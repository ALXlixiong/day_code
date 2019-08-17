#include <functional>
#include <iostream>


void Test(std::function<int(int, int)> f)
{
    int ret = f(1, 2);
    std::cout << ret << std::endl;

}

int func(int a, int b)
{
    return a + b;

}

int main()
{
    Test(func);
    return 0;

}
