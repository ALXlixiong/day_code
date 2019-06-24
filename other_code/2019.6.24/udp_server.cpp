#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdlib>
#include <cstring>
#include <strings.h>
#include <arpa/inet.h>
class Server
{
    private:
        int port_;
        std::string ip_;
        int sock_;
    public:
        Server(int port,std::string ip):port_(port),ip_(ip)
    {}

        void UdpInit()
        {
            sock_ = socket(AF_INET,SOCK_DGRAM,0);
            if(sock_ < 0){
                std::cerr<<"socket error\n";
                exit(-1);
            }

            struct sockaddr_in server;
            bzero((struct sockaddr *)&server,sizeof(server));

            server.sin_family = AF_INET;
            server.sin_port = htons(port_);
            server.sin_addr.s_addr = inet_addr(ip_.c_str());

            if(bind(sock_,(struct sockaddr *)&server,sizeof(server))<0){
                std::cerr<<"bind error\n";
                exit(-1);
            }
        }

        void Run()
        {
            char buf[1024];
            while(1)
            {
                struct sockaddr_in client;
                socklen_t len = sizeof(client);
                ssize_t size = recvfrom(sock_,buf,sizeof(buf)-1,0,(struct sockaddr *)&client,&len);
                if(size<0){
                    std::cerr<<"recv error\n";
                    continue;
                }
                else if(size == 0){
                    std::cout<<"client quit...\n";
                    break;
                }
                else{
                    buf[size] = '\0';
                    std::cout<<buf<<std::endl;

                    memset(buf,0,sizeof(buf));
                    std::cin>>buf;
                    sendto(sock_,buf,sizeof(buf),0,(struct sockaddr*)&client,len);
                }
            }
        }
};

void Usage(std::string arg){
    arg += " ip port";
    std::cout<<arg<<std::endl;
}

int main(int argc,char *argv[])
{
    if(argc != 3){
        Usage(argv[0]);
        exit(0);
    }
    Server s(atoi(argv[2]),argv[1]);
    s.UdpInit();
    s.Run();
    return 0;
}
