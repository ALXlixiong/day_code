#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    public:
        void GetFunc(vector<int> &arr,vector<int> &res,int k,int n)
        {
            while(k--)
            {
                int tmp = n;
                while(tmp--)
                {
                    res.push_back(arr[n+tmp]);
                    res.push_back(arr[tmp]);
                }
            }
            reverse(res.begin(),res.end());
        }
};

int main()
{
    int task = 0;
    cin>>task;
    while(task--)
    {
        int n = 0;
        int k = 0;
        cin>>n>>k;
        vector<int> arr(2*n,0);
        for(int i = 0;i<2*n;++i)
            cin>>arr[i];
        Solution s;
        vector<int> res;
        s.GetFunc(arr,res,k,n);
        for(int i = 0;i<2*n-1;++i)
            cout<<res[i]<<" ";
        cout<<res[2*n-1]<<endl;
    }
    return 0;
}
