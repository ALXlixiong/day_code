//线程终止
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_fun(void *arg)
{
  char *tmp = (char *)arg;
  while(1)
  {
    printf(tmp);
    //return NULL;
    //exit(0);
    //pthread_exit(NULL);
    sleep(1);
  }
  return NULL;
}

int main()
{
  pthread_t tid;
  if(pthread_create(&tid,NULL,thread_fun,"hello thread\n"))
  {
    perror("pthread_create");
    return -1;
  }
  pthread_exit(NULL);
  //pthread_cancel(tid);
  while(1)
  {
    printf("hello\n");
    sleep(1);
  }
  return 0;
}
