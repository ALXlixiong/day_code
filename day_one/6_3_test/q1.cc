#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution{
private:
	string _str;
	vector<string> _v;
public:
	Solution(string str) :_str(str)
	{}

	void SplitStr()
	{
		string tmp = "";
		for (int i = 0; i < _str.size(); ++i)
		{
			if (_str[i] == '"')
			{
				++i;
				while (_str[i] != '"')
				{
					tmp += _str[i++];
				}
				if (tmp != "")
				{
					_v.push_back(tmp);
					tmp = "";
				}
			}
			else if (_str[i] == ' ')
			{
				if (tmp != "")
				{
					_v.push_back(tmp);
					tmp = "";
					continue;
				}
			}
			else
			{
				tmp += _str[i];
			}
		}
		_v.push_back(tmp);
		cout << _v.size() << endl;
		for (auto &e : _v)
			cout << e << endl;
	}
};

int main()
{
	string str = "";
	while (getline(cin, str))
	{
		Solution s(str);
		s.SplitStr();
	}
	return 0;
}
