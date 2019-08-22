#include <iostream>
#include <vector>

void Swap(int &left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

void BubbleSort(std::vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		bool flag = false;
		for (int j = 0; j < v.size() - i - 1; ++j)
		{
			if (v[j]>v[j + 1]){
				Swap(v[j], v[j+1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

void SelectSort(std::vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		int maxPos = 0;
		for (int j = 0; j < v.size() - i; ++j)
		{
			if (v[j]>v[maxPos])
				maxPos = j;
		}
		if (maxPos != v.size() - i-1)
			Swap(v[maxPos], v[v.size() - i-1]);
	}
}

void SelectSortTwo(std::vector<int> &v)
{
	int begin = 0;
	int end = v.size() - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (v[i]>v[max])
				max = i;
			if (v[i] < v[min])
				min = i;
		}
		Swap(v[begin], v[min]);
		if (max == begin)
			max = min;
		Swap(v[end], v[max]);
		++begin;
		--end;
	}
}


void InsertSort(std::vector<int> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		int end = i-1;
		while (end >= 0)
		{
			if (v[end]>v[end + 1]){
				Swap(v[end], v[end + 1]);
				--end;
			}
			else
				break;
		}
	}
}

void ShellSort(std::vector<int> &v)
{
	int gap = v.size() / 3 + 1;
	while (1)
	{
		for (int i = gap; i < v.size(); i = i + gap)
		{
			int end = i - gap;
			while (end >= 0)
			{
				if (v[end]>v[end + gap]){
					Swap(v[end], v[end + gap]);
					end = end - gap;
				}
				else
					break;
			}
		}
		if (gap == 1)
			break;
		gap = gap / 3 + 1;
	}
}

void HeapAdjustDown(std::vector<int> &v, int parent,int size)
{
	int max_child = parent * 2 + 1;
	while (max_child < size)
	{
		if (max_child + 1 < size && v[max_child] > v[max_child + 1])
			max_child += 1;
		if (v[parent] > v[max_child])
			Swap(v[parent], v[max_child]);
		else
			break;
		parent = max_child;
		max_child = parent * 2 + 1;
	}
}

void HeapSort(std::vector<int> &v)
{
	int root = (v.size() - 2) / 2;
	for (; root >= 0; --root)
	{
		HeapAdjustDown(v, root,v.size());
	}
	int end = v.size();
	while (end > 0)
	{
		Swap(v[0], v[end - 1]);
		HeapAdjustDown(v, 0, end - 1);
		--end;
	}
}

int Partion_1(std::vector<int> &v, int left, int right)
{
	//[ )
	//hrone
	int begin = left;
	int end = right - 1;

	while (begin < end)
	{
		while (begin < end && v[begin] <= v[right - 1])
			++begin;
		while (begin < end && v[end] >= v[right - 1])
			--end;
		if (begin < end)
			Swap(v[begin], v[end]);
	}
	if (begin != right - 1)
		Swap(v[begin], v[right - 1]);
	return begin;
}

void _QuickSort(std::vector<int> &v, int left, int right)
{
	if (left < right)    //[ )
	{
		int mid = Partion_1(v, left, right);
		_QuickSort(v, left, mid);
		_QuickSort(v,mid+1, right);
	}
}


void QuickSort(std::vector<int> &v)
{
	_QuickSort(v, 0, v.size());
}

void Merge(std::vector<int> &v, int left, int mid, int right)
{
	int begin1 = left;
	int begin2 = mid;
	int *arr = new int[v.size()];
	int index = left;
	while (begin1 < mid && begin2 < right)
	{
		if (v[begin1]>v[begin2])
			arr[index++] = v[begin2++];
		else
			arr[index++] = v[begin1++];
	}

	while (begin1 < mid)
		arr[index++] = v[begin1++];
	while (begin2 < right)
		arr[index++] = v[begin2++];
	for (int i = left; i < right; ++i)
		v[i] = arr[i];
	delete[] arr;
}

void _MergeSort(std::vector<int> &v, int left, int right)
{
	//[ )
	if ((right-left)>1)
	{
		int div = left + ((right - left) >> 1);
		_MergeSort(v, left, div);
		_MergeSort(v, div, right);
		Merge(v, left, div, right);
	}
}

void MergeSort(std::vector<int> &v)
{
	_MergeSort(v, 0, v.size());
}


int main()
{
	std::vector<int> v1{ 3, 2, 1, 5, 4, 9, 0, 3, 4, 7 };
	std::vector<int> v2{ 9, 1, 2, 3, 4, 5, 6, 7, 0, 3 };
	//BubbleSort(v1);
	//SelectSort(v1);
	//SelectSortTwo(v1);
	//SelectSortTwo(v2);
	//InsertSort(v1);
	//InsertSort(v2);
	//ShellSort(v1);
	//ShellSort(v2);
	//HeapSort(v1);
	//HeapSort(v2);
	//QuickSort(v1);
	MergeSort(v1);
	MergeSort(v2);
	return 0;
}


