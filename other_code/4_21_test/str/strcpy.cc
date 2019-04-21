#include<iostream>
using namespace std;
#include<assert.h>
#include<string.h>
char *my_strcpy(char *dest,const char *scr)
{
  assert(dest);
  assert(scr);
  char *ret = dest;
  while(*(dest++) = *(scr++))
    ;
  return ret;
}

int main()
{
  char *scr = "hello world";
  char *dest = new char[strlen(scr)+1];
  cout<<my_strcpy(dest,scr)<<endl;
  return 0;
}
