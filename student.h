#pragma once
#include"people.h"
#include"date.h"

#ifndef STUDENT_H
#define STUDENT_H

#include<String>
#include<iostream>
#include<fstream>
using namespace std;

class Student : virtual public People
{
public:
	Student(string nm, string num, string sx, int yy, int mm, int dd, string clno);
	Student();
	Student(const Student& rhs);
	virtual ~Student();
	Student& operator= (const Student& rhs);
	friend ostream& operator<<(ostream&, const Student& rhs);
	virtual void save();
	virtual void modify(int target, int i, int line_num, string* line, std::ofstream& file);
protected:
	string classno;
};


#endif
