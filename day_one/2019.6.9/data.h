#include<iostream>
using namespace std;

class Date
{
public:
	explicit Date(int year = 2010, int month = 1, int day = 1);
	Date(const Date& d);
	void display();
	bool operator==(const Date& d);
	Date& operator=(const Date& d);
	Date operator++(int);
	Date operator++();
	Date operator--(int);
	Date operator--();
	Date operator-(int days);//不可以返回引用，因为不改变当前对象
	Date operator+(int days);
	bool operator>(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator!=(const Date& d)const;
	//////
	int IsvalidDays(Date d);
private:
	int _year;
	int _month;
	int _day;
};
