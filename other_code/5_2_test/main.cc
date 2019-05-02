#include "vector.hpp"
int main()
{
	bit::vector<int> v1(10, 1);
	bit::vector<int> v2;
	v2 = v1;
	bit::vector<int> v3(v2);
	int arr[] = { 1, 2, 3, 4, 5 };
	bit::vector<int> v4(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto& e : v4)
		cout << e <<" ";
	cout << endl;
	cout << v4[4] << endl;
	//cout << v4[5] << endl;
	cout << v4.at(4) << endl;
	cout << v4.at(5) << endl;
	cout << v4.back() << endl;
	v4.resize(20);
	v4.reserve(30);

	/*v4.erase(v4.begin());
	v4.insert(v4.begin(), 1);
	v4.insert(v4.begin(), 0);*/
	//v4.erase(v4.end());
	//v4.insert(v4.end(), 5);
	return 0;
}
