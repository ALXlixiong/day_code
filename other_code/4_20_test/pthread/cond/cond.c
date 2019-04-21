#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int g_tmp = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;
void *sale(void *arg)
{
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    printf("生产了一个\n");
    g_tmp = 1;
    //int pthread_cond_broadcast(pthread_cond_t *cond);
    //广播通知，通知等待队列中所有线程
    pthread_cond_signal(&cond);
    sleep(1);//这里只是限制时间，如果没有这个时间，那么导致生产大量。
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void *eat(void *arg)
{
  (void)arg;
  while(1)
  {
    pthread_mutex_lock(&mutex);
    while(g_tmp == 0)
    {
      //int pthread_cond_wait(pthread_cond_t *restrict cond,
      //              pthread_mutex_t *restrict mutex);
      //    mutex:互斥锁 不可以给NULL
      //为什么有个锁？
      //因为条件是临界资源，所以我们需要互斥锁。但是如果加锁了，刚开始生产家条件不满足
      //陷入休眠，造成死锁。所以在卖家等待之前需要解锁，但是解锁和等待不是原子操作，可能生产家
      //修改完变量之后通知卖家，导致该信号错过，导致陷入永久休眠
      //所以我们需要在等待函数上加一个锁，构造一个等待函数原子操作（包含一个锁）
      pthread_cond_wait(&cond,&mutex);  
      //为什么需要循环？？？
      //在wait函数内部包含解锁和加锁：
      //被唤醒之后接着加锁，继续操作，但是这个锁，并不是因为锁被别人获取而等待；
      //并不会阻塞
      //被唤醒之后可能唤醒多个线程，导致都向下执行，所以还需要再次循环判断条件是否满足
      //使得只能有一个线程向下执行
    }
    g_tmp = 0;//注意顺序
    printf("eat a noodle!!!\n");
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
int main()
{
  pthread_t tid[2];
  int ret = 0;
  pthread_cond_init(&cond,NULL);
  pthread_mutex_init(&mutex,NULL);
  ret = pthread_create(&tid[1],NULL,eat,NULL);
  if(ret != 0)
  {
    perror("create error!");
    exit(1);
  }
  ret = pthread_create(&tid[0],NULL,sale,NULL);
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
