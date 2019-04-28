#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *pthread_fun(void *arg)
{
  while(1)
  {
    printf("arg = %d\n",(int)arg);
    sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t tid;
  int ret = pthread_create(&tid,NULL,pthread_fun,(void *)30);
  if(ret == -1)
  {
    printf("pthread_create error!!\n");
    return -1;
  }
  while(1);
  return 0;
}
