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
  while(1)
  {
    printf("%s\n",addr);
    sleep(1); 
    //memset(addr,0,strlen(addr));
  }
  return 0;
}

