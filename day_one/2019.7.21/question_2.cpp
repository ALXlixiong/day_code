#include <iostream>
#include <vector>
#include <algorithm>
bool cmp(const std::vector<int> &left, const std::vector<int> &right)
{
	return left[0] < right[0];
}
int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		int num = 0;
		std::vector<std::vector<int> > v(n, std::vector<int>(2, 0));
		for (int i = 0; i < n; ++i) {
			std::cin >> num;
			for (int j = 0; j < 2; ++j)
				std::cin >> v[i][j];
		}
		sort(v.begin(), v.end(), cmp);

		std::vector<int> tmp(n, 1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (v[j][1] <= v[i][1] && tmp[i]< tmp[j] + 1)
					tmp[i] = tmp[j] + 1;
			}
		}
		int max = 0;
		for (int i = 0; i < n; ++i)
		{
			if (tmp[i] > max)
				max = tmp[i];
		}
		std::cout << max << std::endl;
	}
	return 0;
}

