#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
class Solution
{
public:
	static void GetResult(std::string str)
	{
		std::vector<std::string> v;
		std::string tmp = "";
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] != ',')
				tmp += str[i];
			else
			{
				v.push_back(tmp);
				tmp = "";
			}
		}
		v.push_back(tmp);
		std::sort(v.begin(), v.end());
		for (int i = 0; i < v.size() - 1; ++i)
		{
			std::cout << v[i] << ",";
		}
		std::cout << v[v.size() - 1] << std::endl;
	}
};


int main()
{
	std::string str = "";
	while (std::cin >> str)
	{
		Solution::GetResult(str);
	}
	return 0;
}
