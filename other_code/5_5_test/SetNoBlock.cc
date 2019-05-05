#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void SetNoBlock(int fd)
{
  int fl = fcntl(fd,F_GETFL);
  if(fl<0)
  {
    perror("fcntl");
    return;
  }
  fcntl(fd,F_SETFL,fl|O_NONBLOCK);
}
int main()
{
  SetNoBlock(0);
  char buff[1024];
  while(1)
  {
    ssize_t sz = read(0,buff,sizeof(buff)-1);
    if(sz>0){
      buff[sz] = 0;
      std::cout<<buff<<std::endl;
    }
    else 
      std::cout<<"defult..."<<std::endl;
    sleep(2);
  }
  return 0;
}
