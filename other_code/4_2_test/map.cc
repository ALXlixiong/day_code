#include<iostream>
using namespace std;
#include<map>
#include<string>
//int main()
//{
//  map<int,string> m1{{2,"bbb"},{1,"aaa"},{3,"ccc"}};
//  cout<<m1[1]<<endl;
//  for(map<int,string>::iterator it = m1.begin();it != m1.end();++it)
//    cout<<it->first<<"-->"<<it->second<<endl;
//  auto ret = m1.insert(pair<int,string>(1,"aaa"));
//  if(ret.second)
//    cout<<"bu cun zai"<<endl;
//  else 
//    cout<<"cun zai"<<endl;
//  cout<<m1[4]<<endl;
//  m1[4] = "ddd";
//  cout<<m1[4]<<endl;
//  ret = m1.insert(make_pair(5,"eee"));
//  if(ret.second)
//    cout<<"cheng gnong"<<endl;
//  if(m1.count(6) == 0)
//    cout<<"6 bu cun zai"<<endl;
//  else 
//    cout<<"6 cun zai"<<endl;
//  return 0;
//}
#include<vector>
//int main()
//{
//
//  map<int,int> m1{{1,1},{2,2},{3,3}};
//  for(auto& e: m1)
//    cout<<e.first<<"->"<<e.second<<endl;
//  map<int,int> m2(m1);
//  m2[1] = 4;
//  for(auto& e: m2)
//    cout<<e.first<<"->"<<e.second<<endl;
//  cout<<m2.count(1)<<endl;
//  map<int,int> m3(m1.begin(),m1.end());
//  for(auto& e: m3)
//    cout<<e.first<<"->"<<e.second<<endl;
//  cout<<m1.size()<<endl;
//  return 0;
//}
#include<algorithm>
int main()
{
  vector<int> v{2,4,1,0,8,4,6,3,4,2,1,9,9};
  cout<<v.size()<<endl;
  multimap<int,int> m1;
  for(auto& e:v)
    m1.insert(make_pair(e,e));
  cout<<"m1.size() = "<<m1.size()<<endl;
  for(auto it = m1.begin();it != m1.end();++it)
    cout<<it->first<<" ";
  cout<<endl;
  sort(v.begin(),v.end());
  for(auto& e: v)
    cout<<e<<" ";
  cout<<endl;
}
