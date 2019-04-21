#include<iostream>
using namespace std;

int my_strlen(const char* p)
{
  int count = 0;
  while(*p)
  {
    ++count;
    ++p;
  }
  return count;
}
int my_strlen2(const char *str)
{
  if(*str == '\0')
    return 0;
  else 
    return 1+ my_strlen2(str+1);
}
int main()
{
  char *str = "hello world!";
  cout<<my_strlen2(str)<<endl;
}
