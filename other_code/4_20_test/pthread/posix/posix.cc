//实现信号量互斥，互斥和同步不可以同时实现
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

class Posix;

typedef struct info_t
{
  Posix *p;
}info_t;


class Posix
{
  public:
    Posix(){
      sem_init(&_sem,0,0);
    }
    ~Posix(){
      sem_destroy(&_sem);
    }

    static void *Get(void *arg)
    {
      info_t *info = (info_t *)arg;
      while(1)
      {
        sem_wait(&info->p->_sem);//在此处不可以给info->p->_sem重新定义一个变量，不然唤醒的是不同的信号量
        std::cout<<"get a apple"<<std::endl;
        sem_post(&info->p->_sem);
      }
      return NULL;
    }

    static void *Put(void *arg)
    {
      while(1)
      {
        info_t *info = (info_t *)arg;
        sem_wait(&info->p->_sem);
        std::cout<<"put a apple"<<std::endl;
        sem_post(&info->p->_sem);
      }
      return NULL;
    }

    void Run()
    {
      pthread_t tid[2];
      info_t *info = new info_t;
      info->p = this;
      if(pthread_create(&tid[0],NULL,Put,(void *)info) != 0)
      {
        perror("pthread_create error");
        exit(1);
      }
      if(pthread_create(&tid[1],NULL,Get,(void *)info) != 0)
      {
        perror("pthread_create error");
        exit(2);
      }
      
      pthread_join(tid[0],NULL);
      pthread_join(tid[1],NULL);
      delete info;
    }

  private:
    sem_t _sem;
};

int main()
{
  Posix p;
  p.Run();
  return 0;
}
