#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
#include<assert.h>
void *my_memcpy(void *dst,const void *scr,size_t count)
{
  assert(dst&&scr);
  void *ret = dst;
  if(dst>scr && (char *)dst<(char *)scr + count)
  {
    /*此处不能对dst强转*/dst = (char *)dst + count-1;
    scr = (char *)scr + count-1;
    while(count--)
    {
      *(char *)dst = *(char *)scr;
      dst = (char *)dst-1;
      scr = (char *)scr-1;
    }
    return ret;
  }
  while(count--)
  {
    *(char *)dst = *(char *)scr;
    dst = (char *)dst + 1;
    scr = (char *)scr + 1;
  }
  return ret;
}
int main()
{
  char dst[] = "abcdef";
  char *ret = (char *)my_memcpy(dst+1,dst,strlen(dst));
  cout<<ret<<endl;
  return 0;
}
