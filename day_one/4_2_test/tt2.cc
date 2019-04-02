// write your code here cpp
#include<iostream>
using namespace std;
#include<string>
int main()
{
    int num;
    while(cin>>num)
    {
        while(num>=10)
        {
            string tmp = to_string(num);
            num = 0;
            for(size_t i = 0;i<tmp.size();++i)
                num += (tmp[i]-'0');
        }
        cout<<num<<endl;
    }
    return 0;
}
