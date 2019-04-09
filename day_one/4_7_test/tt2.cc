#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool IsContinuous( vector<int> numbers ) {
         //对数组进行排序
        //统计数组中0出现的次数
        //计算不连续间隔需要多少个0进行替换，判断是否顺子
        //如果数组中存在两个数相等，肯定不是顺子
        sort(numbers.begin(),numbers.end());
        int index = 0;
        int count = 0;
        for(int index = 0;index<numbers.size() && numbers[index] == 0;++index)
        {
            ++count;
        }
        if(count == 4)
            return true;
        //间隔个数标志
        int gap = 0;
        for(int i = index;i<numbers.size();++i)
        {
            if(i+1<numbers.size() && numbers[i] == numbers[i+1])
                return false;
            if(i+1<numbers.size() && numbers[i+1] != numbers[i]+1)
                gap += (numbers[i+1]-numbers[i]-1);
        }
        if(gap != count)
            return false;
        return true;
    }
};

int main()
{
  vector<int> v{0,3,2,6,4};
  Solution::IsContinuous(v);
  return 0;
}
