#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

void* entrance(void * arg)
{
    (void)arg;

    std::cout << "This is thread, tid = " << pthread_self() << std::endl;

    pid_t pid = fork();
    if(pid < 0)
    {
        std::cerr << "fork error" << std::endl;
    }
    std::cout << "fork succeed, pid = " << getpid() << std::endl;

    if(pid == 0)
    {
        std::cout << "hahaha, I'm from child. pid = " << getpid() << " tid = " << pthread_self() << std::endl;
        execlp("./exec", "./exec", (char*)0);
    }
    else
    {
        sleep(1);
        waitpid(pid, nullptr, 0);
        std::cout << "I'm father, pid = " << getpid() << " tid = " << pthread_self() << std::endl;
    }

    return nullptr;
}

void* xxxx(void* arg)
{
    (void)arg;
    execlp("./exec", "./exec", (char*)0);
    return nullptr;
}

int main(void)
{
    pthread_t tid = 0;

    std::cout << "I come from main, pid = " << getpid() << std::endl;

    pthread_create(&tid, nullptr, xxxx, nullptr);

    std::cout << "I'm main thread, tid = " << pthread_self() << std::endl;

    pthread_join(tid, nullptr);

    return 0;
}

