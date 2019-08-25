int BinaryFind(std::vector<int> &v, int val)
{
	int begin = 0;
	int end = v.size();
	//[ )
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (v[mid] == val)
			return mid;
		else if (v[mid] > val)
			end = mid;
		else
			begin = mid + 1;
	}
	return -1;
}

int main()
{
	std::vector<int> v{ 1, 3, 4, 5, 7, 7, 9, 23 };
	std::cout << BinaryFind(v, 10) << "\n";
	return 0;
}
