/*
 *求数组的所有子集，并且每个子集按照顺序打印
 *思路：通过位运算求子集，每个数字用比特位表示存在 与 不存在；1表示存在，0表示不存在
 *如果都不存在那么比特位组成的数字就是0；
 *如果都存在那么比特位组成的数字就是全11111111……
 *0到全1有2^n个数，循环判断每个数组，得到的结果通过排序填入到结果中
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Solution
{
    static void GetAllSubsets(vector<int> &v_)
    {
        vector<vector<int> > result;
        int count = pow(2,v_.size())-1;
        int limit = v_.size();
        for(int i = 0;i<=count;++i)
        {
            int j = 0;
            vector<int> tmp;
            while(j<limit)
            {
                if((i>>j)&1)
                {
                    tmp.push_back(v_[j]);
                }
                ++j;
            }
            sort(tmp.begin(),tmp.end());
            result.push_back(tmp);
        }
        for(int i = 0;i<result.size();++i)
        {
            std::cout<<"[";
            for(int j = 0;j<result[i].size();++j)
            {
                std::cout<<result[i][j]<<" ";
            }
            std::cout<<"]"<<std::endl;
        }
    }
};
int main()
{
    vector<int> v{1,2,3};
    Solution::GetAllSubsets(v);
    return 0;
}
