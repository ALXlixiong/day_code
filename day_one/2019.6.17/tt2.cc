#include<iostream>
#include<queue>
#include<string.h>
#include <stdio.h>
using namespace std;
int a[10][10] = {0};//记录格子状态，0代表没有走过
char str[10][10];//记录迷宫
int bfs(int x0,int y0)
{
    queue<pair<int,int> > q;//存储格子坐标的队列
    pair<int,int> p;
    int x,y;
    q.push(make_pair(x0,y0));
    while(1)
    {
        p = q.front();
        x = p.first;
        y = p.second;
        if(x==9&&y==8)//走到终点就退出循环
            return a[9][8];
/*
下面是4个if语句，分别对应格子的上、下、左、右四个相邻的格子
如果这个格子符合条件(坐标不越界，同时不是'#'，并且之前没有走过)
就把它放入队列。这里需要注意的是，队列先进先出就保证了离出口近的
格子总是比离出口远的格子先处理，也就是说只有当广度(离出口距离比如2)
的所有格子都pop()出队列，广度为3的格子才变为队首元素。就这样一点点
增加广度，直到走到出口。
当然你也可以用一个for循环替代这里的4个if，但我想写的详细点*/
        if((x-1)>=0&&(x-1)<=9&&y>=0&&y<=9&&a[x-1][y]==0&&str[x-1][y]!='#')
        {
            a[x-1][y]=a[x][y]+1;
            q.push(make_pair(x-1,y));
        }
        if((x+1)>=0&&(x+1)<=9&&y>=0&&y<=9&&a[x+1][y]==0&&str[x+1][y]!='#')
        {
            a[x+1][y]=a[x][y]+1;
            q.push(make_pair(x+1,y));
        }
        if(x>=0&&x<=9&&(y-1)>=0&&(y-1)<=9&&a[x][y-1]==0&&str[x][y-1]!='#')
        {
            a[x][y-1]=a[x][y]+1;
            q.push(make_pair(x,y-1));
        }
        if(x>=0&&x<=9&&(y+1)>=0&&(y+1)<=9&&a[x][y+1]==0&&str[x][y+1]!='#')
        {
            a[x][y+1]=a[x][y]+1;
            q.push(make_pair(x,y+1));
        }
        q.pop();//判断完上下左右4个格子后该格子应该出队
    }
}
int main()
{
    char c;
    while(~scanf("%c",&c))
    {
        str[0][0] = c;
        for(int i=1;i<10;i++)
        {
            scanf("%c",&c);
            str[0][i] = c;
        }
        getchar();//吃掉末尾的换行符
        for(int i=1;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                scanf("%c",&c);
                str[i][j] = c;
            }
            getchar();//吃掉末尾的换行符
        }
        printf("%d\n",bfs(0,1));
        memset(a,0,sizeof(a));//初始化全局变量a数组
    }
    return 0;
}
