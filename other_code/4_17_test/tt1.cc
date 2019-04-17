#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#if 0
class Solution {
public:
	static int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size()<3)
			return 0;
		sort(nums.begin(), nums.end());
		int begin = 0;
		int first = 0;
		int end = nums.size() - 1;
		int ret = INT_MAX;
		while (begin <= nums.size() - 3)
		{
			first = begin+1;
			end = nums.size() - 1;
			while (first<end)
			{
				int tmp = nums[begin] + nums[first] + nums[end];
				if (tmp>target)
				{
					if (abs(target-ret)>(tmp - target))
						ret = tmp;
					--end;
				}
				else if (tmp<target)
				{
					if (abs(target - ret)>target - tmp)
						ret = tmp;
					++first;
				}
				else
					return target;
			}
			++begin;
		}
		return ret;
	}
};
#endif
class Solution {
public:
	static vector<string> generateParenthesis(int n) {
		//递归
		//如果左括号还有，可以继续递归
		//只有左括号小于右括号才可以递归使用右括号
		vector<string> ret;
		generateParenthesis("", ret, n, n);
		return ret;
	}
	void generateParenthesis(string tmp, vector<string> &ret, int left, int right)
	{
		if (left == 0 && right == 0)
		{
			ret.push_back(tmp);
			return;
		}
		if (left>0)
			generateParenthesis(tmp + '(', ret, left - 1, right);
		if (left<right)
			generateParenthesis(tmp + ')', ret, left, right - 1);
	}
};

int main()
{
	string s1 = "eat";
	string s2 = "sea";
	vector<int> v{ 1,1,1,1 };
	string s = "25525511135";
	//int ret = Solution::threeSumClosest(v,-100);
	
	return 0;
}

