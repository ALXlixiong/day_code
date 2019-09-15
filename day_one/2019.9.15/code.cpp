#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	static int minDistance(string word1, string word2) {
		if (word1.empty())
			return word2.size();
		if (word2.empty())
			return word1.size();
		//删除多少步可以使得两个字符串相等，那么只需要找到他们的最长子序列
		int row = word1.size() + 1;
		int col = word2.size() + 1;
		std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
		for (int i = 1; i<row; ++i)
		{
			for (int j = 1; j<col; ++j)
			{
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return word1.size() + word2.size() - 2 * dp[row - 1][col - 1];
	}
};


int main()
{
	std::cout << Solution::minDistance("a", "b") << std::endl;
	return 0;
}
