#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
  int pid = fork();
  if(pid<0)
  {
    perror("fork error!\n");
    exit(1);
  }
  else if(pid == 0)
  {
    int fd[2];
    if(pipe(fd)!= 0)
    {
      perror("pipe error!\n");
      exit(1);
    }
    if(fork() == 0)
    {
      close(fd[0]);
      dup2(fd[1],1);
      execlp("ps","ps","aux",NULL);
      close(fd[1]);
    }
    close(fd[1]);
    dup2(fd[0],0);
    execlp("grep","grep","pipe",NULL);
    close(fd[0]);
  }
  wait(NULL);
  return 0;
}
