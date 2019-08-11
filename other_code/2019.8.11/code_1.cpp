#include <iostream>
#include <thread>
#include <unistd.h>
void route(int arg)
{
    sleep(2);
    std::cout<<arg<<std::endl;
    sleep(2);
}

int main()
{
    std::thread t1(route,1);
    //t1.join();
    t1.detach();
    std::cout<<"huihe\n";
    return 0;
}
