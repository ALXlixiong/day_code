#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
class Select
{
    private:
        int _port;
        int _listen_sock;
        int *_array;
        int _size;//_array中合法的文件描述符个数
        int _cap;
    public:
        Select(int port)
            :_port(port)
             ,_size(0)
             ,_cap(sizeof(fd_set)*8)
        {
            _array = new int[_cap];
            for(int i = 0;i<_cap;++i){
                _array[i] = -1;//大于0的是合法文件描述符，所以给为-1；
            }
        }
        ~Select()
        {
            close(_listen_sock);
        }
        void StartUp()
        {
            _listen_sock = socket(AF_INET,SOCK_STREAM,0);
            if(_listen_sock < 0){
                std::cerr<<"socket error\n";
                exit(-1);
            }

            //解决time_wait
            int opt = 1;
            setsockopt(_listen_sock,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));

            struct sockaddr_in server;
            server.sin_family = AF_INET;
            server.sin_addr.s_addr = htonl(INADDR_ANY);
            server.sin_port = htons(_port);

            if(bind(_listen_sock,(struct sockaddr*)&server,sizeof(server))<0){
                std::cerr<<"bind error\n";
                exit(-1);
            }

            if(listen(_listen_sock,5)<0){
                std::cerr<<"listen error\n";
                exit(-1);
            }
        }
        bool Add_array(int fd)
        {
            if(_size == _cap)
                return false;
            _array[_size++] = fd;
            return true;
        }
        int Add_rfds(fd_set &rfds)
        {
            int maxfd = _array[0];
            for(int i = 0;i<_size;++i)
            {
                FD_SET(_array[i],&rfds);
                if(_array[i]>maxfd){
                    maxfd = _array[i];
                }
            }
            return maxfd;
        }
        void Del_array(int index)
        {
            _array[index] = _array[--_size];
            _array[_size] = -1;
        }
        void Run()
        {
            Add_array(_listen_sock);
            while(1){
                //select之后时间和读集合都被清空，所以应该写在循环之内
                fd_set rfds;
                FD_ZERO(&rfds);
                int maxfd = Add_rfds(rfds);
                struct timeval timeout = {2,0};
                switch(select(maxfd+1,&rfds,nullptr,nullptr,&timeout))
                {
                    case -1:
                        std::cerr<<"seelct error\n";
                        exit(-1);
                    case 0:
                        std::cout<<"time out\n";
                    default:
                        {
                            for(int i = 0;i<_size;++i)
                            {
                                if(i == 0 && FD_ISSET(_array[i],&rfds))
                                {
                                    struct sockaddr_in client;
                                    socklen_t len = sizeof(client);
                                    int sock = accept(_array[0],(struct sockaddr*)&client,&len);
                                    if(sock<0){
                                        std::cerr<<"accept error\n";
                                        continue;
                                    }
                                    if(!Add_array(sock)){
                                        std::cout<<"select full\n";
                                        close(sock);
                                        continue;
                                    }
                                }
                                else if(FD_ISSET(_array[i],&rfds))
                                {
                                    char buff[10240];
                                    int ret = read(_array[i],buff,sizeof(buff)-1);
                                    if(ret > 0){
                                        buff[ret] = '\0';
                                        std::cout<<"client>>"<<buff<<std::endl;
                                        std::string html = "HTTP/1.1 200 OK\r\n\r\n<html><title>hello select</title></html>";
                                        write(_array[i],html.c_str(),html.size());
                                        //Del_array(i);
                                        //close(_array[i]);
                                    }
                                    else if(ret == 0){
                                        std::cout<<"client quit\n";
                                        close(_array[i]);
                                        Del_array(i);
                                    }
                                    else{
                                        std::cerr<<"read error\n";
                                        close(_array[i]);
                                        Del_array(i);
                                    }
                                }
                            }
                        }
                }
            }
        }
};
