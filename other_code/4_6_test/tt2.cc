//不使用四则运算法则，实现两个数之和
#include <iostream>
using namespace std;
int main()
{
  int num1 = 0;
  int num2 = 0;
  while(cin>>num1>>num2)
  {
    int add = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    while(1)
    {
      tmp1 = num1^num2;
      tmp2 = (num1&num2)<<1;
      if(tmp2 == 0)
      {
        add = tmp1;
        break;
      }
      num1 = tmp1;
      num2 = tmp2;
    }
    cout<<add<<endl;
  }
  return 0;
}
