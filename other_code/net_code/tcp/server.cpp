#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>

class Server
{
    private:
        int sock_;
        int port_;
        std::string ip_;
    public:
        Server(int port,std::string ip):port_(port),ip_(ip)
    {}

        void ServerInit()
        {
            try
            {
                sock_ = socket(AF_INET,SOCK_STREAM,0);
                if(sock_ < 0)
                    throw "socket error";

                struct sockaddr_in server;
                server.sin_family = AF_INET;
                server.sin_port = htons(port_);
                server.sin_addr.s_addr = inet_addr(ip_.c_str());

                if(bind(sock_,(struct sockaddr*)&server,sizeof(server))<0)
                    throw "bind error";

                if(listen(sock_,5)<0)
                    throw "listen error";
            }
            catch(...)
            {
                throw;
            }
        }

        void ServerRun()
        {
            struct sockaddr_in client;
            for(;;)
            {
                socklen_t len = sizeof(client);
                int client_sock = accept(sock_,(struct sockaddr*)&client,&len);
                if(client_sock < 0)
                {
                    std::cerr<<"accept error\n";
                    continue;
                }
                std::cout<<"get a connect\n";
                std::cout<<"ip:"<<inet_ntoa(client.sin_addr)<<" port:"<<ntohs(client.sin_port)<<std::endl;

                char buf[1024];
                for(;;)
                {
                    ssize_t size = read(client_sock,buf,sizeof(buf)-1);
                    if(size < 0)
                    {
                        std::cerr<<"read error\n";
                        continue;
                    }
                    else if(size == 0)
                    {
                        std::cout<<"client quit...\n";
                        break;
                    }
                    else
                    {
                        buf[size] = '\0';
                        std::cout<<"client say>>"<<buf<<"\n";
                    }
                    std::cout<<"server say>>";
                    memset(buf,'\0',sizeof(buf));
                    std::cin>>buf;
                    write(client_sock,buf,strlen(buf));
                }
            }
        }

        ~Server()
        {
            close(sock_);
        }
};

int main(int argc,char *argv[])
{
    try
    {
        Server s(atoi(argv[2]),argv[1]);
        s.ServerInit();
        s.ServerRun();
    }
    catch(const char *str)
    {
        std::cerr<<str<<"\n";
        return -1;
    }
    return 0;
}
