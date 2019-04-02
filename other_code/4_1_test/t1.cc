#include<iostream>
using namespace std;
#include<vector>
int GetBig(int left,int right)
{
  int ret = 0;
  while(left%right != 0)
  {
    ret = left%right;
    left = right;
    right = ret;
  }
  return right;
}
int main()
{
  int num = 0;
  int power = 0;
  while(cin>>num>>power)
  {
    vector<int> v(num);
    for(int i = 0;i<num;++i)
      cin>>v[i];
    for(int i = 0;i<num;++i)
    {
      if(power>=v[i])
        power += v[i];
      else 
      {
        int tmp = GetBig(v[i],power);
        power += tmp;
      }
    }
    cout<<power<<endl;
  }
  return 0;
}
