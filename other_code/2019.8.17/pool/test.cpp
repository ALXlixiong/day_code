#include "ThreadPool.hpp"
#include <unistd.h>

void *func(int arg)
{
    sleep(3);
}

int main()
{
    ThreadPool<int> pool(20);
    pool.ThreadPoolInit();
    for(int i = 0;i<20;++i){
        Task<int> t(func,i);
        pool.PushQueue(t);
    }

    std::cout<<"---------end-------------\n";
    while(1);
    return 0;
}
