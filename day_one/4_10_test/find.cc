#include <iostream>
using namespace std;
#include <string>
#include <vector>
int main()
{
  string str;
  getline(cin,str);
  string tmp = str;
  vector<string> ret;
  size_t pos = str.find(",");
  while(pos != string::npos)
  {
    ret.push_back(str.substr(0,pos));
    str = str.substr(pos+1);
    pos = str.find(",");
  }
  ret.push_back(tmp.substr(tmp.rfind(',')+1));
  for(size_t i = 0;i<ret.size();++i)
    cout<<ret[i]<<endl;
  return 0;
}
