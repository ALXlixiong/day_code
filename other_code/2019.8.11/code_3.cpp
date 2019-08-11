#include <iostream>
#include <thread>
#include <atomic>

std::atomic id{0};

void func()
{
    for(int i = 0;i<100000;++i)
        ++id;
}

int main()
{
    //TODO
    std::thread t[10];
    for(int i = 0;i<10;++i)
        t[i](func);
    for(int i =0;i<10;++i)
        t[i].join();
    std::cout<<"end...\n";
    return 0;
}
