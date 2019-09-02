#include <iostream>
#include <vector>

class Solution
{
public:
	void GetResult(std::vector<int> &v, int &ret, int m, int k, int index,int &max)
	{
		if (m == 0 || k == 0)
			return ;
		for (int i = index; i<v.size(); ++i)
		{
			ret += v[i];
			GetResult(v, ret, m - 1, k - 1, index + 1,max);
			if (ret>max)
				max = ret;
			ret -= v[i];
		}
	}
};

int main()
{
	int len = 0;
	int m = 0;
	int n = 0;
	while (std::cin >> len >> m >> n)
	{
		std::vector<int> v(len, 0);
		for (int i = 0; i<len; ++i)
			std::cin >> v[i];
		Solution s;
		int ret = 0;
		int max = 0;
		s.GetResult(v, ret, m, n, 0, max);
		std::cout <<max<< std::endl;
	}
	return 0;
}
