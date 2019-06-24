#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>

class Client
{
    private:
        int port_;
        int sock_;
        std::string ip_;
    public:
        Client(int port,std::string ip):port_(port),ip_(ip)
    {}

        void UdpInit()
        {
            sock_ = socket(AF_INET,SOCK_DGRAM,0);
            if(sock_ < 0){
                std::cerr<<"socket error\n";
                exit(-1);
            }

        }

        void Run()
        {
            struct sockaddr_in client;
            client.sin_family = AF_INET;
            client.sin_port = htons(port_);
            client.sin_addr.s_addr = inet_addr(ip_.c_str());

            while(1)
            {
                char buf[1024];
                int size = read(0,buf,sizeof(buf)-1);
                buf[size] = '\0';

                sendto(sock_,buf,strlen(buf),0,(struct sockaddr *)&client,sizeof(client));
                size_t sz = recvfrom(sock_,buf,sizeof(buf)-1,0,nullptr,nullptr);
                buf[sz] = 0;
                std::cout<<"server#"<<buf<<std::endl;
            }
        }
        ~Client()
        {
            close(sock_);
        }
};

void Usage(std::string arg){
    arg += " ip port\n";
    std::cout<<arg;
}
int main(int argc,char *argv[])
{
    if(argc != 3){
        Usage(argv[0]);
        exit(0);
    }
    Client c(atoi(argv[2]),argv[1]);
    c.UdpInit();
    c.Run();
    return 0;
}
