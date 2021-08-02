#include"people.h"
#include"FileErr.h"

#include<iostream>
#include<strstream>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>
#pragma warning(disable : 4996)
using namespace std;

//�вι��캯��
//������������ѧ�š��Ա�
//����һ��������Ա�����
People::People(string nm, string num, string sx, int yy, int mm, int dd) :
	name(nm), number(num),sex(sx), birthday(yy,mm,dd)
{ }

//�޲ι��캯��
//������None
//ͨ�������޲ι��캯��ʹclient����ֱ���ڲ���ϵͳ�й�����Ҫ�Ķ���
People::People()
{
	cout << "������������Ϣ��" << endl;
	cout << "������"; cin >> name;
	cout << "��ţ�"; cin >> number;
	cout << "�Ա�"; cin >> sex;
	while (sex != "��" && sex != "Ů")
	{
		cout << "�Ա𲻺Ϸ��������롰�С���Ů��\n �Ա�" << endl;
		cin >> sex;
	}
	cout << "���գ�"; cin >> birthday;
}

//��������
//������none
//�ͷŸö�����ڴ沢��ӡ��ʾ
People::~People() {}

//���ƹ��캯��
//������һ������������� const People&rhs
//ͨ��һ�����ж������һ�����ж���ֵ
//return�����ƺ���¶���
People::People(const People& rhs)
{
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
};
 
//��ֵ�����������
//������һ������������� const People&rhs
//ͨ��һ�����ж������һ�����ж���ֵ
//return��ͨ����ַ��ʽ�����µ�ԭ�ж���
People& People::operator= (const People& rhs)
{
	if (this == &rhs) return *this;
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
	return *this;
};

void People::save()
{
	
	char c[80];
	ostrstream strout(c, 80);
	try
	{
		ofstream ofile("ѧУ��Ա��¼���.txt", ios::app);
		if (!ofile) throw (FileErr());
		else
		{
			strout << "1����� " << this->name << setw(8)<<" " <<this->number <<" " << this->sex << " "<< this->birthday << " " << "#" << endl;
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
		char c=getch();
	}
	
}

//��������������
//������output���������rhs��Ŀ��People object
//return��ostream& �������������
ostream& operator<<(ostream& output, const People&rhs)
{
	output << "������" << rhs.name << endl;
	output << "��ţ�" << rhs.number << endl;
	output << "�Ա�" << rhs.sex << endl;
	output << "���գ�" << rhs.birthday << endl;
	return output;
}

//�޸Ķ��󱣴溯��
//������target������������������ļ�����/ i��Ŀ���ļ����ڵ����� / line_num:������ / line��string������ָ�� �ֱ𴢴����ļ���ÿһ�е��ַ��� / ofile:������ļ�
//��modifymode()�е��ô˺��������԰��޸Ĺ��Ķ������txt�ļ��С�
// ���ڱ��棬���������޸ġ�
//return: ��

void People::modify(int target, int i, int line_num,string* line ,ofstream& ofile)
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