#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int num = 0;
    while(cin>>num)
    {
        int count = 0;
        for(int i = 2;i<=sqrt(num);++i)
        {
            if(num%i == 0)
            {
                while(num%i == 0)
                {
                    num /= i;
                }
                ++count;
            }
        }
        if(num != 1)
            ++count;
        std::cout<<count<<std::endl;
    }
    return 0;
}
