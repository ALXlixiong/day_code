#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
    std::string num = "";
    while(std::cin>>num)
    {
        long long ret = 0;
        while(ret == 0 || ret>=10)
        {
            ret = 0;
            for(int i = 0;i<num.size();++i)
                ret += (num[i]-'0');
            num = std::to_string(ret);
        }
        std::cout<<ret<<std::endl;
    }
    return 0;
}
