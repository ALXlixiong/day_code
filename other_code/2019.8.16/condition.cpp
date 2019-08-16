#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <stdlib.h>
#include <time.h>

template<class T>
class BlockQueue
{
    private:
        std::queue<T> q_;
        size_t cap_;
        pthread_mutex_t mutex_;
        pthread_cond_t full_;
        pthread_cond_t empty_;
    public:
        BlockQueue(size_t cap = 10):cap_(cap)
    {
        pthread_mutex_init(&mutex_,nullptr);
        pthread_cond_init(&full_,nullptr);
        pthread_cond_init(&empty_,nullptr);
    }

        bool IsFull()
        {
            return q_.size() == cap_ ? true : false;
        }
        bool IsEmpty()
        {
            return q_.size() != cap_ ? true : false;
        }

        void PushData(T data)
        {
            pthread_mutex_lock(&mutex_);
            while(IsFull())
            {
                pthread_cond_signal(&empty_);
                std::cout<<"queue is full,stop product\n";
                pthread_cond_wait(&full_,&mutex_);
            }
            q_.push(data);
            pthread_cond_signal(&empty_);
            pthread_mutex_unlock(&mutex_);
        }

        T PopData()
        {
            pthread_mutex_lock(&mutex_);
            while(IsEmpty())
            {
                pthread_cond_signal(&full_);
                std::cout<<"queue is empty,stop consumer\n";
                pthread_cond_wait(&empty_,&mutex_);
            }
            sleep(1);
            int data = q_.front();
            q_.pop();
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&full_);
            return data;
        }
        ~BlockQueue()
        {
            pthread_cond_destroy(&full_);
            pthread_cond_destroy(&empty_);
            pthread_mutex_destroy(&mutex_);
        }
};

void *product(void *arg)
{
    BlockQueue<int> *q = (BlockQueue<int>*)arg;
    int i = 1;
    for(;;)
    {
        q->PushData(i++);
    }
    return nullptr;
}

void* consumer(void *arg)
{
    BlockQueue<int> *q = (BlockQueue<int>*)arg;
    for(;;)
    {
        std::cout<<"consumer: "<<q->PopData()<<std::endl;
    }
    return nullptr;
}


int main()
{
    pthread_t tid[2];
    BlockQueue<int> q;
    pthread_create(&tid[0],nullptr,product,(void *)&q);
    pthread_create(&tid[1],nullptr,consumer,(void *)&q);

    for(int i = 0;i<2;++i)
        pthread_join(tid[i],nullptr);
    return 0;
}
