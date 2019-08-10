#include <iostream>
#include <memory>
#include <thread>
std::shared_ptr<int> p1(new int(1000));

void JudgeIsThreadSur(std::shared_ptr<int>& p2)
{
	p2.swap(p1);
	p1.swap(p2);
}
void func()
{
	std::shared_ptr<int> p2(new int(2000));
	for (int i = 0; i < 1000000; ++i)
	{
		JudgeIsThreadSur(p2);
		if (*p2.get() != 2000)
		{
			std::cout << "线程错误\n";
			break;
		}
	}
}

int main()
{
	for (int i = 0; i < 2; ++i)
	{
		std::thread t(func);
		t.detach();
	}
	while (1);
	return 0;
}
