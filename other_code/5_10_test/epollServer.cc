#include "epollServer.hpp"
#include <stdio.h>
#include <stdlib.h>
void Usage(std::string str)
{
    std::cout<<"Usage: "<<str <<"ip "<<"port"<<std::endl;
}

int main(int argc,char* argv[])
{
    //./epollServer 127.0.0.1 8888
    if(argc != 3){
        Usage(argv[0]);
        return 0;
    }
    epollServer server(atoi(argv[2]));
    server.epollServerInit();
    server.Run();
    return 0;
}
