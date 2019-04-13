//#include <iostream>
//using namespace std;
//
//long long GetResult(int num)
//{
//	long long ret = 1;
//	while (num != 1)
//	{
//		ret *= num;
//		/*while (ret % 10 == 0)
//			ret /= 10;*/
//		--num;
//	}
//	return num;
//}
//
//int GetFirstNoZero(long long tmp)
//{
//	while (tmp)
//	{
//		int ret = tmp % 10;
//		if (ret != 0)
//			return ret;
//		tmp /= 10;
//	}
//	return 0;
//}
//int main()
//{
//	
//	return 0;
//}
//#include <iostream>
//using namespace std;
//
//long long GetResult(int num)
//{
//	long long ret = 1;
//	while (num != 1)
//	{
//		ret *= num;
//		if (ret % 10 == 0)
//			ret = ret / 10;
//		--num;
//	}
//	return num;
//}
//
//int GetFirstNoZero(long long tmp)
//{
//	while (tmp)
//	{
//		int ret = tmp % 10;
//		if (ret != 0)
//			return ret;
//		tmp /= 10;
//	}
//	return 0;
//}
//int main()
//{
//	int num = 0;
//	cin >> num;
//	long long tmp = GetResult(num);
//	int ret = GetFirstNoZero(tmp);
//	cout << ret << endl;
//	return 0;
//}



#include <iostream>
using namespace std;
#include <vector>
#include <string>
int main()
{
	string s1 = "";
	string s2 = "";
	cin >> s1;
	cin >> s2;
	int count = 0;
	//相等，只需要修改
	if (s1.size() == s1.size())
	{
		for (size_t i = 0; i < s1.size(); ++i)
		{
			if (s1[i] != s2[i])
				++count;
		}
		return count;
	}
	//删除
	if (s1.size() < s2.size())
	{
		//s2中多于的字符，或者s1中没有的字符删除
		vector<int> v1(256);
		vector<int> v2(256);
		for (size_t i = 0; i < s1.size(); ++i)
			v1[s1[i]]++;
		for (size_t i = 0; i < s2.size(); ++i)
			v2[s2[i]]++;
		//删除不在s1中的字符，并且需要判断s1和s2的长度是否相等，然后在修改
		int len = s2.size();
		for (int i = 0; i < 256; ++i)
		{
			if (s1.size() != len && v1[i] == 0 && v2[i] != 0)
			{
				++count;
				v2[i]--;
				len--;
			}
		}
		//删完了，但是s1和s2长度还是不相等，那么删除含有相同元素多余的
		for (int i = 0; i < 256; ++i)
		{
			if (s1.size() == len)
				break;
			while (v1[i] < v2[i])
			{
				v2[i]--;
				++count;
				len--;
			}
		}
		for (size_t i = 0; i < s1.size(); ++i)
		{

		}
	}
	return 0;
}
