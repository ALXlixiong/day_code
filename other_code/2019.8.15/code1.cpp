#include <iostream>

class Date
{
public:
	Date()
	{
		std::cout << "date()\n";
	}

	Date(const Date& d)
	{
		std::cout << "Date(const Date& )\n";
	}
	Date& operator= (const Date & d)
	{
		a_ = d.a_;
		std::cout << "operator\n";
		return *this;
	}
	int a_;
};
int main()
{
	Date d1;
	Date d2;
	d2 = d1;
	
	return 0;
}
