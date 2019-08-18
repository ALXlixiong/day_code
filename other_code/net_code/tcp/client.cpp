#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>

class Client
{
    private:
        int sock_;
        int port_;
        std::string ip_;
    public:
        Client(int port,std::string ip):port_(port),ip_(ip)
    {}

        void ClientInit()
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

                if((connect(sock_,(struct sockaddr*)&server,sizeof(server)))<0)
                    throw "connect error";
            }
            catch(...)
            {
                throw;
            }
        }

        void ClientRun()
        {
            std::cout<<"connect success\n";
            char buf[1024];
            for(;;)
            {
                std::cout<<"client say>>";
                fflush(stdin);
                memset(buf,'\0',sizeof(buf));
                std::cin>>buf;
                write(sock_,buf,strlen(buf));
                ssize_t size = read(sock_,buf,sizeof(buf)-1);
                buf[size] = '\0';
                std::cout<<"server say>>"<<buf<<"\n";
            }
        }

        ~Client()
        {
            close(sock_);
        }
};

int main(int argc,char *argv[])
{
    try
    {
        Client c(atoi(argv[2]),argv[1]);
        c.ClientInit();
        c.ClientRun();
    }
    catch(const char *str)
    {
        std::cerr<<str<<"\n";
        return -1;
    }
    return 0;
}
