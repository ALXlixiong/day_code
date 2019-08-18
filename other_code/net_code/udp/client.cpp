#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
class Client
{
    private:
        int sock_;
        int port_;
        std::string ip_;
    public:
        Client( int port,std::string ip)
            :port_(port)
            ,ip_(ip)
    {}

        void ClientInit()
        {
            try
            {
                sock_ = socket(AF_INET,SOCK_DGRAM,0);
                if(sock_ < 0)
                    throw "socket error";
            }
            catch(...)
            {
                throw;
            }
        }

        void ClientRun()
        {
            char buf[1024];
            struct sockaddr_in server;
            server.sin_family = AF_INET;
            server.sin_port = htons(port_);
            server.sin_addr.s_addr = inet_addr(ip_.c_str());
            struct sockaddr_in info;
            for(;;)
            {
                socklen_t len =sizeof(info);
                read(0,buf,sizeof(buf)-1);
                sendto(sock_,buf,strlen(buf),0,(struct sockaddr*)&server,len);
                ssize_t size = recvfrom(sock_,buf,sizeof(buf)-1,0,(struct sockaddr*)&info,&len);
                if(size <= 0)
                {
                    perror("recvfrom");
                    continue;
                }
                else if(size>0)
                {
                    buf[size] = '\0';
                    std::cout<<ntohs(info.sin_port)<<" "<<inet_ntoa(info.sin_addr)<<">>"<<buf<<std::endl;
                }
            }
        }

        ~Client()
        {
            close(sock_);
        }
};

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        std::cerr<<"Usage:"<<argv[0]<<" "<<"ip"<<" "<<"port"<<std::endl;
        return -1;
    }

    try
    {
        Client c(atoi(argv[2]),argv[1]);
        c.ClientInit();
        c.ClientRun();
    }
    catch(const char *error)
    {
        std::cerr<<"error:"<<error<<"\n";
        return-1;
    }
    return 0;
}
