#pragma once
#include"teacher.h"
#include"graduate.h"
#include"date.h"

#ifndef TA_H
#define TA_H

#include<String>
#include<iostream>
#include<fstream>
using namespace std;

class TA : public Graduate, public Teacher
{
public:
	TA(string nm, string num, string sx, int yy, int mm, int dd, string clno, string subj, string department, string principal);
	TA();
	TA(const TA& rhs);
	~TA();
	TA& operator= (const TA& rhs);
	friend ostream& operator<<(ostream&, const TA& rhs);
	virtual void save();
	virtual void modify(int target, int i, int line_num, string* line, std::ofstream& file);
};

#endif
