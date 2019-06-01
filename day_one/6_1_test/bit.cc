#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#include <cmath>
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		int ret = 0;
		for (int index1 = 0; index1<32; ++index1)
		{
			if (index1 >= j && index1 <= i)
			{
				int bit = (m >> (index1 - j)) & 1;
				ret += bit*pow(2, index1);
			}
			else
			{
				int bit = (n >> index1) & 1;
				ret += bit*pow(2, index1);
			}
		}
		return ret;
	}
};
int main()
{
	BinInsert b;
	int ret = b.binInsert(1024, 19, 2, 6);
	return 0;
}



