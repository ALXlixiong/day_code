//验证信号量实现线程间同步与互斥
//1、信号量初始化
//2、信号量操作（等待和通知）
//3、信号量的释放
// 
// 1、实现线程间同步
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <semaphore.h>
#include<pthread.h>
#include<stdlib.h>

sem_t sem;
int ticket = 100;
void *pthread_producer(void *arg)
{
  while(1)
  {
    printf("producer    p\n");
    //发布信号
    sem_post(&sem);
    usleep(1000);
  }
}
void *pthread_consumer(void *arg)
{
  while(1)
  {
    //没有资源等待
    sem_wait(&sem);
    printf("consumer  c\n");
    usleep(1000);
  }
}
//实现互斥
void *pthread_ticket(void *arg)
{
  int tmp = (int)arg;
  while(1)
  {
    sem_wait(&sem);//信号量初始值为1，会将信号量计数器减1变为0，阻塞后面线程
    if(ticket>0)
    {
      //sleep(1);
      printf("%d buy ticket  %d\n",tmp,ticket);
      --ticket;
      sem_post(&sem);//信号量计数器加1
    }
    else 
    {
      printf("%d no buy  ticket!!!\n",tmp);
      sem_post(&sem);
      break;
    }
  }
  return NULL;
}

int main()
{
  pthread_t tid1,tid2;
  //初始化信号量
  sem_init(&sem,0,1);

  if(pthread_create(&tid1,NULL,pthread_ticket,(void *)1)!= 0)
  {
    printf("pthread_create error!!\n");
    return -1;
  }
  if(pthread_create(&tid2,NULL,pthread_ticket,(void *)2) != 0)
  {
    printf("pthread_create error!!\n");
    return -1;
  }
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  //销毁信号量
  sem_destroy(&sem);
  return 0;
}
