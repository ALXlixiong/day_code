/*包含所有常见C语言字符串函数实现*/
#include <iostream>
#if 0
//正常方式
size_t my_strlen(const char *src)
{
	if (src == nullptr)
		return 0;
	char *tmp = (char *)src;
	size_t count = 0;
	while (*tmp++ != '\0')
	{
		++count;
	}
	return count;
}
#endif
#if 0
//递归
size_t my_strlen(const char *src)
{
	if (src == nullptr)
		return 0;
	if (*src == '\0')
		return 0;
	return 1 + my_strlen(src + 1);
}
#endif

//指针减
size_t my_strlen(const char *src)
{
	if (src == nullptr)
		return 0;
	const char *end = src;
	while (*end++ != '\0');
	return end - src-1;
}

char *my_strcpy(char *dest, const char *src)
{
	if (!dest || !src)
		return dest;
	char *begin = dest;
	while (*dest++ = *src++);
	return begin;
}

char *my_strcat(char *dest, const char *src)
{
	if (!dest || !src)
		return dest;
	char *begin = dest;
	while (*dest)
		++dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++; src++;
	}
	*dest = '\0';
	return begin;
}

const char *my_strstr(const char *str, const char *sub_str)
{
	if (!sub_str || !str)
		return str;
	while (*str)
	{
		const char *tmp1 = str;
		const char *tmp2 = sub_str;
		while (*tmp1 && *tmp2 && *tmp1 == *tmp2)
		{
			++tmp1; ++tmp2;
		}
		if (*tmp2 == '\0')
			return str;
		else if (*tmp1 == '\0')
			return nullptr;
		++str;
	}
	return nullptr;
}
#if 0
int my_strcmp(const char *str1, const char *str2)
{
	if (str1 == nullptr && str2 == nullptr)
		return 0;
	else if (str1 == nullptr && str2 != nullptr)
		return -1;
	else if (str1 != nullptr && str2 == nullptr)
		return 1;
	else
	{
		while (*str1 || *str2)
		{
			if (*str1 > *str2)
				return 1;
			else if (*str1 < *str2)
				return -1;
			else
			{
				++str1; ++str2;
			}
		}
		return 0;
	}
}
#endif

int my_strcmp(const char *str1, const char *str2)
{
	int ret = 0;
	while (!(ret = (*str1 - *str2)) && *str2)/*这里的*str2也可以换成*str1，主要防止两个字符串相等*/
	{
		++str1; ++str2;
	}
	if (ret > 0)
		return 1;
	else if (ret < 0)
		return -1;
	else
		return 0;
}
#include <assert.h>
void *my_memcpy(void *dest, const void *src, size_t size)
{
	assert(dest && src && size >= 0);
	char *d = (char *)dest;
	char *s = (char *)src;
	while (size--)
	{
		*d = *s;
		++d; ++s;
	}
	return dest;
}

void *my_memmove(void *dest, const void *src, int size)
{
	assert(dest && src && size >= 0);
	char *d = (char *)dest;
	char *s = (char *)src;
	if (d > s && d < s + size)
	{
		//内存重叠,从右向左拷贝数据
		d = d + size - 1;
		s = s + size - 1;
		while (size--)
			*d-- = *s--;
	}
	else
	{
		while (size--)
			*d++ = *s++;
	}
	return dest;
}

int main()
{
	char str1[] = "abcdefgh";
	my_memcpy(str1 + 3, str1, 4);
	//my_memmove(str1 + 3, str1, 4);
	return 0;
}
