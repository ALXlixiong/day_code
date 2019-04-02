#include<iostream>
using namespace std;
#include<stdio.h>
#include<vector>
long GetFibonaci(int num)
{
  if(num == 1)
    return 1;
  if(num == 2)
    return 2;
  int f1 = 1;
  int f2 = 2;
  int n = 3;
  long f3 = 0;
  while(n<=num)
  {
    f3 = f1+ f2;
    f1 = f2;
    f2 = f3;
    ++n;
  }
  if(f3>=10000)
    f3 = f3%10000;
  return f3;
}
int main()
{
  int count = 0;
  while(cin>>count)
  {
    vector<int> v;
    v.resize(count);
    for(int i = 0;i<count;++i)
    {
      cin>>v[i];
      int ret = GetFibonaci(v[i]);
      printf("%04d",ret);
    }
    cout<<endl;
  }
}
