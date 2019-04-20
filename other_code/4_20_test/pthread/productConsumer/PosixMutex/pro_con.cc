//这是一个基于环形队列实现的生产者与消费者模型
//使用vector实现环形队列
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <vector>
using namespace std;
const size_t MAXSCOPE = 10;

class RingQueue;
typedef struct info_t
{
  RingQueue *p;
}info_t;

class RingQueue
{
  public:
    RingQueue(size_t capacity = MAXSCOPE)
      :_capacity(capacity)
       ,_list(MAXSCOPE)
       ,_product_index(0)
       ,_consumer_index(0)
  {
    pthread_mutex_init(&_mutex,NULL);
    sem_init(&_space,0,capacity);
    sem_init(&_data,0,0);
    _product_index = 0;
    _consumer_index = 0;
  }
    ~RingQueue()
    {
      pthread_mutex_destroy(&_mutex);
      sem_destroy(&_space);
      sem_destroy(&_data);
    }

    void QueuePush(int &data)
    {
      //sem_wait本身就是一个判断条件
      sem_wait(&_space);
      pthread_mutex_lock(&_mutex);
      _list[_product_index] = data;
      cout<<"push a data = "<<data<<endl;
      _product_index = (_product_index + 1)%_capacity;
      pthread_mutex_unlock(&_mutex);
      sem_post(&_data);
    }

    void QueuePop()
    {
      sem_wait(&_data);
      pthread_mutex_lock(&_mutex);
      int data = _list[_consumer_index];
      cout<<"pop a data = "<<data<<endl;
      _consumer_index = (_consumer_index + 1)%_capacity;
      pthread_mutex_unlock(&_mutex);
      sem_post(&_space);
    }

    static void *productor(void *arg)
    {
      info_t *info = (info_t *)arg;
      int data = 0;
      while(1)
      {
        info->p->QueuePush(++data);
      }
      return NULL;
    }
    static void *consumer(void *arg)
    {
      info_t *info = (info_t *)arg;
      while(1)
      {
        info->p->QueuePop(); 
      }
      return NULL;
    }
    void Run()
    {
      pthread_t tid[2];
      info_t *info = new info_t;
      info->p = this;
      if(pthread_create(&tid[0],NULL,productor,(void *)info) != 0)
      {
        perror("pthread_create error");
        exit(1);
      }
      if(pthread_create(&tid[1],NULL,consumer,(void *)info) != 0)
      {
        perror("pthread_create error");
        exit(2);
      }
      pthread_join(tid[0],NULL);
      pthread_join(tid[1],NULL);
      delete info;
    }

  private:
    vector<size_t> _list;
    size_t _capacity;
    size_t _product_index;//生产者下标
    size_t _consumer_index;//消费者下标
    pthread_mutex_t _mutex;
    sem_t _space;//对于生产者还有没有位置
    sem_t _data;//对于消费者还有多少个数据可以取
};


int main()
{
  RingQueue q;
  q.Run();
  return 0;
}
