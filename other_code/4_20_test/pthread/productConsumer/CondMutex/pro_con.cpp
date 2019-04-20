//实现生产者和消费者模型

#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_NODE 10
using namespace std;

class BlockingQueue
{
  private:
    queue<int> _list;
    size_t _capacity;  //队列最大节点数
    pthread_cond_t _full;
    pthread_cond_t _empty;
    pthread_mutex_t _mutex;
  public:
    BlockingQueue(int capacity = MAX_NODE)
      :_capacity(capacity)
    {
      pthread_cond_init(&_full,NULL);
      pthread_cond_init(&_empty,NULL);
      pthread_mutex_init(&_mutex,NULL);
    }
    ~BlockingQueue()
    {
      pthread_cond_destroy(&_full);
      pthread_cond_destroy(&_empty);
      pthread_mutex_destroy(&_mutex);
    }
    bool QueuePush(int data)
    {
      pthread_mutex_lock(&_mutex);
      while(_capacity == _list.size())
        pthread_cond_wait(&_full,&_mutex);
      _list.push(data); 
      pthread_mutex_unlock(&_mutex);
      pthread_cond_signal(&_empty);
      return true;
    }

    bool QueuePop(int &data)
    {
      pthread_mutex_lock(&_mutex);
      while(_list.empty()){
        cout<<"---------------"<<endl;
        pthread_cond_wait(&_empty,&_mutex);
      }
      data = _list.front();
      _list.pop(); 
      pthread_mutex_unlock(&_mutex);
      pthread_cond_signal(&_full);
      return true;
    }
};

void *Product(void *arg)
{
  BlockingQueue *p = (BlockingQueue *)arg;
  int i = 1;
  while(1)
  {
    p->QueuePush(i);
    cout<<"push a number "<<i<<endl;
    i++;
  }
  return NULL;
}

void *Consumer(void *arg)
{
  BlockingQueue *p = (BlockingQueue*)arg;
  int data = 0;
  while(1)
  {
    p->QueuePop(data);
    cout<<"pop a number "<<data<<endl;
  }
}

int main()
{
  pthread_t tid[2];
  BlockingQueue *p = new BlockingQueue;

  int ret = 0;
  ret = pthread_create(&tid[0],NULL,Product,(void *)p);
  if(ret != 0)
  {
    perror("pthread_create error");
    exit(1);
  }
  ret = pthread_create(&tid[1],NULL,Consumer,(void *)p);
  if(ret != 0)
  {
    perror("pthread_create error");
    exit(1);
  }
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  delete p;
  return 0;
}
