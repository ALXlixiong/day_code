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
class Server
{
    private:
        int sock_;
        int port_;
        std::string ip_;
    public:
        Server( int port,std::string ip)
            :port_(port)
            ,ip_(ip)
    {}

        void ServerInit()
        {
            try
            {
                sock_ = socket(AF_INET,SOCK_DGRAM,0);
                if(sock_ < 0)
                    throw "socket error";

                struct sockaddr_in local;
                local.sin_family = AF_INET;
                local.sin_port = htons(port_);
                local.sin_addr.s_addr = inet_addr(ip_.c_str());
                if(bind(sock_,(struct sockaddr*)&local,sizeof(local))<0)
                    throw "bind error";
            }
            catch(...)
            {
                throw;
            }
        }

        void ServerRun()
        {
            char buf[1024];
            struct sockaddr_in client;
            for(;;)
            {
                socklen_t len =sizeof(client);
                ssize_t size =  recvfrom(sock_,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
                if(size <= 0)
                {
                    perror("recvfrom");
                    continue;
                }
                else if(size>0)
                {
                    buf[size] = '\0';
                    std::cout<<ntohs(client.sin_port)<<" "<<inet_ntoa(client.sin_addr)<<">>"<<buf<<std::endl;
                    sendto(sock_,buf,strlen(buf),0,(struct sockaddr*)&client,len);
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
    if(argc != 3)
    {
        std::cerr<<"Usage:"<<argv[0]<<" "<<"ip"<<" "<<"port"<<std::endl;
        return -1;
    }

    try
    {
        Server s(atoi(argv[2]),argv[1]);
        s.ServerInit();
        s.ServerRun();
    }
    catch(const char *error)
    {
        std::cerr<<"error:"<<error<<"\n";
        return-1;
    }
    return 0;
}
