#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>
#define PATHNAME "."
#define PROJ_ID 0X12345678

int CreateShm()
{
  key_t key = ftok(PATHNAME,PROJ_ID);
  if(key == -1)
  {
    perror("ftok eror");
    exit(1);
  }
  int shmid = shmget(key,1024,IPC_CREAT|0644);
  if(shmid<0)
  {
    perror("shmget error");
    exit(1);
  }
  return shmid;
}
