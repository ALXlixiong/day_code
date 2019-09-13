#include <iostream>
#include <string>
#include <stdio.h>
class Solution
{
public:
	static void GetResult(std::string src, std::string dest)
	{
		if (!JudgeIsLegal(dest) || !JudgeIsLegal(src))
		{
			std::cout << -1 << std::endl;
			return;
		}
		int count = 0;
		for (int i = 0; i < src.size(); ++i)
		{
			if (src[i] != dest[i])
			{
				src[i] = dest[i];
				if (JudgeIsLegal(src))
					++count;
				else
				{
					std::cout << -1 << std::endl;
					return;
				}
			}
		}
		std::cout << count << std::endl;
	}
private:
	static bool JudgeIsLegal(std::string dest)
	{
		if (dest.size() != 6)
			return false;
		for (int i = 0; i < dest.size(); ++i)
		{
			if (dest[i]<'0' || dest[i]>'9')
				return false;

		}
		int tmp = atoi(dest.c_str());
		std::cout << tmp << std::endl;
		for (int i = 2; i <= tmp / 2; ++i)
		{
			if (tmp%i == 0)
				return false;
		}
		return true;
	}
};
int main()
{
	std::string src;
	std::string dest;
	int count = 0;

	while (std::cin >> count)
	{
		while (count--)
		{
			std::cin >> src >> dest;
			Solution::GetResult(src, dest);
		}
	}
	return 0;
}
