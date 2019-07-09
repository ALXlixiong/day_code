#include <iostream>
#include <string>

int main()
{
    std::string s = "";
    std::string t = "";
    while(std::cin>>s>>t)
    {
        int count = 0;
        while(1)
        {
            size_t pos = s.find(t);
            if(pos == std::string::npos)
                break;
            ++count;
            s = s.substr(pos+t.size());
        }
        std::cout<<count<<std::endl;
    }
    return 0;
}
