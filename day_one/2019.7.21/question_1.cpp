lude <iostream>
#include <vector>


long long max = 0;

void Func(std::vector<int> v, int num, int k, int d,long long ret, int index, int preindex)
{
	if (index >= v.size() || num == k)
	{
		max = max > ret ? max : ret;
		return;
	}

	//如果选择
	if ((index - preindex) <= d) {
		preindex = index;
		Func(v, num + 1, k, d, ret*v[index], index + 1, preindex);
	}
	//如果不选择
	if ((index - preindex) <= d)
	{
		preindex = index;
		Func(v, num, k, d, ret, index + 1, preindex);
	}
}

int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		std::vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
			std::cin >> v[i];
		int k = 0;
		int d = 0;
		std::cin >> k >> d;

		Func(v, 0, k, d, 1ll, 0, 0);
		std::cout << max << std::endl;
		max = 0ll;
	}
	return 0;
}

