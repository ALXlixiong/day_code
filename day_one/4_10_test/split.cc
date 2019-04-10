#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
int main()
{
  string str;
  cin>>str;
  vector<string> ret;
  boost::split(ret,str,boost::is_any_of(","),boost::token_compress_on);
  for(size_t i = 0;i<ret.size();++i)
    cout<<ret[i]<<endl;
  return 0;
}
