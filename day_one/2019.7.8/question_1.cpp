#include <iostream>
#include <math.h>

int GetFunc(int num)
{
    for(int i = 2;i<=sqrt(num);++i)
    {
        if(num%i == 0)
            return i;
    }
    return 0;
}

int main()
{
    int num = 0; 
    while(std::cin>>num)
    {
        int tmp = 1;
        std::string ret = std::to_string(num);
        ret += "=";

        while(1)
        {
            int tmp = GetFunc(num);
            if(tmp == 0)
            {
                ret += std::to_string(num);
                std::cout<<ret<<std::endl;
                break;
            }
            ret += std::to_string(tmp);
            ret += "*";
            num /= tmp;
        }
    }
    return 0;
}
