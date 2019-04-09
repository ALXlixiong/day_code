#include "date.h"
int main()
{
	Date d1(2018, 11, 1);
	Date d2(2019, 11, 17);
	//d1 = d2 + 3;
	//cout << (d1 > d2) << endl;
	//Date d2(d1);
	
	/*if (d1 == d2)
		cout << "d1 == d2" << endl;
	else
		cout << "d1 != d2" << endl;
	cout << (d1 == d2) << endl;
	Date d3;*/
	//d3 = d1 = d2++;
	//d3 = d1 = ++d2;
	//d3 = d1 = --d2;
	//cout << (d1 >= d2) << endl;
	//cout << (d1 != d2) << endl;
	/*d2 = d1 + 999;
	d2.display();
	d1 = d2 - 999;
	d1 = d1 - 1;*/
	d1 = d1 - 999;
	d1.display();
	return 0;
}