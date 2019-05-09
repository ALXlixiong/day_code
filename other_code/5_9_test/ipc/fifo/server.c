#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
  int ret_pipe = open("./fifo", O_RDONLY);
  if(ret_pipe<0)
  {
    perror("open error");
    exit(1);
  }
  char buf[1024] = {0};
  while(1)
  {
    int n = read(ret_pipe,buf,sizeof(buf)-1);
    if(n<0)
    {
      perror("read error");
      exit(1);
    }
    if(write(1,buf,n) != n)
    {
      perror("write error");
      exit(1);
    }
    buf[0] = 0;
  }
  return 0;
}
