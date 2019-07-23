#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool cmp(const std::string &left,const std::string &right)
{
    return left<right;
}

int main()
{
    int line = 0;
    while(std::cin>>line)
    {
        std::vector<std::string> v(line,"");
        for(int i = 0;i<line;++i)
            std::cin>>v[i];

        std::vector<std::string> tmp;
        for(int i = 0;i<line;++i)
        {
            bool flag = false;
            for(int j = 0;j<line;++j)
            {
                if(i != j)
                {
                    if(v[j].find(v[i]) != std::string::npos)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag)
            {
                tmp.push_back(v[i]);
            }
        }
        sort(tmp.begin(),tmp.end(),cmp);
        for(int i = 0;i<tmp.size();++i)
        {
            std::cout<<"mkdir -p "<<tmp[i]<<std::endl;
        }
        std::cout<<"\n";
    }
    return 0;
}
