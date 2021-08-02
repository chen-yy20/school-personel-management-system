//抽象类一般不包含数据成员，只提供接口
#include<string>
#include<fstream>
#pragma once

#ifndef abstract_human_H
#define abstract_human_H

using namespace std;

class abstract_human
{
public:
	virtual ~abstract_human() {};  //史诗级debug的结果！抽象类里面要加虚析构函数才可以delete！
	virtual void save() = 0;
	virtual void modify(int target, int i, int line_num, string* line, std::ofstream& file) = 0;
};

#endif // !abstract_human_H
