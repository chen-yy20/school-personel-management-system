//������һ�㲻�������ݳ�Ա��ֻ�ṩ�ӿ�
#include<string>
#include<fstream>
#pragma once

#ifndef abstract_human_H
#define abstract_human_H

using namespace std;

class abstract_human
{
public:
	virtual ~abstract_human() {};  //ʷʫ��debug�Ľ��������������Ҫ�������������ſ���delete��
	virtual void save() = 0;
	virtual void modify(int target, int i, int line_num, string* line, std::ofstream& file) = 0;
};

#endif // !abstract_human_H
