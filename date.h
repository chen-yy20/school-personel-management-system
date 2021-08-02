//日期类的声明
//重载了输入流运算符和输出流运算符，到时候方便一起输出
#pragma once
#include<iostream>

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int yy=1901, int mm=1, int dd=1);
	~Date();
	int getyear() const;
	int getmonth() const;
	int getday() const;
	Date& operator = (const Date& rhs);
	friend std::ostream& operator<<(std::ostream&, const Date& rhs);
	friend std::istream& operator>>(std::istream&, Date& rhs);
private:
	int year;
	int month;
	int day;
};

#endif //!DATE_H