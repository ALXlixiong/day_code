#include <iostream>

void Check()
{
    int a =0x12345678;
    char tmp = *(char *)&a;
    if(tmp == 0x12)
        std::cout<<"big endian\n";
    else
        std::cout<<"little endian\n";
}

union u
{
    char a;
    int b;
}un;

int main()
{
    Check();
    un.b = 0x12345678;
    if(un.a == 0x12)
        std::cout<<"big endian\n";
    else 
        std::cout<<"little endian\n";
    return 0;
}
