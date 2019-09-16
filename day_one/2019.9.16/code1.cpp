#include <iostream>
#include <string>
class Solution
{
public:
	static void GetAllResult(int n)
	{
		if (n < 6)
			return;
		std::cout << "6=3+3" << std::endl;
		for (int i = 8; i <= n; ++i)
		{
			if (i % 2 == 0)
			{
				for (int j = 2; j <= i / 2; ++j)
				{
					if (JudgeIsPrimer(j) && JudgeIsPrimer(i - j))
					{
						std::string tmp = std::to_string(i);
						tmp += '=';
						tmp += std::to_string(j);
						tmp += '+';
						tmp += std::to_string(i - j);
						std::cout << tmp << std:: endl;
					}
				}
			}
		}
	}
private:
	static bool JudgeIsPrimer(int num)
	{
		for (int i = 2; i <= num / 2; ++i)
		{
			if (num%i == 0)
				return false;
		}
		return true;
	}
};

int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		Solution::GetAllResult(n);
	}
	return 0;
}
