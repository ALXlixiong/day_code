//抢票例子
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

pthread_mutex_t mutex;
class Mutex;
typedef struct info_t
{
  int i;
  Mutex *p;
  int ticket;
}info_t;

class Mutex
{
  public:
    Mutex(int ticket = 100)
      :_ticket(ticket)
    {}
    static void* route(void *arg)
    { 
      info_t *info = (info_t *)arg;
      while(1)
      {
        pthread_mutex_lock(&mutex);
        if(info->ticket>0)
        {
          cout<<info->i<<" get a ticket!  "<<info->ticket<<endl;
          --info->ticket;
        }
        else 
        {
          pthread_mutex_unlock(&mutex);//在任何一个可能退出的位置解锁
          return NULL;
        }
        pthread_mutex_unlock(&mutex);
      }
    }
    void Run()
    {
      pthread_t tid[4];
      int ret = 0;
      info_t *info = new info_t;
      for(int i = 0;i<4;++i)
      {
        pthread_mutex_init(&mutex,NULL);
        info->i = i;
        info->p = this;
        info->ticket = _ticket;

        ret = pthread_create(&tid[i],NULL,route,(void *)info);
        if(ret != 0)
        {
          cerr<<"pthread_create error!"<<endl;
          exit(1);
        }
      }
      for(int i = 0;i<4;++i)
      {
        pthread_join(tid[i],NULL);
      }
      pthread_mutex_destroy(&mutex);
      delete info;
    }
  private:
    int _ticket;
};
int main()
{
  Mutex p;
  p.Run();
  return 0;
}
