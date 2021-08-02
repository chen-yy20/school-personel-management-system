#include"FileErr.h"
#include<iostream>
using namespace std;

int FileErr::reasonopen() const
{
	cout << "文件打开失败！" << endl;
	return 0;
}

int FileErr::reasonread() const
{
	cout << "文件读写错误！" << endl;
	return 0;
}