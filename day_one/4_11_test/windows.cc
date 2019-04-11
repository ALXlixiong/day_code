#include <iostream>
using namespace std;
#include <queue>
#include <vector>
class Solution {
public:
	static vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		//通过一个队列来控制窗口的大小
		queue<int> q;
		if (num.empty() || size == 0)
			return num;
		int index = 0;
		vector<int> ret;
		while (index <= num.size() - size)
		{
			for (int i = index; i<num.size() && i<index + size; ++i)
				q.push(num[i]);
			if (q.size() != size)
				break;
			int max = 0;
			while (!q.empty())
			{
				max = max>q.front() ? max : q.front();
				q.pop();
			}
			ret.push_back(max);
			++index;
		}
		return ret;
	}
};

int main()
{
	vector<int> v{ 1, 3, 5, 7, 9, 11, 13, 15 };
	auto ret = Solution::maxInWindows(v, 4);
	for (auto& e : ret)
		cout << e << endl;
	return 0;
}
