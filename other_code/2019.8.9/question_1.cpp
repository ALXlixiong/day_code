#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *route(void *arg)
{
    while(1)
    {
        std::cout<<pthread_self()<<std::endl;
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    if(pthread_create(&tid,nullptr,route,nullptr)<0)
    {
        std::cerr<<"pthread error\n";
    }
    pthread_detach(tid);
    while(1)
    {
        std::cout<<tid<<std::endl;
        std::cout<<"---"<<pthread_self()<<std::endl;
        sleep(1);
    }
    return 0;
}
