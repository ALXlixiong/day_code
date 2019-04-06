class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int max = 0;
        //前i天最大收益=max(前i-1天最大收益，第i天的价格-前i-1天最小的价格)
        int min = prices[0];
        for(size_t i = 1;i<prices.size();++i)
        {
            if(prices[i]-min>max)
                max = prices[i]-min;
            if(prices[i]<min)
                min =prices[i];
        }
        return max;
    }
};
