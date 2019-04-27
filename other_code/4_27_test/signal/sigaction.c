//因为signal函数有linux版本的差异，所以信号自定义函数处理方式我们一般用sigaction

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

//struct sigaction {
//    void     (*sa_handler)(int);处理函数
//    void     (*sa_sigaction)(int, siginfo_t *, void *);处理函数
//    sigset_t   sa_mask;在处理信号时，可以暂时阻塞一些想要阻塞的信号，处理完毕还原回去
//    int        sa_flags;决定我们使用哪个处理函数
//    void     (*sa_restorer)(void);不用
//};

void sigcb(int signo)
{
  printf("signo:%d\n",signo);
}

void _sigcb(int signo, siginfo_t * info, void * context)
{
  printf("signo:%d\n",signo);
  printf("info:%d\n",info->si_int);
}
int main()
{
  //int sigaction(int signum, const struct sigaction *act,) 
  //      struct sigaction *oldact);
  // signum:信号编号
  // act：新的处理方式
  // oldsct：保存原来的处理方式
  struct sigaction new_act;
  struct sigaction old_act;
  //和signal一样
  sigemptyset(&new_act.sa_mask);
  new_act.sa_flags = 0;
  new_act.sa_handler = sigcb;
  sigaction(SIGINT,&new_act,&old_act);
  
  sigemptyset(&new_act.sa_mask);
  new_act.sa_flags = SA_SIGINFO;
  new_act.sa_sigaction = _sigcb;
  sigaction(SIGQUIT,&new_act,&old_act);
  while(1)
  {
    sleep(2);
    kill(getpid(),SIGINT);
    //int sigqueue(pid_t pid, int sig, const union sigval value);
    //功能：可以发送一个信号，还可以携带一个参数
    // pid:进程id
    // sig：信号编号
    // value：参数
    union sigval val;
    val.sival_int = 666;
    sigqueue(getpid(),SIGQUIT,val);
  }
  return 0;
}
