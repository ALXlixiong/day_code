//演示售票例子
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>

int g_ticket = 100;
pthread_mutex_t mutex;
void *pthread_fun(void *arg)
{

  while(1)
  {
    pthread_mutex_lock(&mutex);
    if(g_ticket>0)
    {
      usleep(1000);
      printf("thread %d sells a ticket %d\n",(int)arg,g_ticket);
      --g_ticket;
      pthread_mutex_unlock(&mutex);
    }
    else 
    {
      printf("no ticket!!!\n");
      pthread_mutex_unlock(&mutex);
      pthread_exit(NULL);
    }
  }
  return NULL;
}

int main()
{
  pthread_t tid[4];
  int i = 0;
  pthread_mutex_init(&mutex,NULL);
  for(;i<4;i++)
  {
    if(pthread_create(&tid[i],NULL,pthread_fun,(void *)i) != 0)
    {
      printf("pthread_create error!\n");
      return -1;
    }
  }
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  pthread_join(tid[2],NULL);
  pthread_join(tid[3],NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}

