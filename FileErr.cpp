#include"FileErr.h"
#include<iostream>
using namespace std;

int FileErr::reasonopen() const
{
	cout << "�ļ���ʧ�ܣ�" << endl;
	return 0;
}

int FileErr::reasonread() const
{
	cout << "�ļ���д����" << endl;
	return 0;
}