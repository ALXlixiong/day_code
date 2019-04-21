#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int g_tmp = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;
void *saleFun(void *arg)
{
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(g_tmp == 1)
      pthread_cond_wait(&cond,&mutex);
    g_tmp = 1;
    printf("生产一个苹果\n");
    pthread_cond_signal(&cond);  //唤醒消费者
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void *eatFun(void *arg)
{
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(g_tmp == 0)
      pthread_cond_wait(&cond,&mutex);//原子操作
    printf("eat a apple!! \n");
    g_tmp = 0;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);//唤醒生产者
    //那么有一个问题就是会不会唤醒生产者呢？
    //在多个生产者和消费者可能会出现生产者唤醒生产者，导致陷入死等状态
    //所以我们需要各自一个条件变量（生产者和消费者）。
    //生产者唤醒消费者条件变量
    //消费者唤醒生产者条件变量
  }
  return NULL;
}
int main()
{
  pthread_t tid[3];
  int ret = 0;
  pthread_cond_init(&cond,NULL);
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
  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}
