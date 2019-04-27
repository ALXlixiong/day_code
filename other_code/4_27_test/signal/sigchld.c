#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<wait.h>
void sigcb(int signo)
{
  wait(NULL);
  printf("child is end\n");
}
int main()
{
  signal(SIGCHLD,sigcb);
  if(fork() == 0)
  {
    sleep(7);
    exit(1);
  }

  while(1)
  {
    printf("hello world\n");
    sleep(1);
  }
  return 0;
}
