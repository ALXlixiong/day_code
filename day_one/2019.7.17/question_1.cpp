#include <iostream>
#include <string>


int main()
{
    std::string src= "";
    while(std::cin>>src)
    {
        std::string dest = "";
        int i = 0;
        for(i = 0;i<src.size();++i)
        {
            if(src[i] == '_')
                break;
            dest += src[i];
        }
        for(;i<src.size();++i)
        {
            if(src[i] == '_')
            {
                ++i;
                dest += (src[i]-32);
            }
            else
                dest += src[i];
        }
        std::cout<<dest<<std::endl;
    }
    return 0;
}
