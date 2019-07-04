#include <iostream>
using namespace std;
int n;  //输入有多少种物品
int c;  //每种物品有多少件
int v;  //每种物品的价值
int s;  //每种物品的尺寸
int count = 0; //分解后可得到多少种物品
int value[MAX]; //用来保存分解后的物品价值
int size[MAX];  //用来保存分解后物品体积

scanf("%d", &n);    //先输入有多少种物品，接下来对每种物品进行分解

while (n--)     //接下来输入n中这个物品
{
    scanf("%d%d%d", &c, &s, &v);  //输入每种物品的数目和价值
    for (int k=1; k<=c; k<<=1)   //<<右移 相当于乘二
    {
        value[count] = k*v;
        size[count++] = k*s;
        c -= k;
    }
    if (c > 0)
    {
        value[count] = c*v;
        size[count++] = c*s;
    }
}
