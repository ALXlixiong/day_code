#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
char *my_strcat(char*str1,const char* str2)
{
  assert(str1);
  assert(str2);
  char *ret = str1;
  while(*str1)
  {
    str1++;//
  }
  while(*str1++ = *str2++)
  {
    ;
  }
  return ret;
}
int main()
{
  char str1[14] = "hello ";
  char *str2 = "world";
  cout<<my_strcat(str1,str2)<<endl;
  return 0;
}
