#pragma once
#include"date.h"
#include"abstract_human.h"
#include"people.h"
#include"student.h"
#include"graduate.h"
#include"teacher.h"
#include"TA.h"
#include"FileErr.h"


#include<iostream>
#include<string>
#include<fstream>
#include<strstream>
#include<iomanip>
#include<conio.h>
#pragma warning(disable:4996)
using namespace std;

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
//��ȡ�ļ���һ�е���Ϣ����ӡ������
void getinfo_line(ifstream& ifile)
{
	char genre[10];
	
	string name, number, sex, classno, subject,department ,principal;
	Date birthday;
	ifile >> genre >> name >> number >> sex >> birthday;
	switch (genre[0] - 48)
	{
	case 1:
	{
	People* p;
	p = new People(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday());
	cout << *p;
	delete p; }break;
	case 2:
	{ifile >> classno;

	Student* s = new Student(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno);
	cout << *s;
	delete s; }break;
	case 3:
	{ifile >> classno >> subject;
	Graduate* g;
	g = new Graduate(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject);
	cout << *g;
	delete g; }break;
	
	case 4:
	{ifile >> department >> principal;
	Teacher* t;
	t = new Teacher(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), department, principal);
	cout << *t;
	delete t; }break;

	case 5:
	{ifile >>classno>>subject >>department >> principal;
	TA* ta;
	ta = new TA(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject, department, principal);
	cout << *ta;
	delete ta; }break;
	}
}

//��ȡ�ļ���һ�е���Ϣ���ж��Ƿ���������ҵ���Ϣ��ƥ�䣬��ƥ�����ӡ��Ϣ��������ʲô�����ɡ�
void search_line(ifstream& ifile,string info, int& flag)
{
	string genre, name, number, sex, classno,subject,department,principal;
	Date birthday;
	ifile >> genre >> name >> number >> sex >> birthday;
	if (name == info || number == info)
	{
		cout << "===========" << flag << "===========" << endl;
		switch (genre[0] - 48)
		{
		case 1:
		{
			People* p;
			p = new People(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday());
			cout << *p;
			delete p; }break;
		case 2:
		{ifile >> classno;
		Student* s;
		s = new Student(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno);
		cout << *s;
		delete s; }break;
		case 3:
		{ifile >> classno >> subject;
		Graduate* g;
		g = new Graduate(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject);
		cout << *g;
		delete g; }break;
		case 4:
		{ifile >> department>>principal;
		Teacher* t;
		t = new Teacher(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), department,principal);
		cout << *t;
		delete t; }break;
		case 5:
		{ifile >> classno >> subject>>department>>principal;
		TA* ta;
		ta = new TA(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject, department, principal);
		cout << *ta;
		delete ta; }break;
		}
		flag ++;
	}

}
//�в�����ƥ����Ա��Ϣ��
int search_all(string info)
{
	cout << "��ʼ����" << endl;
	try
	{
		int flag = 0;
		ifstream ifile("ѧУ��Ա��¼���.txt");
		if (!ifile) throw(FileErr());
		else
		{
			char str[1024];
			while (!ifile.eof() && ifile.tellg() != -1)
			{

				search_line(ifile, info, flag);
				cout << "ָ��λ�ã�" << ifile.tellg() << endl;
				ifile.getline(str, 1024, '#');//������һ�У�������׼�ַ���

			}
			ifile.close();
			if (flag >= 1) cout << "�����ҵ�����" << flag << "����Ϣ��" << endl;
			else cout << "δ���ҵ������Ϣ��" << endl;
			return flag;

		}

	}
	catch (FileErr E)
	{
		E.reasonopen();
		cout << "����������ء�" << endl;
		char c = getch();
		return 0;
	}
	return 0;
}


//����Ϊ��mainpageҳ������û���ʾ�Ľӿڡ�
class conductor
{
public:
	~conductor(){ cout << "��л����ʹ�ã��ټ���" << endl; }
	void mainpage()
	{
		system("cls");  //��������
		cout.width(30);
		cout.fill('+');//�������ֻ���õ�����
		cout.setf(ios::left);
		cout << " " << endl;

		cout.width(27);
		cout.fill(' ');
		cout.setf(ios::right);
		cout << "�໨�ɴ�ѧ���¹���ϵͳ" << endl;

		cout << " ";
		cout.width(29);
		cout.setf(ios::left);
		cout.fill('+');
		cout << "" << endl;


		cout.width(32);
		cout.fill('#');//�������ֻ���õ�����
		cout << "" << endl << endl;

		cout.width(18);
		cout.fill(' ');
		cout.setf(ios::right);
		cout << "���˵�" << endl;
		cout.width(21);
		cout << "1.����¼��" << endl;
		cout.width(21);
		cout << "2.����ɾ��" << endl;
		cout.width(21);
		cout << "3.��ʾȫ��" << endl;
		cout.width(21);
		cout << "4.���ݲ�ѯ" << endl;
		cout.width(21);
		cout << "5.�����޸�" << endl;
		cout.width(21);
		cout << "6.�˳�����" << endl;
		cout.width(24);
		cout << "��ѡ�����(1-6)" << endl;
		cout << " ";
		cout.width(30);
		cout.setf(ios::left);
		cout.fill('+');
		cout << "" << endl;
		cout<<"\n\n\n��ӭʹ�á��໨�ɴ�ѧ���¹���ϵͳ��\n"
			<<"ע�⣺�����ڳ������;��ͻȻ�˳����򣬿��ܵ������ص����ݶ�ʧ���⡣�˳�������ʹ��ϵͳ�ṩ�Ľӿڡ�\n"<<endl;
		button();
		
		}
	void button()
		{
			char input = getch();
			switch (input - 48)
			{
			case 1: add_mode(); break;
			case 2: delete_mode(); break;
			case 3: show_mode(); break;
			case 4: search_mode(); break;
			case 5: modify_mode(); break;
			case 6: exit_mode(); break;
			default: {
				cout << "��������룬������:" << endl;
				button();
			}
		}

	}
private:
	//���ļ��������Ա��Ϣ�Ľӿڡ�
	void add_mode()
	{
		char flag;
		cout << "��������¼����Ա�����" << endl;
		cout << "1.����� 2.ѧ�� 3.�о��� 4.��ְ��Ա 5.����" << endl;
		flag = getch();
		abstract_human * pt = NULL;
		switch (flag - 48)
		{
		case 1: { cout << "¼��ģʽ�������" << endl; pt = new People(); }break;
		case 2: { cout << "¼��ģʽ��ѧ��" << endl;  pt = new Student();}break;
		case 3: { cout << "¼��ģʽ���о���" << endl; pt = new Graduate(); }break;
		case 4: { cout << "¼��ģʽ����ְ��Ա" << endl; pt = new Teacher(); }break;
		case 5: { cout << "¼��ģʽ������" << endl; pt = new TA(); }break;
		default: cout << "�����ַ��������������룡" << endl;
		}
		pt->save();
		delete pt;
		cout << "1.�������\t2.����������" << endl;
		char button = getch();
		if (button == '1') add_mode();
		else mainpage();

	}

	//���������ļ�Ѱ��ƥ�����Ϣ���޲Σ������ҵ�ƥ�����Ϣ��������ӡ����Ϣ��
	void search_mode()
	{
		cout << "��ʼ����..." << endl;
		try
		{
			string info;
			int flag = 1;
			cout << "��������Ҫ���ҵ�����/ѧ�ţ�" << endl;
			cin >> info;
			ifstream ifile("ѧУ��Ա��¼���.txt");
			if (!ifile) throw(FileErr());
			else
			{
				char str[1024];
				while (!ifile.eof() && ifile.tellg() != -1)
				{

					search_line(ifile, info, flag);
					ifile.getline(str, 1024, '#');//������һ�У�������׼�ַ���

				}
				ifile.close();
				if (flag > 1) cout << "=======================\n�����ҵ�����" << flag-1 << "����Ϣ��" << endl;
				else cout << "=======================\nδ���ҵ������Ϣ��" << endl;

			}

		}
		catch (FileErr E)
		{
			E.reasonopen();
			cout << "����������������档" << endl;
			char c = getch();
		}
		cout << "1.��������\t2.����������" << endl;
		char button = getch();
		if (button == '1') search_mode();
		else mainpage();
	}

	//�޸���Ա��Ϣ�Ľӿ� ��������ҵ���Ϣ���������ļ�ԭλ�ý����޸ġ�
	void modify_mode()
	{
		char str[512];
		string info, * line;
		int line_num = -1, i, target = 0;//��ȡ�ļ�������Ŀ���ļ����ڵ�����
		int genre = 0;
		int flag = 0;  //��¼�޸ĵ���Ϣ��
		char button;
		char type;
		ifstream ifile;
		ofstream ofile;
		cout << "��������Ҫ�޸ĵĵ�����/ѧ�ţ�";
		cin >> info;
		try
		{
			ifile.open("ѧУ��Ա��¼���.txt");
			if (!ifile) throw(2);
			else
			{
				while (!ifile.eof())
				{
					ifile.getline(str, 1024, '#');
					line_num++;
				}
				line = new(string[line_num]);
				ifile.seekg(0);//ʹ�ļ�ָ��ָ�����ͷ
				for (i = 0; i < line_num; i++)
				{
					getline(ifile, *(line + i)); //getline��������һ���÷�
				}
				ifile.seekg(ios::beg);//ʹ�ļ�ָ��ָ�����ͷ
			//��������Ϊʹ���ַ��������ļ������е�ÿһ����Ϣ��
				string genre, name, number, sex, classno, subject, dpmt, principal;
				Date birthday;
				for (i = 0; i < line_num && ifile.tellg() != -1; i++)
				{
					ifile >> genre >> name >> number >> sex >> birthday;
					cout << "��ȡ���ȣ�" << i + 1 << "/" << line_num << endl;
					if (name == info || number == info)
					{
						flag ++;
						cout << "�ڵ�" << i + 1 << "�д����ҵ���Ϣ���£�" << endl;
						switch (genre[0] - 48)   //�ж�ָ������
						{
						case 1:
						{People* p;
						p = new People(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday());
						cout << *p;
						delete p; }break;
						case 2:
						{ifile >> classno;
						Student* s;
						s = new Student(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno);
						cout << *s;
						delete s; }break;
						case 3:
						{ifile >> classno >> subject;
						Graduate* g;
						g = new Graduate(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject);
						cout << *g;
						delete g; }break;
						case 4:
						{ifile >> dpmt >> principal;
						Teacher* t;
						t = new Teacher(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), dpmt, principal);
						cout << *t;
						delete t; }break;
						case 5:
						{ifile >> classno >> subject >> dpmt >> principal;
						TA* ta;
						ta = new TA(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject, dpmt, principal);
						cout << *ta;
						delete ta; }break;
						}
						cout << "�Ƿ�Դ���Ϣ�����޸ģ�(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							cout << "��������Ҫ�޸ĵ���Ա���\n1.�����  2.ѧ��  3.�о���  4.��ְ��Ա  5.����\n" ;
							cin >> type;
							abstract_human* pt = NULL;
							ifile.close();
							ofile.open("ѧУ��Ա��¼���.txt", ios::trunc);
							switch (type - 48)
							{
							case 1: {
								cout << "�޸�ģʽ���������ɡ�1�����..." << endl;
								pt =new People();
							}break;
							case 2: {
								cout << "�޸�ģʽ���������ɡ�2ѧ����..." << endl;
								pt = new Student();
							}break;
							case 3: {
								cout << "�޸�ģʽ���������ɡ�3�о�����..." << endl;
								pt = new Graduate();
							}break;
							case 4: {
								cout << "�޸�ģʽ���������ɡ�4��ְ��Ա��..." << endl;
								pt = new Teacher();
							}break;
							case 5: {
								cout << "�޸�ģʽ���������ɡ�5���̡�..." << endl;
								pt = new TA();
							}break;
							
							default: {cout << "��������룡�����ԣ�" << endl;
							}
							}
							pt->modify(target, i, line_num, line, ofile);
							delete pt;
							ofile.close();
						}
					}
					ifile.getline(str, 1024, '#');
				}
				delete[]line;
			}


		}
		catch (int)
		{
			cout << "�ļ��򿪷�������" << endl;
			cout << "����������ء�" << endl;
			info[0] = getch();
			return;
		}
		catch (FileErr E)
		{
			E.reasonread();
			cout << "����������ء�" << endl;
			info[0] = getch();
			return;
		}
		if (flag == 0) cout << "δ���ҵ������Ϣ��" << endl;
		cout << "1.�����޸�\t2.����������" << endl;
		button = getch();
		if (button == '1') modify_mode();
		else mainpage();

	}

	//ɾ����Ա��Ϣ�Ľӿڣ���������ҵ���Ϣ�������ļ���ɾ��������Ϣ��
	void delete_mode()
	{
		char str[512];
		string info, * line;
		int line_num = -1, i, target = -1;//��ȡ�ļ�������Ŀ���ļ����ڵ�����
		int genre = 0;
		int flag = 0;  //��¼���ҵ���Ϣ��
		char button;
		ifstream ifile;
		ofstream ofile;
		cout << "��������Ҫɾ���ĵ�����/ѧ�ţ�";
		cin >> info;
		try
		{
			ifile.open("ѧУ��Ա��¼���.txt");
			if (!ifile) throw(2);
			else
			{
				while (!ifile.eof())
				{
					ifile.getline(str, 1024, '#');
					line_num++;
				}
				line = new(string[line_num]);
				ifile.seekg(0);//ʹ�ļ�ָ��ָ�����ͷ
				for (i = 0; i < line_num; i++)
				{
					getline(ifile, *(line + i));
				}
				ifile.seekg(0);//ʹ�ļ�ָ��ָ�����ͷ
			//��������Ϊʹ���ַ��������ļ������е�ÿһ����Ϣ��
				string genre, name, number, sex, classno, subject, dpmt, principal;
				Date birthday;
				for (i = 0; i < line_num && ifile.tellg() != -1; i++)
				{
					ifile >> genre >> name >> number >> sex >> birthday;
					cout << "��ȡ���ȣ�" << i + 1 << "/" << line_num << endl;
					if (name == info || number == info)
					{
						flag = 1;
						cout << "�ڵ�" << i + 1 << "�д����ҵ���Ϣ���£�" << endl;
						switch (genre[0] - 48)   //�ж�ָ������
						{
						case 1:
						{People* p;
						p = new People(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday());
						cout << *p;
						cout << "�Ƿ�Դ���Ϣ����ɾ����(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("ѧУ��Ա��¼���.txt", ios::trunc);
						}
						delete p; }break;
						case 2:
						{ifile >> classno;
						Student* s;
						s = new Student(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno);
						cout << *s;
						cout << "�Ƿ�Դ���Ϣ����ɾ����(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("ѧУ��Ա��¼���.txt", ios::trunc);
						} delete s; }break;
						case 3:
						{ifile >> classno >> subject;
						Graduate* g;
						g = new Graduate(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject);
						cout << *g;
						cout << "�Ƿ�Դ���Ϣ����ɾ����(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("ѧУ��Ա��¼���.txt", ios::trunc);
						} delete g; }break;
						case 4:
						{ifile >> dpmt >> principal;
						Teacher* t;
						t = new Teacher(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), dpmt, principal);
						cout << *t;
						cout << "�Ƿ�Դ���Ϣ����ɾ����(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("ѧУ��Ա��¼���.txt", ios::trunc);
						} delete t; }break;
						case 5:
						{ifile >> classno >> subject >> dpmt >> principal;
						TA* ta;
						ta = new TA(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject, dpmt, principal);
						cout << *ta;
						cout << "�Ƿ�Դ���Ϣ����ɾ����(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("ѧУ��Ա��¼���.txt", ios::trunc);
						} delete ta; }break;
						}
					}
					ifile.getline(str, 1024, '#');
					if (target != -1)
					{
						for (i = 0; i < line_num; i++)
						{
							if (i != target)
							{
								ofile << *(line + i) << endl;
								cout << *(line + i) << endl;
							}
							else {
								cout << "ɾ����" << *(line + i) << endl;
							}
						}
						ofile.close();
						cout << "ɾ�������ɹ���" << endl;
					}
				}
				delete[]line;
			}
			
		}
		catch (int)
		{
			cout << "�ļ��򿪷�������" << endl;
			cout << "����������ء�" << endl;
			info[0] = getch();
			return;
		}
		catch (FileErr E)
		{
			E.reasonread();
			cout << "����������ء�" << endl;
			info[0] = getch();
			return;
		}
		if (flag == 0) cout << "δ���ҵ������Ϣ��" << endl;
		cout << "��Ϣ�ѱ�����ɡ�\n1.����ɾ��\t2.����������" << endl;
		button = getch();
		if (button == '1') delete_mode();
		else mainpage();
	}

	//��ʾ��Ϣ�ӿڣ���ȡ�����ļ��е���Ϣ����ӡ������
	void show_mode()

	{
		int num = 1;
		int count = 0;
		cout << "��ʼ��ȡ�ļ���Ϣ������" << endl;
		try
		{
			ifstream ifile("ѧУ��Ա��¼���.txt");
			if (!ifile) throw(FileErr());
			else
			{
				char str[1024];
				while (!ifile.eof() && ifile.tellg() != -1)
				{
					ifile.getline(str, 1024, '#');
					count++;
				}
				ifile.seekg(ios::beg);
				for (num; num< count;num++)
				{
					cout << "==========="<<num<<"===========" << endl;
					getinfo_line(ifile);
					ifile.getline(str, 1024, '#');//������һ�У�������׼�ַ���
				}
				ifile.close();
				cout << "=======================\n��Ϣ��ȫ����ʾ��\n����������������档" << endl;
				char t = getch();
				mainpage();

			}

		}
		catch (FileErr E)
		{
			E.reasonopen();
			cout << "����������ء�" << endl;
			char c = getch();
		}
		
	}
	
	//��ʾ��лʹ�ý��棬�˳�����
	void exit_mode()
	{
		return;
	}

};




#endif // !CONDUCTOR_H

