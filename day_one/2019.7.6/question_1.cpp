#include <iostream>

int a = 0;

int main()
{
    int a = 0;
    a = 10;
    ::a = 11;
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"::a = "<<::a<<std::endl;
    return 0;
}
