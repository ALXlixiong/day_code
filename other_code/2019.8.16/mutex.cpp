#include <iostream>
#include <pthread.h>
#include <unistd.h>

int g_ticket = 100;
pthread_mutex_t mutex_;
void *route(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex_);
        if(g_ticket>0)
        {
            usleep(1000);
            g_ticket--;
            std::cout<<g_ticket<<std::endl;
            pthread_mutex_unlock(&mutex_);
        }
        else
        {
            pthread_mutex_unlock(&mutex_);//在任何可能退出的地方解锁
            break;
        }
    }
    return nullptr;
}

int main()
{
    pthread_mutex_init(&mutex_,nullptr);
    pthread_t tid[4];
    for(int i = 0;i<4;++i){
        pthread_create(&tid[i],nullptr,route,nullptr);
    }
    for(int i = 0;i<4;++i)
        pthread_join(tid[i],nullptr);
    pthread_mutex_destroy(&mutex_);
    return 0;
}
