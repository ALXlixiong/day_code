#include <iostream>
#include <vector>


void FindKey(std::vector<int> &v,int &key)
{
  int left = 0;
  int right = v.size();
  while(left<right)
  {
    int mid = left + ((right-left)>>1);
    if(v[mid] == key)
    {
      std::cout<<"找到了 下表是"<<mid<<std::endl;
      return;
    }
    else if(v[mid]>key)
      right = mid;
    else 
      left = mid+1;
  }
  std::cout<<"没有找到"<<std::endl;
}

int main()
{
  std::vector<int> v{0,2,3,5,8,9,10,16,20};
  for(std::vector<int>::iterator it = v.begin();it != v.end();++it)
  {
    FindKey(v,*it);
  }
  return 0;
}
