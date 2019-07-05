/*求子集问题，要求每个子集里面的元素是有序的*/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    private:
        vector<int> v_;
    public:
        Solution(vector<int> v):v_(v)
    {}
        void GetAllSubsets()
        {
            sort(v_.begin(),v_.end());
            vector<vector<int> > result;
            vector<int> subset;
            _GetAllSubsets(result,subset,0,0);
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
    private:
        void _GetAllSubsets(vector<vector<int> > &result,vector<int> subset,int index,int level)
        {
            if(level == v_.size())
            {
                result.push_back(subset);
                return;
            }
            //不加入子集
            _GetAllSubsets(result,subset,index+1,level+1);
            //加入子集
            subset.push_back(v_[index]);
            _GetAllSubsets(result,subset,index+1,level+1);
        }
};

int main()
{
    vector<int> v{1,2,3};
    Solution s(v);
    s.GetAllSubsets();
    return 0;
}
