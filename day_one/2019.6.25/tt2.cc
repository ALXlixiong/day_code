#include <iostream>
using namespace std;
#include <string>
int main()
{
    string str1 = "";
    string str2 = "";
    getline(cin,str1);
    getline(cin,str2);
    int arr[256] = {0};
    for(int i = 0;i<str2.size();++i)
        arr[str2[i]]++;
    
    string ret = "";
    for(int i = 0;i<str1.size();++i)
    {
        if(arr[str1[i]] == 0)
            ret += str1[i];
    }
    cout<<ret<<endl;
    return 0;
}
