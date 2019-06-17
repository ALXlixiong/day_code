#include <iostream>
using namespace std;
#include <string>


void Func(string str)
{
    string tmp = "";
    for(int i = 0;i<str.size();++i)
    {
        if(str[i]>='0' && str[i]<='9')
            tmp += str[i];
    }
    cout<<tmp<<endl;
}

int main()
{
    string str = "";
    while(getline(cin,str))
    {
        Func(str);
    }
    return 0;
}
