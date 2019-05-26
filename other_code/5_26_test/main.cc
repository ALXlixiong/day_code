#include "select.hpp"

int main(int argc,char *argv[])
{
    //std::cout<<sizeof(fd_set)<<std::endl;
    //std::cout<<sizeof(fd_set)/sizeof(int)<<std::endl;
    if(argc != 2){
        std::cout<<"Usage:"<<argv[0]<<" "<<"port\n";
        return -1;
    }
    Select s(atoi(argv[1]));
    s.StartUp();
    s.Run();
    return 0;
}
