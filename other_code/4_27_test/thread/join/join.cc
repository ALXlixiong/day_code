//线程等待
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *pthread_fun(void *arg)
{
  pthread_exit("hello bit!!!\n");
  return NULL; 
  //pthread_detach(pthread_self());
  char *str = (char *)arg;
  printf(str);
  return (void *)str;
}

int main()
{
  pthread_t tid;
  if(pthread_create(&tid,NULL,pthread_fun,"hello pthread\n"))
  {
    perror("pthread_create");
    return -1;
  }
  //sleep(3);
  //char *retval;
  //pthread_join(tid,(void **)&retval);
  //printf("%s\n",retval);
  while(1);
  return 0;
}

