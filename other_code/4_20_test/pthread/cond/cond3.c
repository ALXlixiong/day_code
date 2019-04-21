#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int g_tmp = 0;
pthread_cond_t sale;
pthread_cond_t eat;
pthread_mutex_t mutex;
void *saleFun(void *arg)
{
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(g_tmp == 1)
      pthread_cond_wait(&sale,&mutex);
    g_tmp = 1;
    printf("生产一个苹果\n");
    pthread_cond_signal(&eat);  //唤醒消费者
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void *eatFun(void *arg)
{
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(g_tmp == 0)
      pthread_cond_wait(&eat,&mutex);//原子操作
    printf("eat a apple!!\n");
    g_tmp = 0;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&sale);//唤醒生产者
  }
  return NULL;
}
int main()
{
  pthread_t tid[2];
  int ret = 0;
  pthread_cond_init(&sale,NULL);
  pthread_cond_init(&eat,NULL);
  pthread_mutex_init(&mutex,NULL);
  ret = pthread_create(&tid[0],NULL,saleFun,NULL);
  if(ret != 0)
  {
    perror("create error!");
    exit(1);
  }
  ret = pthread_create(&tid[1],NULL,eatFun,NULL);
  if(ret != 0)
  {
    perror("create error!");
    exit(1);
  }
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  pthread_cond_destroy(&sale);
  pthread_cond_destroy(&eat);
  pthread_mutex_destroy(&mutex);
  return 0;
}
