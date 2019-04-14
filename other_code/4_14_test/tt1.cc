#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
class Solution {
public:
	static int minDistance(string word1, string word2) {
		//本题其实由最长公共子序列变化而来
		if (word1.empty())
			return word2.size();
		if (word2.empty())
			return word1.size();
		int n = word1.size();//列
		int m = word2.size();//行
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

		for (int i = 1; i<=m; ++i)
		{
			for (int j = 1; j<=n; ++j)
			{
				if (word2[i-1] == word1[j-1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
				{
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		return word1.size() + word2.size() - 2 * dp[m - 1][n - 1];
	}
};
int main()
{
	string s1 = "a";
	string s2 = "b";
	Solution::minDistance(s1,s2);
	return 0;
}

