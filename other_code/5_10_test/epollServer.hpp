#include <iostream>
#include <sys/epoll.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
class epollServer
{
    private:
        int _sock;
        int _port;
    public:
        epollServer(int port):_port(port)
    {}
         void epollServerInit()
        {
            //创建sock
            _sock = socket(AF_INET,SOCK_STREAM,0);
            if(_sock < 0){
                std::cerr << "socket error" << std::endl;
                return;
            }
            //bind
            struct sockaddr_in local;
            local.sin_family = AF_INET;
            local.sin_addr.s_addr = htonl(INADDR_ANY);
            local.sin_port = htons(_port);
            if(bind(_sock,(struct sockaddr*)&local,sizeof(struct sockaddr_in))<0){
                std::cerr << "bind error" << std::endl;
                close(_sock);
                return;
            }
            //listen
            int ret = listen(_sock,5);
            if(ret < 0){
                std::cerr << "listen error" << std::endl;
                close(_sock);
                return;
            }

            Run();
        }
         void Run()
        {
            for(;;){
                struct sockaddr_in client;
                socklen_t len;
                int fd = accept(_sock,(struct sockaddr*)&client,&len);
                if(fd < 0){
                    std::cerr << "accept error" << std::endl;
                    close(_sock);
                    return;
                }
                std::cout << "get a connect..." << std::endl;
                char buf[10240];
                while(1){
                    ssize_t sz = read(fd,buf,sizeof(buf)-1);
                    if(sz<0){
                        std::cerr << "read error" << std::endl;
                        close(fd);
                        break;
                    }
                    else if(sz >0){
                        buf[sz] = 0;
                        std::cout << buf << std::endl;
                        std::string req = "HTTP/1.0 200 OK\r\n\r\n<html><h1>hello world</h1></html>\r\n";
                        write(fd,req.c_str(),req.size());
                    }
                    else{
                        std::cout << "client quit..." << std::endl;
                        close(fd);
                    }
                }
            }
        }
};
