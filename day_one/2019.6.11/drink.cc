#include <iostream>

class Solution
{
    private:
        int _num;
        int _total;
    public:
        Solution(int num):_num(num),_total(0)
    {}
        void GetResultFunc()
        {
            while(1)
            {
                if(_num == 2){
                    _total++;
                    break;
                }
                else if(_num<2){
                    break;
                }
                else{
                    int tmp1 = _num/3;
                    int tmp2 = _num%3;
                    _num = tmp1 + tmp2;
                    _total += tmp1;
                }
            }
            std::cout<<_total<<std::endl;
        }
};

int main()
{
    int num = 0;
    while(std::cin>>num)
    {
        if(num == 0){
            break;
        }
        Solution s(num);
        s.GetResultFunc();
    }
    return 0;
}
