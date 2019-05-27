#include <iostream>

int main()
{
    while(1)
    {
        int a = 0;
        std::cin>>a;
        switch(a)
        {
            case 1:
                std::cout<<"1"<<std::endl;
                break;
            case 2:
                std::cout<<"2"<<std::endl;
                continue;
        }
    }
    return 0;
}
