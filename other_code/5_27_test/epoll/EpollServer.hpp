#include <iostream>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/epoll.h>

class EpollServer{
    private:
        int _port;
        int _sock;
    public:
        EpollServer(int port)
            :_port(port)
        {}

        ~EpollServer()
        {
            close(_sock);
        }

        void startup()
        {
            _sock = socket(AF_INET,SOCK_STREAM,0);
            if(_sock < 0){
                std::cerr << "socket error\n";
                exit(-1);
            }
            int opt = 1;
            setsockopt(_sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
            struct sockaddr_in server;
            server.sin_family = AF_INET;
            server.sin_addr.s_addr = htonl(INADDR_ANY);
            server.sin_port = htons(_port);
            if(bind(_sock,(struct sockaddr *)&server,sizeof(server))<0){
                std::cerr <<"bind error\n";
                exit(-1);
            }
            if(listen(_sock,5)<0){
                std::cerr << "listen error\n";
                exit(-1);
            }
        }
        bool EpollHandler(int epfd,int sock,int op,uint32_t event){
            if(event == 0){
                epoll_ctl(epfd,op,sock,nullptr);
                return true;
            }
            struct epoll_event ev;
            ev.events = event;
            ev.data.fd = sock;
            if(epoll_ctl(epfd,op,sock,&ev)<0){
                std::cerr<<"epoll_ctl error\n";
                return false;
            }
            return true;
        }
        void EpollServerRun()
        {
            int epfd = epoll_create(300);
            if(epfd < 0){
                std::cerr<<"epoll_create error\n";
            }
            if(!EpollHandler(epfd,_sock,EPOLL_CTL_ADD,EPOLLIN)){
                std::cerr<<"listen sock add epoll error\n";
                exit(-1);
            }
            while(1)
            {
                struct epoll_event ev[256];
                int ret = epoll_wait(epfd,ev,256,1000);
                switch(ret)
                {
                    case 0:
                        std::cout << "time out...\n";
                        continue;
                    case -1:
                        std::cerr << "epoll_wait error\n";
                        continue;
                    default:
                        EpollInfo(epfd,ev,ret);
                        break;
                }
            }
        }
        void EpollInfo(int epfd,struct epoll_event ev[],int num)
        {
            for(int i = 0;i<num;++i)
            {
                if(ev[i].events & EPOLLIN)
                {
                    if(ev[i].data.fd == _sock)
                    {
                        //连接
                        struct sockaddr_in client;
                        socklen_t len = sizeof(client);
                        int client_sock = accept(_sock,(struct sockaddr *)&client,&len);
                        if(client_sock < 0){
                            std::cout<<"accept error\n";
                            continue;
                        }
                        EpollHandler(epfd,client_sock,EPOLL_CTL_ADD,EPOLLIN);
                    }
                    else
                    {
                        //read
                        char buff[10240];
                        ssize_t size = read(ev[i].data.fd,buff,sizeof(buff)-1);
                        if(size == 0){
                            std::cout<<"client quit\n";
                            EpollHandler(epfd,ev[i].data.fd,EPOLL_CTL_DEL,0);
                            close(ev[i].data.fd);
                            continue;
                        }
                        else if(size <0){
                            std::cerr<<"server read error"<<std::endl;
                            continue;
                        }
                        else{
                            buff[size] = 0;
                            std::cout<<"--------------\n";
                            std::cout<<buff<<std::endl;
                            std::cout<<"--------------\n";
                            EpollHandler(epfd,ev[i].data.fd,EPOLL_CTL_MOD,EPOLLOUT);
                        }
                    }
                }
                else
                {
                    //write
                    std::string html = "HTTP/1.1 OK 200\r\n\r\n<html><h1>hello epoll</h1></html>";
                    write(ev[i].data.fd,html.c_str(),html.size());
                    EpollHandler(epfd,ev[i].data.fd,EPOLL_CTL_MOD,EPOLLIN);
                }
            }
        }
};
