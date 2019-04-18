#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#if 0
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		//使用栈找到nums2中所有的key-value（key<value）
		stack<int> s;
		unordered_map<int, int> m;
		vector<int> ret;
		if (nums2.empty() || nums1.empty())
			return ret;

		for (int i = 0; i<nums2.size(); ++i)
		{
			while (!s.empty() && s.top()<nums2[i])
			{
				m.insert(pair<int, int>(s.top(), nums2[i]));
				s.pop();
			}
			if (s.empty() || nums2[i]<s.top())//在循环后面写
				s.push(nums2[i]);
		}

		for (int i = 0; i<nums1.size(); ++i)
		{
			auto tmp = m.find(nums1[i]);
			if (tmp != m.end())
				ret.push_back(tmp->second);
			else
				ret.push_back(-1);
		}
		return ret;
	}
};
#endif
#include <stack>
class Solution {
public:
	static bool find132pattern(vector<int>& nums) {
		if (nums.size()<3)
			return false;
		int begin = 0;
		int first = begin + 1;
		int end = nums.size() - 1;
		while (begin <= nums.size() - 3)
		{
			first = begin + 1;
			end = nums.size() - 1;
			if (begin>0)
			{
				if (nums[begin] >= nums[begin - 1])
				{
					++begin;
					continue;
				}
			}
			while (first<end)
			{
				if (nums[first] <= nums[begin] && nums[end] <= nums[begin])
				{
					++first;
					--end;
				}
				else if (nums[first] <= nums[begin])
				{
					++begin;
				}
				else if (nums[end] <= nums[begin])
				{
					--end;
				}
				else
				{
					stack<int> s;

					while (first <= end)
					{
						if (s.empty() || nums[first]>s.top()){
							s.push(nums[first]);
							++first;
						}
						else
							return true;
					}
				}
			}
			++begin;
		}
		return false;
	}
};
int main()
{
	vector<int> v{ 3, 1, 4, 2 };
	string s = "25525511135";
	bool ret = Solution::find132pattern(v);
	
	return 0;
}

