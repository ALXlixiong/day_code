//伪代码

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
