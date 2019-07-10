#include <iostream>
#include <vector>
#include <string>
int main()
{
	int n = 0;
	while (std::cin >> n)
	{
		std::vector<std::string> v(n);
		std::cin.clear();
		std::cin.ignore();
		for (int i = 0; i < n; ++i)
		{
			getline(std::cin, v[i]);
			if (v[i].find(',') != std::string::npos || v[i].find(" ") != std::string::npos)
			{
				std::string tmp = "\"";
				tmp += v[i];
				tmp += "\"";
				if (i != n - 1)
					std::cout << tmp << ",";
				else
					std::cout << tmp << std::endl;
			}
			else
			{
				if (i != n - 1)
					std::cout << v[i] << ",";
				else
					std::cout << v[i] << std::endl;
			}
		}
	}
	return 0;
}

