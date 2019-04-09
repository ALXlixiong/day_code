#include<iostream>
using namespace std;
#include <set>
#include <vector>
//int main()
//{
//  vector<int> v{2,4,1,0,8,5,9,7};
//  set<int> s(v.begin(),v.end());
//  for(auto& e: s)
//    cout<<e<<" ";
//  cout<<endl;
//  s.erase(1);
//  s.insert(1);
//  for(auto& e: s)
//    cout<<e<<" ";
//  cout<<endl;
//  return 0;
//}
int main()
{
  vector<int> v{3,2,1,5,4,6,7,3,4,2};
  multiset<int> s;
  s.insert(1);
  for(auto& e: v)
    s.insert(e);
  for(auto& e:s)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
