class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0;
        int end = height.size()-1;
        int ret = 0;
        while(begin<end)
        {
            int high = min(height[begin],height[end]);
            ret = max(ret,high*(end-begin));
            if(height[begin]<height[end])
                ++begin;
            else
                --end;
        }
        return ret;
    }
};
