#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
void sigcb(int signo,siginfo_t *info,void *cur)
{
 // printf("signo:%d\n",signo);
 // printf("info->si_int:%d\n",info->si_int);
 // printf("info->si_value.sival_int:%d\n",info->si_value.sival_int);
    printf("signo:%d\n",signo);
    printf("info->si_ptr:%s\n",info->si_ptr);
    printf("info->si_value.sival_ptr:%s\n",info->si_value.sival_ptr);
}
 
int main(int argc,char *argv[2])
{
  //int sigaction(int signum, const struct sigaction *act,) 
  //             struct sigaction *oldact);
  //struct sigaction {
  //    //sa_handler和sa_sigaction是信号处理函数，但是handler函数接口就和signal函数接口用法一样
  //    //如果参数sa_flags = SA_SIGINFO时，调用的处理函数是sa_sigaction，
  //    void (*sa_handler)(int);
  //    
  //    void (*sa_sigaction)(int, siginfo_t *, void *);
  //    sigset_t sa_mask;//在信号处理时，暂时想要阻塞哪些信号
  //    int  sa_flags;
  //    void (*sa_restorer)(void);//不用
  //         };
  // 
  struct sigaction act;
  sigemptyset(&act.sa_mask);
  sigfillset(&act.sa_mask);
  act.sa_sigaction = sigcb;
  act.sa_flags = SA_SIGINFO;
  sigaction(2,&act,NULL);
  while(1)
  {
    //int sigqueue(pid_t pid, int sig, const union sigval value);
    union sigval val;
    //val.sival_int = 100;
    //sigqueue(getpid(),atoi(argv[1]),val);
    char *buf = "hello world!\n";
    val.sival_ptr = (char *)malloc(sizeof(buf));
    strcpy((char *)val.sival_ptr,buf); 
    //通过命令行参数传入信号,如果为2，则会循环处理，如果为9，则会杀死
    sigqueue(getpid(),atoi(argv[1]),val);
    sleep(2);
  }
  return 0;
}
