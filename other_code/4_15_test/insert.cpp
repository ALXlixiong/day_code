#include<iostream>
using namespace std;
#include<vector>

void sort(vector<int> &v)
{
  size_t i = 0;
  for(i = 1;i<v.size();++i)
  {
    int key = v[i];
    int end = i-1;
    while(end>=0 && key<v[end])
    {
      v[end+1] = v[end];
      --end;
    }
    v[end+1] = key;
  }
}

int main()
{
  vector<int> v{3,2,6,5,7,0,8,9,1,2};
  sort(v);
  for(vector<int>::iterator it = v.begin();it != v.end();++it)
    cout<<*it<<' ';
  cout<<endl;

  for(auto &e:v)
    cout<<e<<' ';
  cout<<endl;
  return 0;
}
