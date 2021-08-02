#include"date.h"
#include <iostream>
using namespace std;

bool date_find(int year, int month, int day) //输入年月日 判断日期是否合法
{
	if (year < 1901 || year >2021 || month < 1 || month > 12 || day < 1 || day > 31) return false;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day == 31) return false;
		else return true;
	}
	else if (month == 2)
	{
		if (year % 4 == 0)  //闰年
		{
			if (day > 29) return false;
			else return true;
		}
		else
		{
			if (day > 28) return false;
			else return true;
		}
	}
	else return true;

}


Date::Date(int yy, int mm, int dd)
{
	int a, b, c;
	a = yy;
	b = mm;
	c = dd;
	while (!date_find(a, b, c))
	{
		cout << "日期不合法！请重新输入（年/月/日）" << endl;
		cin >> a >> b >> c;
	}
	year = a;
	month = b;
	day = c;
}


Date::~Date() { }

int Date::getyear() const { return year; }
int Date::getmonth() const { return month; }
int Date::getday() const { return day; }

Date& Date::operator=(const Date& rhs)
{
	if (this == &rhs) return *this;
	year = rhs.year;
	month = rhs.month;
	day = rhs.day;
	return *this;
}

ostream& operator <<(ostream& output, const Date& rhs)
{
	output << rhs.year << " ";
	output << rhs.month << " ";
	output << rhs.day;
	return output;
}

istream& operator >>(istream& input, Date& rhs)
{
	input >> rhs.year >> rhs.month >> rhs.day;
	while (!date_find(rhs.getyear(), rhs.getmonth(), rhs.getday()))
	{
		cout << "日期不合法！请重新输入（年/月/日）：" << endl;
		input.clear();
		input >> rhs.year >> rhs.month >> rhs.day;
	}
	return input;
}

