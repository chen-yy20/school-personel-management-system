#pragma once
#include"student.h"
#include"date.h"

#ifndef Graduate_H
#define Graduate_H

#include<String>
#include<iostream>
#include<fstream>
using namespace std;

class Graduate :  public Student
{
public:
	Graduate(string nm, string num, string sx, int yy, int mm, int dd, string clno, string sub);
	Graduate();
	Graduate(const Graduate& rhs);
	virtual ~Graduate();
	Graduate& operator= (const Graduate& rhs);
	friend ostream& operator<<(ostream&, const Graduate& rhs);
	virtual void save();
	virtual void modify(int target, int i, int line_num, string* line, std::ofstream& file);
protected:
	string subject;
};


#endif

