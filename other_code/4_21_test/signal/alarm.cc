#include <iostream>
using namespace std;
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int main()
{
  alarm(10);
  while(1)
  {
    sleep(1);
    cout<<"waiting..."<<endl;
  }
  return 0;
}
