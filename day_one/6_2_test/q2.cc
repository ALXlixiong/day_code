#include <iostream>
using namespace std;
//返回一个二进制数中1的最大连续个数
class Solution
{
    private:
        int _num;
    public:
        Solution(int num):_num(num)
    {}
        void GetBitCount()
        {
            int k = 0;
            for(k = 0;_num != 0;++k)
            {
                _num = _num & (_num<<1);
            }
            cout<<k<<endl;
        }
};

int main()
{
    int num = 0;
    while(cin>>num)
    {
        Solution s(num);
        s.GetBitCount();
    }
    return 0;
}
