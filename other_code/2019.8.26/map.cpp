#include <iostream>
#include <map>

struct cmp
{
	bool operator()(int left,int right)
	{
		return left > right;
	}
};

int main()
{
	//修改比较方式
	std::map<int, int,cmp> m1{ { 1, 1 }, { 3, 3 }, { 2, 2 } };
	m1.insert(std::make_pair(4, 4));

	/*for (auto it = m1.begin(); it != m1.end();)
	{
		auto tmp = it;
		++tmp;
		if (it->first == 3 || it->first == 2)
		{
			m1.erase(it);
			it = tmp;
		}
		else
			++it;
	}*/

	for (auto it = m1.begin(); it != m1.end();)
	{
		if (it->first == 3 || it->first == 2)
			m1.erase(it++);
		else
			++it;
	}
	for (auto it : m1)
		std::cout << it.first << " " << it.second << "\n";
	return 0;
}
