class Solution {
public:
    int minDistance(string word1, string word2) {
        //特殊情况
        if(word1.empty())
            return word2.size();
        if(word2.empty())
            return word1.size();
        
        int m = word2.size();//行
        int n = word1.size();//列
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = word1[0] == word2[0]?0:1;
        //初始化第一行
        bool flag;
        bool tmp;
        if(word1[0] == word2[0])
            tmp = false;
        else
            tmp = true;
        flag = tmp;
        for(int i = 1;i<n;++i)
        {
            if(word1[i] == word2[0])
            {
                if(flag == true)
                {
                    dp[0][i] = dp[0][i-1];
                    flag = false;
                }
                else 
                {
                    dp[0][i] = dp[0][i-1] + 1;
                }
            }
            else
                dp[0][i] = dp[0][i-1] + 1;
        }
        //初始化第一列
        flag = tmp;
        for(int i = 1;i<m;++i)
        {
            if(word2[i] == word1[0])
            {
                if(flag == true)
                {
                    dp[i][0] = dp[i-1][0];
                    flag = false;
                }
                else
                {
                    dp[i][0] = dp[i-1][0] +1;
                }
            }
            else
                dp[i][0] = dp[i-1][0] + 1;
        }
        
        for(int i = 1;i<m;++i)
        {
            for(int j = 1;j<n;++j)
            {
                if(word2[i] == word1[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }
        return dp[m-1][n-1];
    }
};

