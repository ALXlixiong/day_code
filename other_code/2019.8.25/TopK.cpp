#include <iostream>
#include <vector>
#include <algorithm>

void AdjustDown(std::vector<int> &top, int parent)
{
	int min_child = parent * 2 + 1;
	while (min_child < top.size())
	{
		if (min_child + 1 < top.size() && top[min_child] > top[min_child + 1])
			min_child += 1;
		if (top[parent]>top[min_child])
			std::swap(top[parent], top[min_child]);
		else
			break;
		parent = min_child;
		min_child = parent * 2 + 1;
	}
}

void TopKHeap(std::vector<int> &v, int k)
{
	std::vector<int> top;
	for (int i = 0; i < k; ++i)
		top.push_back(v[i]);
	int root = (k - 2) / 2;
	for (; root >= 0; --root)
		AdjustDown(top, root);
	for (int i = k; i < v.size(); ++i)
	{
		if (v[i]>top[0])
		{
			top[0] = v[i];
			AdjustDown(top, 0);
		}
	}
	for (int i = 0; i < top.size(); ++i)
		std::cout << top[i] << " ";
	std::cout << "\n";
}

int main()
{
	std::vector<int> v{ 3, 1, 5, 4, 0, 9, 5, 7, 4, 9, 12, 5, 4 };
	TopKHeap(v, 5);
	std::sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << "\n";
	return 0;
}
