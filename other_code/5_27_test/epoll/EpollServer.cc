#include "EpollServer.hpp"
int main(int argc,char *argv[])
{
    if(argc != 2){
        std::cout<<"Usage:"<<argv[0]<<" "<<"port"<<std::endl;
        return 0;
    }
    EpollServer s(atoi(argv[1]));
    s.startup();
    s.EpollServerRun();
    return 0;
}
