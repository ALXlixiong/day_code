#include <iostream>
#include <string>
#include <algorithm>
#if 0
int main()
{
	std::string src = "i am a student";
	std::reverse(src.begin(), src.end());
	auto pos = src.find(" ");
	size_t tmp = 0;
	while (pos != std::string::npos)
	{
		std::reverse(src.begin()+tmp, src.begin() + pos);
		tmp = pos+1;
		pos = src.find(" ", pos + 1);
	}
	std::reverse(src.begin() + tmp, src.end());
	return 0;
}
#endif

void swap(char &begin, char &end)
{
	auto tmp = begin;
	begin = end;
	end = tmp;
}
int main()
{
	std::string src = "i am a student";
	//整体翻转
	auto begin = src.begin();
	auto end = src.end() - 1;
	while (begin <= end)
	{
		swap(*begin, *end);
		++begin; --end;
	}
	//部分翻转
	begin = src.begin();
	end = src.begin();
	while (end != src.end())
	{
		while (*end != ' ')
			++end;
		auto tmp = end - 1;
		while (begin <= tmp)
		{
			swap(*begin, *tmp);
			++begin; --tmp;
		}
		begin = end + 1;
		++end;
	}
	/*--end;
	while (begin <= end)
	{
		swap(*begin, *end);
		++begin; --end;
	}*/
	return 0;
}
