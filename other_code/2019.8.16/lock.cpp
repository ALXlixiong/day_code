//初始化
work[i] = avilable[i];
finish[1.2...n] = false;

while(1)
{
    bool flag = false;
    for(int i = 0;i<n;++i)
    {
        if(work[i]>=need[i] && finish[i]==false)
        {
            work[i] += allocation[i];//借出去的也是自己的
            finish[i] = true;
            flag = true;
        }
    }
    if(flag == false)
        break;
}

for(int i = 0;i<n;++i)
    if(finish[i] == false)
        return fasle;
return true;
