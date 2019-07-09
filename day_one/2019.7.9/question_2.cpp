#include <iostream>

int main()
{
    int from = 0;
    int to = 0;
    long long arr[80] = {0};
    int f1 = 1;
    int f2 = 1;
    arr[0] = f1;
    arr[1] = f2;
    int i = 2;
    while(i<80)
    {
        int f3 = f1 + f2;
        arr[i] = f3;
        f1 = f2;
        f2 = f3;
        ++i;
    }
    std::cout<<"----\n";
    while(std::cin>>from>>to)
    {
        long long sum = 0;
        for(int i = from-1;i<=to-1;++i)
            sum += arr[i];
        std::cout<<sum<<std::endl;
    }
    return 0;
}
