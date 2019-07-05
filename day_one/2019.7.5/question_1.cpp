#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
class Solution {
    public:
        /**
         *   *  正数数组中的最小不可组成和
         *       *  输入：正数数组arr
         *           *  返回：正数数组中的最小不可组成和
         *               */
        int getFirstUnFormedNum(vector<int> arr, int len) {
            sort(arr.begin(),arr.end());
            int min = arr[0];
            int max = 0;
            for(int i = 0;i<arr.size();++i)
                max += arr[i];
            vector<vector<int> > result;
            GetAllSubsets(arr,result);
            vector<int> map;
            for(int i = 0;i<result.size();++i)
            {
                int tmp = 0;
                for(int j = 0;j<result[i].size();++j)
                {
                    tmp += result[i][j];
                }
                if(result[i].size() != 0)
                    map.push_back(tmp);
            }
            //for(int i = 0;i<map.size();++i)
            //    std::cout<<map[i]<<" ";
            //std::cout<<std::endl;
            for(int i = min;i<=max;++i)
            {
                bool flag = false;
                for(int j = 0;j<map.size();++j)
                {
                    if(i == map[j])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    return i;
                }
            }
            return max+1;
        }
    private:
        void GetAllSubsets(vector<int> arr,vector<vector<int> > &result)
        {
            vector<int> subset;
            _GetAllSubsets(arr,result,subset,0,0);
        }
    private:
        void _GetAllSubsets(vector<int> arr,vector<vector<int> > &result,vector<int> subset,int index,int level)
        {
            if(level == arr.size())
            {
                result.push_back(subset);
                return;
            }
            //不加入子集
            _GetAllSubsets(arr,result,subset,index+1,level+1);
            //加入子集
            subset.push_back(arr[index]);
            _GetAllSubsets(arr,result,subset,index+1,level+1);
        }

};

int main()
{
    vector<int> v{3,2,4};
    Solution s;
    std::cout<<s.getFirstUnFormedNum(v,3)<<std::endl;
    return 0;
}
