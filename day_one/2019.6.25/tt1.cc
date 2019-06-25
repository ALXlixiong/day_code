#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n = 0;
    while(cin>>n)
    {
        vector<int> v(3*n,0);
        for(int i = 0;i<3*n;++i)
            cin>>v[i];
        sort(v.begin(),v.end());
        int begin =0;
        int end = 3*n-2;
        long ret = 0;
        while(begin<end)
        {
            ret += v[end];
            end = end -2;
            begin++;
        }
        cout<<ret<<endl;
    }
    return 0;
}
