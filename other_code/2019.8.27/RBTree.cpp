#include <iostream>
#include <vector>
#include "RBTree.hpp"

int main()
{
	RBTree<int> b;
	std::vector<int> v{ 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : v)
		b.Insert(e);
	return 0;
}
