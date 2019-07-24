#include <iostream>
#include <vector>

class Solution
{
    public:
        static int GetResult(std::vector<std::vector<int> > v,int row,int col)
        {
            std::vector<std::vector<int> > dp(row,std::vector<int>(col,0));
            dp[0][0] = 1;
            for(int i = 0;i<row;++i)
            {
                for(int j = 0;j<col;++j)
                {
                    if(i == 0 && j == 0)
                        continue;
                    else if(v[i][j] == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i-1][j]*(j == (col-1)?1:0.5)+dp[i][j-1]*(i == (row-1)?1:0.5);
                }
            }
            return dp[row-1][col-1];
        }
};

int main()
{
    int row = 0;
    int col = 0;
    int line = 0;
    while(std::cin>>row>>col>>line)
    {
        std::vector<std::vector<int> > v(row,std::vector<int>(col,0));
        int x = 0;
        int y = 0;
        for(int i = 0;i<line;++i)
        {
            std::cin>>x>>y;
            v[x][y] = 1;
        }
        std::cout<<Solution::GetResult(v,row,col)<<std::endl;
    }
    return 0;
}
