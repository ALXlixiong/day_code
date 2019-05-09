#include "comm.h"
int main()
{
  int shmid = CreateShm();
  char *addr = (char *)shmat(shmid,NULL,0);
  if(addr == (char *)-1)
  {
    perror("shmat error");
    exit(1);
  }
  char buf[1024] = {0};
  int n = 0;
  while((n = read(0,buf,sizeof(buf)-1))>0)
  {
    memcpy(addr,buf,n);
    memset(buf,0,n);
    //sleep(1);
    //memset(addr,0,n);
  }
  return 0;
}
