#include<iostream>
using namespace std;
#include<vector>

void TestSort()
{

}
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	friend ostream& operator<<(ostream& _cout, Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};
#if 0
#include<algorithm>
int main()
{
	//TestSort();
	vector<int> v1;
	vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	sort(v2.begin(), v2.end());
	vector<int> v3(v2.begin(), v2.end());
	int arr[] = { 1, 2, 3, 4, 5 };
	vector<int> v4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	vector<int> v5(3);
	vector<int> v6(3, 1);
	vector<Date> v7(3, Date(2010, 1, 1));
	vector<Date> v8(v7);
	for (vector<int>::reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;
	for (auto it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;

	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;
	for (auto& e : v2)
		cout << e << " ";
	cout << endl;
	for (auto& e : v7)
		cout << e << " ";
	cout << endl;
	return 0;
}

#endif

int main()
{
	//TestSort();
	vector<int> v1;
	vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;

	v2.push_back(10);
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;
	v2.pop_back();
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;

	if (v2.end() == find(v2.begin(), v2.end(), 11))
		cout << "Ã»ÕÒµ½" << endl;
	v2.insert(v2.begin(), 0);
	v2.pop_back();
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;

	v2.erase(v2.begin() + 1, v2.begin() + 3);
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;
	v1.swap(v2);
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
		cout << *it << " ";
	cout << endl;
	return 0;
}