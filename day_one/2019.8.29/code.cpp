#include <iostream>
#include <vector>

#if 0
#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		std::vector<int> v(n, 0);
		for (int i = 0; i < n; ++i)
			std::cin >> v[i];
		std::vector<int> tmp(n, 1);
		int max = 0;
		for (int i = 0; i < n; ++i)
		{
			int j = 0;
			for (; j < i; ++j)
			{
				if (v[j] < v[i] && tmp[j] >= tmp[i])
					tmp[i] = tmp[j] + 1;
			}
			if (tmp[i]>max)
				max = tmp[i];
		}
		std::cout << max << "\n";
	}
	return 0;
}
#endif

class Info
{
public:
	int p;
	int l;
};
int main()
{
	int person = 0;
	int lan = 0;
	int info = 0;
	while (std::cin >> person >> lan >> info)
	{
		std::vector<Info> v(info);
		for (int i = 0; i < info; ++i)
			std::cin >> v[i].p >> v[i].l;
		int ret = 0;
		for (int i = 1; i <= person; ++i)
		{
			bool flag = false;
			for (int j = 0; j < info; ++j)
			{
				if (i == v[i].p)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
				++ret;
		}
		//语言之间建立桥梁
		int tmp = 0;
		for (int i = 0; i < info; ++i)
		{
			bool flag = false;
			for (int j = 0; j < info; ++j)
			{
				if (i== j && v[i].p == v[j].p)
				{
					flag = true;
					break;
				}
			} 
			if (!flag)
				++tmp;
		}
		std::cout << (ret + tmp / 2) << std::endl;
	}
	return 0;
}
