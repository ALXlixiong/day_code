//伪代码
//银行家算法要求：
//1. 新来的进程需要向系统提供自己在运行期间需要所有资源的最大数量
//2. 每次在给进程分配资源的时候，先判断是否有足够的资源分配，如果没有则等待，否则，判断如果分配了是不是处于安全状态
//
//需要的参数：
//1. avilable：系统剩余资源数
//2. max：进程最大需要资源的个数
//3. allocate：已经分配的资源
//4. need：还需要多少资源
finish[1...n] = false;
work = avilable;
flag = false;

while(true)
{
    flag = false;
    for(int i = 0;i<n;++i)
    {
        if(finish[i] == false && need[i]<work)
        {
            work += alocation[i];
            finish[i] = true;
            flag= true;
        }
    }
    if(!flag)
        break;
}
