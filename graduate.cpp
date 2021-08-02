#include "Graduate.h"//ʵ���ļ�����Ҫ�ѻ����ͷ�ļ�ҲImport��
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
Graduate::Graduate(string nm, string num, string sx, int yy, int mm, int dd, string clno, string sub) :
	People(nm,num,sx,yy,mm,dd),Student(nm, num, sx, yy, mm, dd,clno), subject(sub)
{}
Graduate::~Graduate() {}

//�޲ι��캯��
//������None
//ͨ�������޲ι��캯��ʹclient����ֱ���ڲ���ϵͳ�й�����Ҫ�Ķ���
Graduate::Graduate() :People(),Student()
{
	cout << "רҵ��"; cin >> subject;
}

//���ƹ��캯��
Graduate::Graduate(const Graduate& rhs) :Student(rhs)
{
	subject = rhs.subject;
};

//��ֵ�����������
//������һ������������� const Student&rhs
//ͨ��һ�����ж������һ�����ж���ֵ
//return��ͨ����ַ��ʽ�����µ�ԭ�ж���
Graduate& Graduate::operator= (const Graduate& rhs)
{
	if (this == &rhs) return *this;
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
	classno = rhs.classno;
	subject = rhs.subject;
	return *this;
}

//��������������
//������output���������rhs��Ŀ��Student object
//return��ostream& �������������
ostream& operator<<(ostream& output, const Graduate& rhs)
{
	output << "������" << rhs.name << endl;
	output << "ѧ�ţ�" << rhs.number << endl;
	output << "�Ա�" << rhs.sex << endl;
	output << "���գ�" << rhs.birthday << endl;
	output << "���" << rhs.classno << endl;
	output << "ѧ�ƣ�" << rhs.subject << endl;
	return output;
}
//���󱣴溯��
//��������
//�ں������аѴ˶���ĸ�����Ϣ���浽�ļ���ѧУ���¹���ϵͳ.txt����
//return: ��

void Graduate::save()
{
	char c[80];
	ostrstream strout(c, 80);
	try
	{
		ofstream ofile("ѧУ��Ա��¼���.txt", ios::app);
		if (!ofile) throw (FileErr());
		else
		{
			strout << "3�о��� " << this->name << setw(8) << " " << this->number << " " << this->sex << " " << this->birthday << " " << this->classno << " " << this->subject<<" "<<"#" << endl;
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

void Graduate::modify(int target, int i, int line_num, string* line, ofstream& ofile)
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
	cout << "����Ϣ�ѱ���" << endl;
}