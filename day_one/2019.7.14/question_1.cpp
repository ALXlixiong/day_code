#include <iostream>
using namespace std;
#include <vector>
#include <map>
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> m_;
		for (int i = 0; i < nums.size(); ++i)
		{
			m_[nums[i]] = i;
		}

		vector<int> v;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (m_.count(target - nums[i]) > 0 && target - nums[i] != nums[i])
			{
				v.push_back(i);
				v.push_back(m_[target - nums[i]]);
				return v;
			}
		}
		return v;
	}
};
int main()
{
	Solution s;
	std::vector<int> v{ 3,2,4 };
	std::vector<int> ret = s.twoSum(v, 6);
	std::cout << ret[0] << " " << ret[1] << std::endl;
	return 0;
}

