#include"date.h"
//构造函数  全缺省
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
//拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
//
void Date::display()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
/////
bool Date::operator==(const Date& d)
{
	if (_year == d._year &&
		_month == d._month &&
		_day == d._day)
		return true;
	else
		return false;
}

// = 
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
//后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	_day += 1;
	return tmp;
}
//前置++
Date Date::operator++()
{
	_day += 1;
	return *this;
}
//前置--
Date Date::operator--()
{
	_day -= 1;
	return *this;
}
//后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	_day -= 1;
	return tmp;
}
// -
int Date::IsvalidDays(Date d)
{
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((d._year % 4 == 0 && d._year % 100 != 0) || d._year % 400 == 0)
		arr[2] += 1;
	return arr[d._month];
}
Date Date::operator-(int days)
{
	Date tmp(*this);
	tmp._day -= days;
	while(tmp._day <= 0)
	{
		tmp._month--;
		if (tmp._month < 1)
		{
			tmp._month = 12;
			tmp._year--;
		}
		tmp._day += IsvalidDays(tmp);
	}
	return tmp;
}
// +
Date Date::operator+(int days)
{
	Date tmp(*this);
	tmp._day += days;
	while(tmp._day>IsvalidDays(tmp))
	{
		tmp._day -= IsvalidDays(tmp);
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._month = 1;
			tmp._year++;
		}
	}
	return tmp;
}
//4年一闰，100年不闰，400年1闰
bool Date::operator > (const Date& d)const
{
	if (_year > d._year || (_year <= d._year && _month > d._month) || (_year <= d._year && _month <= d._month && _day > d._day))
		return true;
	else
		return false;
}
bool Date::operator<(const Date& d)const
{
	if (_year < d._year || (_year >= d._year && _month < d._month) || (_year >= d._year && _month >= d._month && _day < d._day))
		return true;
	else
		return false;
}
bool Date::operator>=(const Date& d)const
{
	return !operator<(d);
}
bool Date::operator<=(const Date& d)const
{
	return !operator>(d);
}
bool Date::operator!=(const Date& d)const
{
	if (_year != d._year || _month != d._month || _day != d._day)
		return true;
	else
		return false;
}




















