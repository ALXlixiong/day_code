#include <iostream>
#include <vector>
#include <string>

int main()
{
    int num = 0;
    while(std::cin>>num)
    {
        std::vector<std::vector<std::string> > v(num,std::vector<std::string>(2,""));
        for(int i = 0;i<num;++i)
        {
            for(int j = 0;j<2;++j)
            {
                std::cin>>v[i][j];
            }
        }

        int max =0;
        int count = 0;
        int ret = 0;
        for(int i =0;i<num;++i)
        {
            if(v[i][1] == "connect")
            {
                if(count == 0){
                    ++ret;
                    ++count;
                }
                else
                    --count;
            }
            else if(v[i][1] == "disconnect")
            {
                --count;
            }
            max = max>count?max:count;
        }
        std::cout<<ret<<std::endl;
    }
    return 0;
}
