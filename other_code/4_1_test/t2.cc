#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
  string str;
  while(cin>>str)
  {
    vector<int> v(256);
    for(size_t i = 0;i<str.size();++i)
      v[str[i]]++;
    for(size_t i = 0;i<str.size();++i)
    {
      if(v[str[i]] == 1)
      {
        cout<<str[i]<<endl;
        break;
      }
    }
  }
  return 0;
}
