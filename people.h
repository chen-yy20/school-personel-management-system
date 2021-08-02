#pragma once
#include"abstract_human.h"
#include"date.h"
#include<iostream>
#include<string>
#include<fstream>

//People 类的声明
//People 为基本人员类，私有数据成员较少，可作为后续类别派生的基类。

#ifndef PEOPLE_H
#define PEOPLE_H
class People:virtual public abstract_human
{
public:
	People(string nm , string num , string sx , int yy, int mm, int dd);
	People();
	People(const People& rhs);
	virtual ~People();
	People& operator= (const People& rhs);
	friend std::ostream& operator<<(std::ostream&, const People&);
	virtual void save();
	virtual void modify(int target, int i, int line_num, string* line,std::ofstream& file);
protected:
	string name;
	string number;
	string sex;
	Date birthday;
};



#endif // !PEOPLE_H

