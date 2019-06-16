#include <iostream>
#include <vector>
using namespace std;

//这道题是一个典型的背包问题
//通过搜索，分为两种情况：选择、不选择
//如果选择当前值，那么背包空间和val都需要加到背包
//如果不选择，那么背包就是上一次的
//
//递归退出条件：m = 0，表示当前背包里面恰好就是结果，需要打印
//m<0，表示当前背包已经不足，所以背包里面数字并不满足要求
//start > n表示一轮遍历完毕
void GetFunc(int start,int n,int m,vector<int> v)
{
    //n:从1到n个数字
    //m:表示背包空间
    if(m == 0)
    {
        for(int i =0;i<v.size();++i)
            i == 0 ? cout<<v[i]:cout<<" "<<v[i];
        cout<<endl;
        return;
    }

    if(m < 0 || start>n)
        return;

    //要
    v.push_back(start);
    GetFunc(start+1,n,m-start,v);

    //不要
    v.pop_back();
    GetFunc(start+1,n,m,v);
}

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> v;
        int start = 1;
        GetFunc(start,n,m,v);
    }
    return 0;
}
