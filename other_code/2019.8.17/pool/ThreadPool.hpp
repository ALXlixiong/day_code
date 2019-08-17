#include <iostream>
#include <queue>
#include <functional>
#include <pthread.h>

template<class T>
class Task
{
    private:
        T arg_;
        std::function<void*(T)> handle_;
    public:
        Task(std::function<void*(T)> handle,T arg)
            :arg_(arg)
            ,handle_(handle)
    {}

        void Run()
        {
            std::cout<<"arg:"<<arg_<<std::endl;
            handle_(arg_);
        }
};

template<class T>
class ThreadPool
{
    private:
        std::queue<Task<T> > q_;
        int num_;//队列线程容量
        int idle_;//空闲的线程个数
        pthread_mutex_t mutex_;
        pthread_cond_t full_;
        pthread_cond_t empty_;
        pthread_t *tid_;
    public:
        ThreadPool(size_t num = 10)
            :num_(num)
            ,idle_(num)
    {
        pthread_mutex_init(&mutex_,nullptr);
        pthread_cond_init(&full_,nullptr);
        pthread_cond_init(&empty_,nullptr);
        tid_ = new pthread_t[num_];
    }


        void ThreadPoolInit()
        {
            for(size_t i = 0;i<num_;++i)
            {
                if(pthread_create(&tid_[i],nullptr,arg_route,(void*)this)<0)
                    std::cerr<<"pthread create error\n";
            }
            for(size_t i = 0;i<num_;++i)
                pthread_detach(tid_[i]);
        }

        bool QueueIsEmpty()
        {
            return q_.size() == 0 ? true : false;
        }

        static void* arg_route(void *arg)
        {
            ThreadPool *info = (ThreadPool *)arg;
            for(;;)
            {
                std::cout<<pthread_self()<<std::endl;
                pthread_mutex_lock(&info->mutex_);
                while(info->QueueIsEmpty())
                {
                    pthread_cond_signal(&info->full_);
                    std::cout<<"queue is empty,start product\n";
                    pthread_cond_wait(&info->empty_,&info->mutex_);
                    --info->idle_;
                }
                //处理任务
                Task<T> task = info->q_.front();
                info->q_.pop();
                pthread_cond_signal(&info->full_);
                pthread_mutex_unlock(&info->mutex_);
                task.Run();
                ++info->idle_;
            }
            return nullptr;
        }

        bool QueueIsFull()
        {
            return q_.size()> 4 ? true:false;
        }
        void PushQueue(Task<T> t)
        {
            pthread_mutex_lock(&mutex_);
            while(QueueIsFull())
            {
                pthread_cond_signal(&empty_);
                std::cout<<"queue is full,stop prodct\n";
                pthread_cond_wait(&full_,&mutex_);
            }
            q_.push(t);
            pthread_cond_signal(&empty_);
            pthread_mutex_unlock(&mutex_);
        }

        ~ThreadPool()
        {
            delete[] tid_;
            pthread_mutex_destroy(&mutex_);
            pthread_cond_destroy(&full_);
            pthread_cond_destroy(&empty_);
        }
};
