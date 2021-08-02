#include "TA.h"//ʵ���ļ�����Ҫ�ѻ����ͷ�ļ�ҲImport��
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
//����һ���о��������
TA::TA(string nm, string num, string sx, int yy, int mm, int dd, string clno, string sub, string dpmt, string prin) :
	People(nm, num, sx, yy, mm, dd), Graduate(nm, num, sx,yy,mm,dd,clno,sub), Teacher(nm,num,sx,yy,mm,dd,dpmt, prin)
{}

TA::~TA() {}

//�޲ι��캯��
//������None
//ͨ�������޲ι��캯��ʹclient����ֱ���ڲ���ϵͳ�й�����Ҫ�Ķ���
TA::TA() :People(),Graduate(),Teacher()
{ }

//���ƹ��캯��
TA::TA(const TA& rhs) :People(rhs),Graduate(rhs),Teacher(rhs)
{ };

//��ֵ�����������
//������һ������������� const Graduate&rhs
//ͨ��һ�����ж������һ�����ж���ֵ
//return��ͨ����ַ��ʽ�����µ�ԭ�ж���
TA& TA::operator= (const TA& rhs)
{
	if (this == &rhs) return *this;
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
	classno = rhs.classno;
	subject = rhs.subject;
	department = rhs.department;
	principal = rhs.principal;
	return *this;
}

//��������������
//������output���������rhs��Ŀ��Graduate object
//return��ostream& �������������
ostream& operator<<(ostream& output, const TA& rhs)
{
	output << "������" << rhs.name << endl;
	output << "ѧ�ţ�" << rhs.number << endl;
	output << "�Ա�" << rhs.sex << endl;
	output << "���գ�" << rhs.birthday << endl;
	output << "���" << rhs.classno << endl;
	output << "��Ŀ��" << rhs.subject << endl;
	output << "���ţ�" << rhs.department << endl;
	output << "ְ��" << rhs.principal << endl;
	return output;
}
//���󱣴溯��
//��������
//�ں������аѴ˶���ĸ�����Ϣ���浽�ļ���ѧУ���¹���ϵͳ.txt����
//return: ��

void TA::save()
{
	char c[80];
	ostrstream strout(c, 80);
	try
	{
		ofstream ofile("ѧУ��Ա��¼���.txt", ios::app);
		if (!ofile) throw (FileErr());
		else
		{
			strout << "5���� " << this->name << setw(8) << " " << this->number << " " 
				<< this->sex << " " << this->birthday << " " << this->classno << " "
				<< this->subject << " " << this->department << " " << this->principal << " " << "#" << endl;
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

void TA::modify(int target, int i, int line_num, string* line, ofstream& ofile)
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