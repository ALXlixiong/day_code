#include <iostream>
using namespace std;
#include <vector>

void Func(vector<int> v)
{
    vector<int> res(v.size(),1);
    for(int i = 0;i<v.size();++i)
    {
        for(int j = 0;j<i;++j)
        {
            if(v[j]<v[i])
                res[i] = res[j]+1;
        }
    }
    int max = 0;
    for(int i = 0;i<res.size();++i)
    {
        if(res[i]>max)
            max = res[i];
    }
    cout<<max<<endl;
}

int main()
{
    int n = 0;
    while(cin>>n)
    {
        vector<int> v(n,0);
        for(int i = 0;i<v.size();++i)
            cin>>v[i];
        Func(v);
    }
    return 0;
}
