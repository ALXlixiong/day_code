#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &v, int left, int div, int right, vector<int> &tmp)
{
	int start1 = left;
	int start2 = div;
	int index = left;
	while (start1<div && start2<right)
	{
		if (v[start1] <= v[start2]){
			tmp[index++] = v[start1++];
		}
		else {
			tmp[index++] = v[start2++];
		}
	}
	while (start1<div){
		tmp[index++] = v[start1++];
	}
	while (start2<right)
	{
		tmp[index++] = v[start2++];
	}
	for (int i = left; i<right; ++i)
		v[i] = tmp[i];
}

void _MergeSort(vector<int> &v, int left, int right, vector<int> &tmp)
{
	if (left<right-1)
	{
		int div = left + ((right - left) >> 1);
		_MergeSort(v, left, div, tmp);
		_MergeSort(v, div, right, tmp);
		Merge(v, left, div, right, tmp);
	}
}

void MergeSort(vector<int>& v)
{
	vector<int> tmp(v.size());
	_MergeSort(v, 0, v.size(), tmp);
}

int main()
{
	vector<int> v{ 3, 2, 5, 6, 1, 8, 0, 4, 6 };
	MergeSort(v);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	return 0;
}
