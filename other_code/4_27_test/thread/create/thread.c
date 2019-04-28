#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
void *threadfun(void *arg)
{
  printf("%lu\n",pthread_self());
  char *str = (char *)arg;
  while(1)
  {
    printf(str);
    sleep(1);
  }
}

int main()
{
  //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,)
  //                   void *(*start_routine) (void *), void *arg);
  //功能：创建一个线程（轻量级进程）（用户线程）
  //thread：线程ID，输出型参数
  //attr：设置线程属性，NULL表示默认
  //start_routine：线程的入口函数地址
  //arg：线程入口函数的参数
  //返回值：正确0 错误返回错误码
  pthread_t tid;
  int ret = pthread_create(&tid,NULL,threadfun,"hello thread\n");
  if(ret != 0)
  {
    perror("pthread");
    return -1;
  }
  printf("child:%lu",tid);
  while(1)
  {
    printf("hello process\n");
    sleep(1);
  }
  return 0;
}
