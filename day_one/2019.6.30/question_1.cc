#include <iostream>
#include <string>
#include <vector>

class Solution
{
    public:
        static void GetFunc(int n)
        {
            if(n <= 3)
            {
                std::string ret = "000";
                ret += std::to_string(n);
                std::cout<<ret;
                return;
            }
            int f1 = 1;
            int f2 = 2;
            int f3 = 0;
            int index = 3;
            while(index<=n)
            {
                f3 = f1+f2;
                f1 = f2;
                f2 = f3;
                ++index;
            }
            if(f3<10)
            {
                std::string ret = "000";
                ret += std::to_string(f3);
                std::cout<<ret;
                return;
            }
            else if(f3<100)
            {
                std::string ret = "00";
                ret += std::to_string(f3);
                std::cout<<ret;
                return;
            }
            else if(f3<1000)
            {
                std::string ret = "0";
                ret += std::to_string(f3);
                std::cout<<ret;
                return;
            }
            else
            {
                std::string ret = "";
                std::string tmp = std::to_string(f3);
                ret += tmp[tmp.size()-4];
                ret += tmp[tmp.size()-3];
                ret += tmp[tmp.size()-2];
                ret += tmp[tmp.size()-1];
                std::cout<<ret;
                return;
            }
        }
};

int main()
{
    int n = 0;
    while(std::cin>>n)
    {
        std::vector<int> v(n,0);
        for(int i = 0;i<n;++i)
            std::cin>>v[i];
        for(int i = 0;i<n;++i)
            Solution::GetFunc(v[i]);
        std::cout<<std::endl;
    }
    return 0;
}
