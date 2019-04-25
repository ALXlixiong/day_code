#include <iostream>
using namespace std;
#include <unistd.h>
int main()
{
  for(int i = 0;i<2;++i)
  {
    fork();
    printf("-\n");
  }
  return 0;
}
