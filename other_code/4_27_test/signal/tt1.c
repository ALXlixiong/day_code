//演示信号阻塞

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  //阻塞这个集合中的信号
  sigset_t new_block;
  //保存原来阻塞集合中的信号，防止以后要还原信号集
  sigset_t old_block;
  if(sigemptyset(&new_block))
  {
    perror("sigempty error");
    return -1;
  }
  if(sigfillset(&new_block))
  {
    perror("sigfillset error");
    return -1;
  }
  //int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
  //功能：阻塞信号或者解除信号
  //
  //阻塞和备份
  if(sigprocmask(SIG_BLOCK,&new_block,&old_block) == 0)
  {
    getchar();//按下回车解除阻塞或者还原
    //获取未决信号集
    sigset_t pending;
    sigemptyset(&pending);
    //获取未决信号
    //未决信号：信号产生（注意是产生）到抵达之间的状态就是信号未决
    //所以，当我们按下ctrl+c最终才会显示打印消息
    sigpending(&pending);
    if(sigismember(&pending,SIGINT))
    {
      printf("1 is blocked\n");
    }
    //解除阻塞
    sigprocmask(SIG_UNBLOCK,&new_block,NULL);
    //还原
    sigprocmask(SIG_SETMASK,&old_block,NULL);
  }
  return 0;
}
