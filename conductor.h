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
//读取文件中一行的信息并打印出来。
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

//读取文件中一行的信息并判定是否与所需查找的信息相匹配，若匹配则打印信息，若否，则什么都不干。
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
//有参搜索匹配人员信息。
int search_all(string info)
{
	cout << "开始查找" << endl;
	try
	{
		int flag = 0;
		ifstream ifile("学校人员记录表格.txt");
		if (!ifile) throw(FileErr());
		else
		{
			char str[1024];
			while (!ifile.eof() && ifile.tellg() != -1)
			{

				search_line(ifile, info, flag);
				cout << "指针位置：" << ifile.tellg() << endl;
				ifile.getline(str, 1024, '#');//跳过这一行，读到标准字符。

			}
			ifile.close();
			if (flag >= 1) cout << "共查找到以上" << flag << "个信息。" << endl;
			else cout << "未查找到相关信息！" << endl;
			return flag;

		}

	}
	catch (FileErr E)
	{
		E.reasonopen();
		cout << "按任意键返回。" << endl;
		char c = getch();
		return 0;
	}
	return 0;
}


//以下为在mainpage页面会向用户显示的接口。
class conductor
{
public:
	~conductor(){ cout << "感谢您的使用，再见。" << endl; }
	void mainpage()
	{
		system("cls");  //清屏函数
		cout.width(30);
		cout.fill('+');//输入符号只能用单引号
		cout.setf(ios::left);
		cout << " " << endl;

		cout.width(27);
		cout.fill(' ');
		cout.setf(ios::right);
		cout << "青花瓷大学人事管理系统" << endl;

		cout << " ";
		cout.width(29);
		cout.setf(ios::left);
		cout.fill('+');
		cout << "" << endl;


		cout.width(32);
		cout.fill('#');//输入符号只能用单引号
		cout << "" << endl << endl;

		cout.width(18);
		cout.fill(' ');
		cout.setf(ios::right);
		cout << "主菜单" << endl;
		cout.width(21);
		cout << "1.数据录入" << endl;
		cout.width(21);
		cout << "2.数据删除" << endl;
		cout.width(21);
		cout << "3.显示全部" << endl;
		cout.width(21);
		cout << "4.数据查询" << endl;
		cout.width(21);
		cout << "5.数据修改" << endl;
		cout.width(21);
		cout << "6.退出程序" << endl;
		cout.width(24);
		cout << "请选择序号(1-6)" << endl;
		cout << " ";
		cout.width(30);
		cout.setf(ios::left);
		cout.fill('+');
		cout << "" << endl;
		cout<<"\n\n\n欢迎使用【青花瓷大学人事管理系统】\n"
			<<"注意：切勿在程序操作途中突然退出程序，可能导致严重的数据丢失问题。退出程序请使用系统提供的接口。\n"<<endl;
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
				cout << "错误的输入，请重试:" << endl;
				button();
			}
		}

	}
private:
	//往文件中添加人员信息的接口。
	void add_mode()
	{
		char flag;
		cout << "请输入想录入人员的类别。" << endl;
		cout << "1.无类别 2.学生 3.研究生 4.教职人员 5.助教" << endl;
		flag = getch();
		abstract_human * pt = NULL;
		switch (flag - 48)
		{
		case 1: { cout << "录入模式：无类别" << endl; pt = new People(); }break;
		case 2: { cout << "录入模式：学生" << endl;  pt = new Student();}break;
		case 3: { cout << "录入模式：研究生" << endl; pt = new Graduate(); }break;
		case 4: { cout << "录入模式：教职人员" << endl; pt = new Teacher(); }break;
		case 5: { cout << "录入模式：助教" << endl; pt = new TA(); }break;
		default: cout << "输入字符有误，请重新输入！" << endl;
		}
		pt->save();
		delete pt;
		cout << "1.继续添加\t2.返回主界面" << endl;
		char button = getch();
		if (button == '1') add_mode();
		else mainpage();

	}

	//搜索整个文件寻找匹配的信息（无参），若找到匹配的信息，逐条打印该信息。
	void search_mode()
	{
		cout << "开始查找..." << endl;
		try
		{
			string info;
			int flag = 1;
			cout << "请输入需要查找的姓名/学号：" << endl;
			cin >> info;
			ifstream ifile("学校人员记录表格.txt");
			if (!ifile) throw(FileErr());
			else
			{
				char str[1024];
				while (!ifile.eof() && ifile.tellg() != -1)
				{

					search_line(ifile, info, flag);
					ifile.getline(str, 1024, '#');//跳过这一行，读到标准字符。

				}
				ifile.close();
				if (flag > 1) cout << "=======================\n共查找到以上" << flag-1 << "个信息。" << endl;
				else cout << "=======================\n未查找到相关信息！" << endl;

			}

		}
		catch (FileErr E)
		{
			E.reasonopen();
			cout << "按任意键返回主界面。" << endl;
			char c = getch();
		}
		cout << "1.重新搜索\t2.返回主界面" << endl;
		char button = getch();
		if (button == '1') search_mode();
		else mainpage();
	}

	//修改人员信息的接口 输入待查找的信息，即可在文件原位置进行修改。
	void modify_mode()
	{
		char str[512];
		string info, * line;
		int line_num = -1, i, target = 0;//获取文件行数和目标文件所在的行数
		int genre = 0;
		int flag = 0;  //记录修改的信息数
		char button;
		char type;
		ifstream ifile;
		ofstream ofile;
		cout << "请输入需要修改的的姓名/学号：";
		cin >> info;
		try
		{
			ifile.open("学校人员记录表格.txt");
			if (!ifile) throw(2);
			else
			{
				while (!ifile.eof())
				{
					ifile.getline(str, 1024, '#');
					line_num++;
				}
				line = new(string[line_num]);
				ifile.seekg(0);//使文件指针恢复到开头
				for (i = 0; i < line_num; i++)
				{
					getline(ifile, *(line + i)); //getline函数的另一种用法
				}
				ifile.seekg(ios::beg);//使文件指针恢复到开头
			//以上内容为使用字符串储存文件中已有的每一行信息。
				string genre, name, number, sex, classno, subject, dpmt, principal;
				Date birthday;
				for (i = 0; i < line_num && ifile.tellg() != -1; i++)
				{
					ifile >> genre >> name >> number >> sex >> birthday;
					cout << "读取进度：" << i + 1 << "/" << line_num << endl;
					if (name == info || number == info)
					{
						flag ++;
						cout << "在第" << i + 1 << "行处查找到信息如下：" << endl;
						switch (genre[0] - 48)   //判断指针类型
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
						cout << "是否对此信息进行修改？(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							cout << "请输入想要修改的人员类别：\n1.无类别  2.学生  3.研究生  4.教职人员  5.助教\n" ;
							cin >> type;
							abstract_human* pt = NULL;
							ifile.close();
							ofile.open("学校人员记录表格.txt", ios::trunc);
							switch (type - 48)
							{
							case 1: {
								cout << "修改模式：即将生成【1无类别】..." << endl;
								pt =new People();
							}break;
							case 2: {
								cout << "修改模式：即将生成【2学生】..." << endl;
								pt = new Student();
							}break;
							case 3: {
								cout << "修改模式：即将生成【3研究生】..." << endl;
								pt = new Graduate();
							}break;
							case 4: {
								cout << "修改模式：即将生成【4教职人员】..." << endl;
								pt = new Teacher();
							}break;
							case 5: {
								cout << "修改模式：即将生成【5助教】..." << endl;
								pt = new TA();
							}break;
							
							default: {cout << "错误的输入！请重试！" << endl;
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
			cout << "文件打开发生错误。" << endl;
			cout << "按任意键返回。" << endl;
			info[0] = getch();
			return;
		}
		catch (FileErr E)
		{
			E.reasonread();
			cout << "按任意键返回。" << endl;
			info[0] = getch();
			return;
		}
		if (flag == 0) cout << "未查找到相关信息！" << endl;
		cout << "1.继续修改\t2.返回主界面" << endl;
		button = getch();
		if (button == '1') modify_mode();
		else mainpage();

	}

	//删除人员信息的接口，输入待查找的信息，并在文件中删除该条信息。
	void delete_mode()
	{
		char str[512];
		string info, * line;
		int line_num = -1, i, target = -1;//获取文件行数和目标文件所在的行数
		int genre = 0;
		int flag = 0;  //记录查找的信息数
		char button;
		ifstream ifile;
		ofstream ofile;
		cout << "请输入需要删除的的姓名/学号：";
		cin >> info;
		try
		{
			ifile.open("学校人员记录表格.txt");
			if (!ifile) throw(2);
			else
			{
				while (!ifile.eof())
				{
					ifile.getline(str, 1024, '#');
					line_num++;
				}
				line = new(string[line_num]);
				ifile.seekg(0);//使文件指针恢复到开头
				for (i = 0; i < line_num; i++)
				{
					getline(ifile, *(line + i));
				}
				ifile.seekg(0);//使文件指针恢复到开头
			//以上内容为使用字符串储存文件中已有的每一行信息。
				string genre, name, number, sex, classno, subject, dpmt, principal;
				Date birthday;
				for (i = 0; i < line_num && ifile.tellg() != -1; i++)
				{
					ifile >> genre >> name >> number >> sex >> birthday;
					cout << "读取进度：" << i + 1 << "/" << line_num << endl;
					if (name == info || number == info)
					{
						flag = 1;
						cout << "在第" << i + 1 << "行处查找到信息如下：" << endl;
						switch (genre[0] - 48)   //判断指针类型
						{
						case 1:
						{People* p;
						p = new People(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday());
						cout << *p;
						cout << "是否对此信息进行删除？(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("学校人员记录表格.txt", ios::trunc);
						}
						delete p; }break;
						case 2:
						{ifile >> classno;
						Student* s;
						s = new Student(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno);
						cout << *s;
						cout << "是否对此信息进行删除？(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("学校人员记录表格.txt", ios::trunc);
						} delete s; }break;
						case 3:
						{ifile >> classno >> subject;
						Graduate* g;
						g = new Graduate(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject);
						cout << *g;
						cout << "是否对此信息进行删除？(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("学校人员记录表格.txt", ios::trunc);
						} delete g; }break;
						case 4:
						{ifile >> dpmt >> principal;
						Teacher* t;
						t = new Teacher(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), dpmt, principal);
						cout << *t;
						cout << "是否对此信息进行删除？(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("学校人员记录表格.txt", ios::trunc);
						} delete t; }break;
						case 5:
						{ifile >> classno >> subject >> dpmt >> principal;
						TA* ta;
						ta = new TA(name, number, sex, birthday.getyear(), birthday.getmonth(), birthday.getday(), classno, subject, dpmt, principal);
						cout << *ta;
						cout << "是否对此信息进行删除？(Y/N)" << endl;
						cin >> button;
						if (button == 'Y' || button == 'y')
						{
							target = i;
							ifile.close();
							ofile.open("学校人员记录表格.txt", ios::trunc);
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
								cout << "删除：" << *(line + i) << endl;
							}
						}
						ofile.close();
						cout << "删除操作成功！" << endl;
					}
				}
				delete[]line;
			}
			
		}
		catch (int)
		{
			cout << "文件打开发生错误。" << endl;
			cout << "按任意键返回。" << endl;
			info[0] = getch();
			return;
		}
		catch (FileErr E)
		{
			E.reasonread();
			cout << "按任意键返回。" << endl;
			info[0] = getch();
			return;
		}
		if (flag == 0) cout << "未查找到相关信息！" << endl;
		cout << "信息已遍历完成。\n1.继续删除\t2.返回主界面" << endl;
		button = getch();
		if (button == '1') delete_mode();
		else mainpage();
	}

	//显示信息接口，读取整个文件中的信息并打印出来。
	void show_mode()

	{
		int num = 1;
		int count = 0;
		cout << "开始提取文件信息。。。" << endl;
		try
		{
			ifstream ifile("学校人员记录表格.txt");
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
					ifile.getline(str, 1024, '#');//跳过这一行，读到标准字符。
				}
				ifile.close();
				cout << "=======================\n信息已全部显示！\n按任意键返回主界面。" << endl;
				char t = getch();
				mainpage();

			}

		}
		catch (FileErr E)
		{
			E.reasonopen();
			cout << "按任意键返回。" << endl;
			char c = getch();
		}
		
	}
	
	//显示感谢使用界面，退出程序。
	void exit_mode()
	{
		return;
	}

};




#endif // !CONDUCTOR_H

