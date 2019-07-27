#include <iostream>
#include <vector>
#include <string>

bool count(std::vector<std::string> broad,int x,int y)
{
    if(broad[x][y] == '.')
        return false;
    int row = broad.size();
    int col = broad[0].size();

    int up_count = 0;
    int down_count = 0;
    for(int i = x-1;i>= 0;--i)
    {
        if(broad[i][y] == broad[x][y])
            ++up_count;
        else
            break;
    }
    for(int i = x+1;i<row;++i)
    {
        if(broad[i][y] == broad[x][y])
            ++down_count;
        else
            break;
    }
    if((up_count + down_count + 1)>=5)
        return true;
    int left_count = 0;
    int right_count = 0;
    for(int j = y-1;j>=0;--j)
    {
        if(broad[x][j] == broad[x][y])
            ++left_count;
        else
            break;
    }
    for(int j = y+1;j<col;++j)
    {
        if(broad[x][j] == broad[x][y])
            ++right_count;
        else
            break;
    }
    if((left_count + right_count + 1)>=5)
        return true;

    int left_up_count = 0;
    int right_down_count = 0;
    int i = x-1;
    int j = y-1;
    while(i>=0 && j>=0)
    {
        if(broad[x][y] == broad[i][j])
            ++left_up_count;
        else
            break;
        --i;--j;
    }
    i = x+1;
    j = y+1;
    while(x<row && j<col)
    {
        if(broad[x][y] == broad[i][j])
            ++right_down_count;
        else
            break;
        ++i;++j;
    }
    if((left_up_count + right_down_count + 1)>=5)
        return true;

    int right_up_count = 0;
    int left_down_count = 0;
    i = x-1;
    j = y+1;
    while(i>=0 && j<col)
    {
        if(broad[x][y] == broad[i][j])
            ++right_up_count;
        else
            break;
        --i;++j;
    }
    
    i = x+1;
    j = y-1;
    while(x<row && j>=0)
    {
        if(broad[x][y] == broad[i][j])
            ++left_down_count;
        else
            break;
        ++i;--j;
    }
    if((right_up_count + left_down_count + 1)>=5)
        return true;
    return false;
}

int main()
{
    int row = 20;
    int col = 20;
    std::vector<std::string> broad(row,"");
    while(1)
    {
        for(int i = 0;i<row;++i)
        {
            std::cin>>broad[i];
        }
        bool flag = false;
        for(int i = 0;i<row;++i)
        {
            for(int j = 0;j<col;++j)
            {
                if(count(broad,i,j))
                {
                    std::cout<<"Yes"<<std::endl;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            std::cout<<"No"<<std::endl;
    }
    return 0; 
}
