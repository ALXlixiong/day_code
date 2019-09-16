#include <iostream>
#include <string>
#include <vector>
#include <set>
class Solution
{
public:
	 void GetAllResult(int num,int sum,std::string tmp)
	{
		if (sum == num)
		{
			std::string index(tmp.begin(), tmp.end() - 1);
			if (!JudgeIsExist(index))
				std::cout << index << std::endl;
			return;
		}
		if (sum > num)
			return;
		for (int i = 1; i < num; ++i)
		{
			GetAllResult(num, sum + i, tmp + std::to_string(i) + '+');
		}
	}
private:
	bool JudgeIsExist(std::string index)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].size() == index.size())
			{
				std::set<int> s1;
				std::set<int> s2;
				for (int j = 0; j < v[i].size(); ++j)
				{
					s1.insert(v[i][j]);
				}
				for (int j = 0; j < index.size(); ++j)
				{
					s2.insert(index[j]);
				}
				if (s1.size() == s2.size())
				{
					auto begin1 = s1.begin();
					auto begin2 = s2.begin();
					for (; begin1 != s1.end(), begin2 != s2.end(); ++begin1, ++begin2)
					{
						if (*begin1 != *begin2)
						{
							v.push_back(index);
							return false;
						}

					}
					return true;
				}
			}
		}
		v.push_back(index);
		return false;
	}
private:
	std::vector<std::string> v;
};

int main()
{
	int num = 0;
	while (std::cin >> num)
	{
		Solution s;
		s.GetAllResult(num, 0, "");
		std::cout << num << std::endl;
	}
	
	return 0;
}
