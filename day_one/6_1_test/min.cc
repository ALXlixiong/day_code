#include <iostream>
using namespace std;
#include <cmath>
class Solution{
    private:
        int _num;
    public:
        Solution(int num):_num(num)
    {}
        void GetFunc()
        {
            int ret = 0;
            int arr[2] = {0};
            for(int i = 2;i<=_num/2;++i)
            {
                if(JudgeIsPrime(i) && JudgeIsPrime(_num-i))
                {
                    if(ret == 0 || ret>(_num -i*2)){
                        ret = _num -i*2;
                        arr[0] = i;
                        arr[1] = _num-i;
                    }
                }
            }
            cout<<arr[0]<<endl;
            cout<<arr[1]<<endl;
        }
    private:
        bool JudgeIsPrime(int num)
        {
            if(num == 1)
                return false;
            for(int i = 2;i<num;++i)
            {
                if(num%i == 0)
                    return false;
            }
            return true;
        }
};
int main()
{
    int num = 0;
    while(cin>>num){
        Solution s(num);
        s.GetFunc();
    }
    return 0;
}
