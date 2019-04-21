#include<iostream>
using namespace std;
#include<assert.h>
#include<string.h>

char *my_strstr(const char*str1,const char*str2)
{
  if(str2 == nullptr)
    return nullptr;
  assert(str1);
  char *cur = (char*)str1;
  while(*str1)
  {
    cur = (char*)str1;
    while(*cur && *str2 && (*cur == *str2))
    {
      ++cur;
      ++str2;
    }
    if(*str2 == '\0')
      return (char *)str1;
    if(*cur == '\0' && *str2 != '\0')
      return nullptr;
    ++str1;
  }
  return nullptr;
}
int main()
{
  char *str1 = "hello world";
  char *str2 = "wor";
  cout<<my_strstr(str1,str2)<<endl;
  int **arr[3][4];
  cout<<sizeof(arr)<<endl; 
  return 0;
}
