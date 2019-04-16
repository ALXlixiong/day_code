#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#if 0
class Solution {
public:
	static int minimumDeleteSum(string s1, string s2) {
		if (s1.empty())
			return s2.size();
		if (s2.empty())
			return s1.size();
		int row = s2.size();
		int col = s1.size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
		//初始化第一行
		for (int i = 1; i <= col; ++i)
		{
			dp[0][i] = dp[0][i - 1] + s1[i - 1];
		}
		//初始化第一列
		for (int i = 1; i <= row; ++i)
		{
			dp[i][0] = dp[i - 1][0] + s2[i - 1];
		}
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
			{
				if (s2[i-1] == s1[j-1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + s1[j - 1] + s2[i - 1], min(dp[i - 1][j] + s2[i - 1], dp[i][j - 1] + s1[j - 1]));
			}
		}
		Print(dp);
		return dp[row][col];
	}
	static void Print(vector<vector<int>> v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			for (size_t j = 0; j < v[0].size(); ++j)
				printf("%4d", v[i][j]);
			cout << endl;
		}
		
	}
};


class Solution {
public:
	static int numberOfArithmeticSlices(vector<int>& A) {
		int row = A.size();
		if (row<3)
			return 0;
		int gap = row / 3 + 1;
		vector<vector<int>> v(row, vector<int>(gap, 0));
		while (gap--)
		{
			int tmp = gap + 1;
			int col = 0;
			for (int i = 0; i<A.size(); ++i)
			{
				if (i>=(2 * tmp) && A[i] - A[i - tmp] == A[i - tmp] - A[i - tmp * 2])
					v[i][tmp-1] = v[i - 1][tmp-1] + 1;
				else
					v[i][tmp-1] = 0;
			}
		}
		int ret = 0;
		for (int i = 0; i<v.size(); ++i)
		{
			for (int j = 0; j<v[0].size(); ++j)
				ret += v[i][j];
		}
		return ret;
	}
};
#endif
#if 0
class Solution {
public:
	static int maxArea(vector<int>& height) {
		if (height.size()<2)
			return 0;
		int max_ret = 0;
		int begin = 0;
		int end = height.size() - 1;
		while (begin<end)
		{
			int ret = min(height[begin], height[end])*(end - begin);
			max_ret = max_ret>ret ? max_ret : ret;
			if (begin <= end)
				++begin;
			else
				--end;
		}
		return max_ret;
	}
};
#endif
#if 0
class Solution {
public:
	static int trap(vector<int> height) {
		if (height.empty())
			return 0;
		

		int maxIndex = 0;
		for (int i = 0; i< height.size(); i++){
			if (height[maxIndex] < height[i]){
				maxIndex = i;
			}
		}
		int cur = 0;
		int sum = 0;

		for (int i = 0; i<maxIndex; i++){
			if (height[i] > cur){
				cur = height[i];
			}
			sum += cur;
		}

		sum += height[maxIndex];

		cur = 0;
		for (int i = height.size() - 1; i > maxIndex; i--){
			if (height[i] > cur){
				cur = height[i];
			}
			sum += cur;
		}

		for (int i = 0; i< height.size(); i++){
			sum -= height[i];
		}
		return sum;


	}
};
#endif
#if 0
class Solution {
public:
	static int trap(vector<int>& height) {
		if (height.empty())
			return 0;
		//找峰值下标
		int maxindex = 0;
		for (int i = 0; i<height.size(); ++i)
		{
			if (height[maxindex]<height[i])
				maxindex = i;
		}
		//蓝色面积 = （黑色面积+蓝色面积）-黑色面积
		//1. 求 黑色面积+蓝色面积 = sum
		int sum = 0;
		int cur = height[0];//记录当前峰值
		for (int i = 0; i<maxindex; ++i)
		{
			if (height[i]>cur)
				cur = height[i];
			sum += cur;
		}
		sum += height[maxindex];
		cur = height[height.size() - 1];
		for (int i = height.size() - 1; i>maxindex; --i)
		{
			if (height[i]>cur)
				cur = height[i];
			sum += cur;
		}

		//求蓝色面积 = sum - 黑色面积
		for (int i = 0; i<height.size(); ++i)
		{
			sum -= height[i];
		}
		return sum;
	}
};
#endif
#if 0
class Solution {
public:
	static vector<string> restoreIpAddresses(string s) {
		//递归
		//四次递归
		//2
		//25
		//255
		vector<string> ret;
		string tmpstr = "";
		restoreIpAddressesR(s, 4, tmpstr, ret);
		return ret;
	}
	static void restoreIpAddressesR(string s, int k, string tmpstr, vector<string> &ret)
	{
		if (k == 0)
		{
			if (s.empty())
			{
				ret.push_back(tmpstr);
			}
			return;
		}

		for (int i = 1; i <= 3; i++)
		{
			if (i <= s.size() && IsValid(s.substr(0, i)))
			{
				
				if (k != 1)
					restoreIpAddressesR(s.substr(i), k - 1, tmpstr+s.substr(0, i)+'.', ret);
				else
					restoreIpAddressesR(s.substr(i), k - 1, tmpstr + s.substr(0, i), ret);

			}
		}
	}
	static bool IsValid(string s)
	{
		if (atoi(s.c_str()) <= 255 && atoi(s.c_str()) >= 0)
			return true;
		return false;
	}
};
#endif
class Solution {
public:
	static string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return "";
		string ret = "";
		for (size_t i = 0; i<strs[0].size(); ++i)
		{
			for (size_t j = 1; j<strs.size(); ++j)
			{
				if (strs[j].size()<i || strs[j][i] != strs[0][i])
					return ret;
			}
			ret += strs[0][i];
		}
		return ret;
	}
};

int main()
{
	string s1 = "eat";
	string s2 = "sea";
	vector<int> v{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	string s = "25525511135";
	string ret = Solution::longestCommonPrefix(s);
	
	return 0;
}

