#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdint.h>
volatile int a = 1;
void sigcb(int signo)
{
  printf("signo:%d\n",signo);
  a = 0;
}
int main()
{
  //uint64_t i = 0;
  signal(SIGINT,sigcb);
  while(a)
  {
    ;
  }
  return 0;
}
