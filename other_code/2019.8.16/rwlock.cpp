#include <iostream>
#include <pthread.h>
#include <unistd.h>
int i = 1;
pthread_rwlock_t rwlock;
void *read_route(void *arg)
{
    while(i)
    {
        pthread_rwlock_rdlock(&rwlock);
        std::cout<<"read: "<<i<<std::endl;
        sleep(1);
        pthread_rwlock_unlock(&rwlock);
    }
    return nullptr;
}

void *write_route(void *arg)
{
    while(i)
    {
        pthread_rwlock_wrlock(&rwlock);
        ++i;
        std::cout<<"write: "<<i<<std::endl;
        sleep(1);
        pthread_rwlock_unlock(&rwlock);
    }
    return nullptr;
}

int main()
{
    pthread_rwlock_init(&rwlock,nullptr);
    pthread_t write[2];

    for(int i = 0;i<2;++i)
        pthread_create(&write[i],nullptr,write_route,nullptr);
    pthread_t read[4];

    for(int i = 0;i<4;++i)
        pthread_create(&read[i],nullptr,read_route,nullptr);


    for(int i = 0;i<4;++i)
        pthread_join(read[i],nullptr);

    for(int i= 0;i<2;++i)
        pthread_join(write[i],nullptr);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
