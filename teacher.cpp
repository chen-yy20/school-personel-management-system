#include "teacher.h"//ʵ���ļ�����Ҫ�ѻ����ͷ�ļ�ҲImport��
#include"FileErr.h"

#include<iostream>
#include<fstream>
#include<strstream>
#include<iomanip>
#include<conio.h>
#include<string>

#pragma warning(disable:4996)

//�вι��캯��
//������������ѧ�š��Ա�ְλ������
//����һ����ְ��Ա�����
Teacher::Teacher(string nm, string num, string sx, int yy, int mm, int dd, string dpmt, string prcpl) :
	People(nm, num, sx, yy, mm, dd), department(dpmt),principal(prcpl){ }

//��������
Teacher::~Teacher() {  }

//�޲ι��캯��
//������None
//ͨ�������޲ι��캯��ʹclient����ֱ���ڲ���ϵͳ�й�����Ҫ�Ķ���
Teacher::Teacher() :People()
{
	cout << "���ţ�"; cin >> department;
	cout << "ְ��"; cin >> principal;
}

//���ƹ��캯��
Teacher::Teacher(const Teacher& rhs) :People(rhs)
{
	department = rhs.department;
	principal = rhs.principal;
};

//��ֵ�����������
//������һ������������� const People&rhs
//ͨ��һ�����ж������һ�����ж���ֵ
//return��ͨ����ַ��ʽ�����µ�ԭ�ж���
Teacher& Teacher::operator= (const Teacher& rhs)
{
	if (this == &rhs) return *this;
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
	department = rhs.department;
	principal = rhs.principal;
	return *this;
}

//��������������
//������output���������rhs��Ŀ��People object
//return��ostream& �������������
ostream& operator<<(ostream& output, const Teacher& rhs)
{
	output << "������" << rhs.name << endl;
	output << "��ţ�" << rhs.number << endl;
	output << "�Ա�" << rhs.sex << endl;
	output << "���գ�" << rhs.birthday << endl;
	output << "���ţ�" << rhs.department << endl;
	output << "ְ��" << rhs.principal << endl;
	return output;
}

void Teacher::save()
{
	char c[80];
	ostrstream strout(c, 80);
	try
	{
		ofstream ofile("ѧУ��Ա��¼���.txt", ios::app);
		if (!ofile) throw (FileErr());
		else
		{
			strout << "4��ְ��Ա " << this->name << setw(8) << " " << this->number << " " << this->sex << " " << this->birthday << " " << this->department << " "<<this->principal<<" " << "#" << endl;
			strout << ends;
			cout << c;//����
			ofile << c;
			cout << "��Ϣ����ɹ���" << endl;
			ofile.close();
		}
	}
	catch (FileErr E)
	{
		E.reasonopen();
		cout << "����������ء�" << endl;
		char c = getch();
	}
}
//�޸Ķ��󱣴溯��
//������target������������������ļ�����/ i��Ŀ���ļ����ڵ����� / line_num:������ / line��string������ָ�� �ֱ𴢴����ļ���ÿһ�е��ַ��� / ofile:������ļ�
//��modifymode()�е��ô˺��������԰��޸Ĺ��Ķ������txt�ļ��С�
// ���ڱ��棬���������޸ġ�
//return: ��
void Teacher::modify(int target, int i, int line_num, string* line, std::ofstream& ofile)
{
	
	target = i;
	for (i = 0; i < line_num; i++)
	{
		if (i != target) ofile << *(line + i) << endl;
		else
		{
			ofile.close();
			this->save();
			ofile.open("ѧУ��Ա��¼���.txt", ios::app);
			continue;
		}
	}
	cout << "����Ϣ�ѱ��档" << endl;
}