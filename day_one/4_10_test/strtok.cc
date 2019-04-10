#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
  char str[] = "hello world,c++";
  char *p = strtok(str," ,");
  while(p)
  {
    cout<<p<<endl;
    p = strtok(nullptr," ,");
  }
  return 0;
}
