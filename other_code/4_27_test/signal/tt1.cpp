#include<iostream>
using namespace std;
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main()
{
  //int kill(pid_t pid,int sig)
  //向指定的进程发送指定的信号
  //pid进程ID，用于指定发送给哪个进程
  //sig信号编号，用于指定发送什么信号
  //
  //int raise(int sig)
  //给调用进程或者线程发送信号，其实就是给自己发送信号
  //
  //int sigqueue(pid_t pid, int sig, const union sigval value);
  //给指定的进程发送信号，同时携带一个参数过去
  //union sigval {
  //  int   sival_int;
  //  void *sival_ptr;
  //};
  //当给另外一个进程发送sigval参数时，其中第二个参数没用，因为每一个进程都有自己独立的一份虚拟地址空间
  //所以对于另外一个进程来说有用的值就是第一个参数sigval_val
  //
  //unsigned int alarm(unsigned int seconds);
  //指定在seconds秒之后，向进程发送SIGALRM信号
  //返回值：返回上一个定时器的剩余时间
  size_t ret = alarm(4);
  cout<<"ret = "<<ret<<endl;
  ret = alarm(4);//第二个定时器返回第一个定时器还有多长时间停止。并且以最后一个停止时间为准（定时器覆盖）
  //alarm(0)取消之前的定时器
  cout<<"ret = "<<ret<<endl;
  while(1)
  {
    sleep(1);
    cout<<"hello world!!!\n";

    //kill(getpid(),2);
    //raise(9);
    //sigqueue(getpid(),9,union sigval(0));
    //sigqueue使用不了
  }
  return 0;
}

