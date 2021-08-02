#pragma once
#include"people.h"
#include"date.h"
#include<iostream>
#include<string>
#include<fstream>

//Teacher �������
//Teacher Ϊ��ְ���࣬��People����������������ְλ��principal���Ͳ��ţ�department����˽�����ݳ�Ա

#ifndef TEACHER_H
#define TEACHER_H
class Teacher :virtual public People
{
public:
	Teacher(string nm, string num, string sx, int yy, int mm, int dd, string department, string principal);
	Teacher();
	Teacher(const Teacher& rhs);
	virtual ~Teacher();
	Teacher& operator= (const Teacher& rhs);
	friend std::ostream& operator<<(std::ostream&, const Teacher&);
	virtual void save();
	virtual void modify(int target, int i, int line_num, string* line, std::ofstream& file);
protected:
	string department;
	string principal;
};



#endif // !TEACHER_H


