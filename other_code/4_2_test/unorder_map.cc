#include<iostream>
using namespace std;
#include <unordered_map>
#include <vector>
int main()
{
  vector<int> v{3,1,2,4,5,6};
  unordered_map<int,int> m1;
  for(auto& e:v)
    m1.insert(make_pair(e,e+2));
  cout<<m1.size()<<endl;
  cout<<m1[7]<<endl;
  m1[7] = 10;
  auto ret = m1.find(7);
  if(ret->second)
  {
    cout<<"zhao dao la "<<ret->first<<endl;
  }
  else 
    cout<<"mei zhaodao"<<endl;
  for(auto& e: m1)
    cout<<e.first<<"->"<<e.second<<endl;
  return 0;
}
