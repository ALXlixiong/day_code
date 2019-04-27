//signal 信号处理方式

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigcb(int signo)
{
  if(signo == SIGQUIT)
  {
    printf("signo = 19\n");
  }
  else 
    printf("signo = 1\n");
}

int main()
{
  signal(SIGINT,sigcb);//忽略ctrl+c发出的SIGINT信号
  signal(SIGQUIT,sigcb);
  while(1)
  {
    printf("hello world\n");
    sleep(1);
  }
  return 0;
}
