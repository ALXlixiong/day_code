#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
	static bool GetResult(std::string str)
	{
		if (str.empty())
			return true;
		std::stack<char> s;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == '[' || str[i] == '(' || str[i] == '{')
			{
				s.push(str[i]);
			}
			else if (str[i] == ']' || str[i] == ')' || str[i] == '}')
			{
				if (s.empty())
					return false;
				char top = s.top();
				s.pop();
				if ((str[i] == ']' && top != '[') || (str[i] == ')' && top != '(') || (str[i] == '}' && top != '{'))
					return false;
			}
		}
		if (s.empty())
			return true;
		return false;
	}
};

int main()
{
	std::string str = "";
	while (std::cin >> str)
	{
		std::cout << (Solution::GetResult(str) ? "true" : "false") << std::endl;
	}
	return 0;
}



