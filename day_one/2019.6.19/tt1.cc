//DFS算法
// 我是用一个二维int型数组a[20][20]来记录的（数组默认全为0）
//'.'记为0,'#'和'@'记为1（注意在输入的时候就可以判断）同时走过的格子也记为1
//那么对于一次DFS只要递归它的上、下、左、右4个相邻的格子就行
//由一个全局变量res记录结果
#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = {0},res = 0,m,n;//注意是全局变量，多组数据时要在最后初始化
void dfs(int x,int y)
{
    if(a[x][y]==1||x<0||x>=m||y<0||y>=n)//递归的边界条件
        return ;
    res++;    //结果增加1
    a[x][y] = 1;//置1代表已经走过
    dfs(x-1,y);//分别对应上
    dfs(x+1,y);//下
    dfs(x,y-1);//左
    dfs(x,y+1);//右相邻格子
     
}
int main()
{
    while(~scanf("%d %d",&m,&n))
    {
        getchar();//为什么要getchar()?因为第一行9 6后面还有一个换行符
        int x,y;
        char c;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%c",&c);
                if(c=='@')
                {
                    x = i;
                    y = j;
                }else{
                    if(c=='#')
                        a[i][j] = 1;
                }
            }
            getchar();//同样的，吃掉每行最后一个换行符
        }
        dfs(x,y);
        printf("%d\n",res);
        res = 0;
        memset(a,0,sizeof(a));//全局变量初始化
    }
 
    return 0;
}
