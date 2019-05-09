//客户端
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
  int ret_pipe = open("./fifo",O_WRONLY);
  if(ret_pipe<0)
  {
    perror("open error");
    exit(1);
  }
  char buf[1024] = {0};
  int n = 0;
  while((n = read(0,buf,sizeof(buf)-1))>0)
  {
    if(write(ret_pipe,buf,n)!= n)
    {
      perror("write error");
      exit(1);
    }
    buf[0] = 0;
  }
  if(n<0)
  {
    perror("read error");
    exit(1);
  }
  close(ret_pipe);
  return 0;
}
