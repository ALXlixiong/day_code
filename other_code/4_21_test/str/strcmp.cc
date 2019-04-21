#include<iostream>
using namespace std;
#include<assert.h>
int my_strcmp(const char *str1,const char *str2)
{
  assert(str1);
  assert(str2);
  int ret = 0;
  while(!(ret = *(unsigned char *)str1-*(unsigned char *)str2))
  {
    ++str1;
    ++str2;
  }
  if(ret<0)
    return -1;
  else if(ret>0)
    return 1;
  return 0;
}

int main()
{
  char *str1 = "he";
  char *str2 = "hello ";
  cout<<my_strcmp(str1,str2)<<endl;
  return 0;
}
