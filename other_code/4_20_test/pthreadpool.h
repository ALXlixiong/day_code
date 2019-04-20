#ifndef __PTHREAD_POOL_HPP__
#define __PTHREAD_POOL_HPP__ 

#include <iostream>
#include <queue>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>

typedef void (*handle_t)(int);

class Task
{
  private:
    int _sock;
    handle_t _handle;
  public:
  Task(int sock,handle_t handle)
    :_sock(sock)
     ,_handle(handle)
  {}
  ~Task()
  {
//    close(_sock);
  }
  void Run()
  {
    _handle(_sock);
    close(_sock);
  }
};

class pthreadPool{
  private:
    int _nums;//线程总数
    int idle_nums;//空闲的线程个数
    std::queue<Task> task_queue;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
  public:
    pthreadPool(int nums = 10):_nums(nums),idle_nums(0)
  {
    pthread_mutex_init(&_mutex,NULL);
    pthread_cond_init(&_cond,NULL);
  }
    ~pthreadPool()
    {
      pthread_mutex_destroy(&_mutex);
      pthread_cond_destroy(&_cond);
    }
    void QueueLock()
    {
      pthread_mutex_lock(&_mutex);
    }
    void QueueUnlock()
    {
      pthread_mutex_unlock(&_mutex);
    }
    bool QueueEmpty()
    {
      return task_queue.size()>0?false:true;
    }
    void PthreadWait()
    {
      ++idle_nums;
      pthread_cond_wait(&_cond,&_mutex);
      --idle_nums;
    }
    Task PopTask()
    {
      Task t = task_queue.front();
      task_queue.pop();
      return t;
    }
    static void *PthreadRoute(void *arg)
    {
      pthreadPool *tp = (pthreadPool *)arg;
      pthread_detach(pthread_self());
      for(;;){
        tp->QueueLock();
        while(tp->QueueEmpty()){
          tp->PthreadWait();
        }
        Task t = tp->PopTask();
        tp->QueueUnlock();
        t.Run();
      }
    }
    void WakeUpOnePtread()
    {
      pthread_cond_signal(&_cond);
    }
    void PushTask(const Task &t)
    {
      QueueLock();
      task_queue.push(t);
      WakeUpOnePtread();
      QueueUnlock();
    }
    void InitPthreadPool()
    {
      pthread_t tid;
      for(int i = 0;i<_nums;++i){
        pthread_create(&tid,NULL,PthreadRoute,(void *)this);
      }
    }
};
#endif 
