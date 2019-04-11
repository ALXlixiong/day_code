#include <iostream>
using namespace std;
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
	static int longestPalindrome(string s) {
		int maxlen = 0;
		vector<int> v(256);
		for (size_t i = 0; i<s.size(); ++i)
		{
			v[s[i]]++;
		}
		//找最大奇数字符
		char flag = '0';
		for (size_t i = 0; i<s.size(); ++i)
		{
			if (v[s[i]] % 2 == 1)
				flag = v[flag]>v[s[i]] ? flag : s[i];
		}
		//计算最大长度
		//最大的奇数直接加，偶数直接加，其余奇数减一之后加
		for (int i = 0; i < 256;++i)
		{
			if (v[i] % 2 == 0)
				maxlen += v[i];
			else if (i != flag)
				maxlen += (v[i] - 1);
			else
				maxlen += v[i];
		}
		return maxlen;
	}
};
int main()
{
	int count = Solution::longestPalindrome("abccccdd");
	cout << count << endl;
	return 0;
}

