#include <iostream>
#include <vector>
#include <string>
class Solution
{
public:
	static int GetResult(std::vector<std::string> &v,int row,int col)
	{
		if (row < 3 || col<3)
			return 0;
		int count = 0;
		for (int i = 1; i < row - 1; ++i)
		{
			for (int j = 1; j < col - 1; ++j)
			{
				if (v[i][j] == '1' && v[i - 1][j] == '1' && v[i + 1][j] == '1' && v[i][j - 1] == '1' && v[i][j + 1] == '1')
					++count;
			}
		}
		return count;
	}
};
/*
01000
11100
11101
11111
00101
*/

int main()
{
	int row = 0;
	int col = 0;
	while (std::cin >> row >> col)
	{
		std::vector<std::string> v(row, "");
		for (int i = 0; i < row; ++i)
			std::cin >> v[i];
		std::cout << Solution::GetResult(v,row,col) << std::endl;
	}
	return 0;
}
