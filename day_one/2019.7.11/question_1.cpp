#include <iostream>
#include <cstdio>
//获奖的概率为0，那么总的抽奖次数是n！，这是分母
//分子是错排的种类数
int main()
{
    int n = 0;
    double dp[21] = {0,0,1,0};
    for(int i = 3;i<21;++i)
    {
        dp[i] = (i-1) *(dp[i-1] + dp[i-2]);
    }
    while(std::cin>>n)
    {
        double sum = 1;
        for(int i = 1;i<=n;++i)
            sum *= i;
        double ret = (dp[n]/sum)*100;
        printf("%4.2lf\%\n",ret);
    }
    return 0;
}
