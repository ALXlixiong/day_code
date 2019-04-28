//演示条件变量
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int g_basket = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;
void *pthread_fun1(void *arg)
{
  char *str = (char *)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    if(g_basket == 0)
    {
      pthread_cond_wait(&cond,&mutex);
    }
    printf(str);
    g_basket = 0;
    pthread_mutex_unlock(&mutex);
  }
  pthread_detach(pthread_self());
  return NULL;
}

void *pthread_fun2(void *arg)
{
  char *str = (char *)arg;
  while(1)
  {
    if(g_basket == 0)
    {
      pthread_mutex_lock(&mutex);
      usleep(1000);
      printf(str);
      g_basket = 1;
      pthread_cond_signal(&cond);
      pthread_mutex_unlock(&mutex);
    } 
  }
  pthread_detach(pthread_self());
  return NULL;
}

int main()
{
  pthread_t tid1,tid2;
  pthread_cond_init(&cond,NULL);
  pthread_mutex_init(&mutex,NULL);
  if(pthread_create(&tid1,NULL,pthread_fun1,"buy tid  1\n") != 0)
  {
    printf("pthread_create error!\n");
    return -1;
  }

  if(pthread_create(&tid2,NULL,pthread_fun2,"sale tid  2\n") != 0)
  {
    printf("pthread_create error!\n");
    return -1;
  }
  while(1);
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}
