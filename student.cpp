#include "student.h"//ʵ���ļ�����Ҫ�ѻ����ͷ�ļ�ҲImport��
#include"FileErr.h"

#include<iostream>
#include<fstream>
#include<strstream>
#include<iomanip>
#include<conio.h>
#include<string>

#pragma warning(disable:4996)

//�вι��캯��
//������������ѧ�š��Ա𡢰��
//����һ��ѧ�������
Student::Student(string nm, string num, string sx, int yy, int mm, int dd, string clno) :
	People(nm, num, sx, yy, mm, dd), classno(clno)
{}
Student::~Student() {}

//�޲ι��캯��
//������None
//ͨ�������޲ι��캯��ʹclient����ֱ���ڲ���ϵͳ�й�����Ҫ�Ķ���
Student::Student() :People()
{
	cout << "���"; cin >> classno;
}

//���ƹ��캯��
Student::Student(const Student& rhs) :People(rhs)
{
	classno = rhs.classno;
};

//��ֵ�����������
//������һ������������� const People&rhs
//ͨ��һ�����ж������һ�����ж���ֵ
//return��ͨ����ַ��ʽ�����µ�ԭ�ж���
Student& Student::operator= (const Student& rhs)
{
	if (this == &rhs) return *this;
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
	classno = rhs.classno;
	return *this;
}

//��������������
//������output���������rhs��Ŀ��People object
//return��ostream& �������������
ostream& operator<<(ostream& output, const Student& rhs)
{
	output << "������" << rhs.name << endl;
	output << "ѧ�ţ�" << rhs.number << endl;
	output << "�Ա�" << rhs.sex << endl;
	output << "���գ�" << rhs.birthday << endl;
	output << "���" << rhs.classno << endl;
	return output;
}

void Student::save()
{
	char c[80];
	ostrstream strout(c, 80);
	try
	{
		ofstream ofile("ѧУ��Ա��¼���.txt", ios::app);
		if (!ofile) throw (FileErr());
		else
		{
			strout << "2ѧ�� " << this->name << setw(8) << " " << this->number << " " << this->sex << " " << this->birthday << " " << this->classno << " " << "#" << endl;
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
void Student::modify(int target, int i, int line_num, string* line, ofstream& ofile)
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