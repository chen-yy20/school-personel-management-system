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

//有参构造函数
//参数：姓名、学号、性别
//生成一个基本人员类对象
People::People(string nm, string num, string sx, int yy, int mm, int dd) :
	name(nm), number(num),sex(sx), birthday(yy,mm,dd)
{ }

//无参构造函数
//参数：None
//通过调用无参构造函数使client可以直接在操作系统中构造想要的对象。
People::People()
{
	cout << "请输入以下信息：" << endl;
	cout << "姓名："; cin >> name;
	cout << "编号："; cin >> number;
	cout << "性别："; cin >> sex;
	while (sex != "男" && sex != "女")
	{
		cout << "性别不合法！请输入“男”或“女”\n 性别：" << endl;
		cin >> sex;
	}
	cout << "生日："; cin >> birthday;
}

//析构函数
//参数：none
//释放该对象的内存并打印提示
People::~People() {}

//复制构造函数
//参数：一个常对象的引用 const People&rhs
//通过一个已有对象对另一个已有对象赋值
//return：复制后的新对象
People::People(const People& rhs)
{
	name = rhs.name;
	number = rhs.number;
	sex = rhs.sex;
	birthday = rhs.birthday;
};
 
//赋值运算符的重载
//参数：一个常对象的引用 const People&rhs
//通过一个已有对象对另一个已有对象赋值
//return：通过传址方式返回新的原有对象
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
		ofstream ofile("学校人员记录表格.txt", ios::app);
		if (!ofile) throw (FileErr());
		else
		{
			strout << "1无类别 " << this->name << setw(8)<<" " <<this->number <<" " << this->sex << " "<< this->birthday << " " << "#" << endl;
			strout << ends;
			cout << c;//调试
			ofile << c;
			cout << "信息保存成功。" << endl;
			ofile.close();
		}
	}
	catch (FileErr E)
	{
		E.reasonopen();
		cout << "按任意键返回。" << endl;
		char c=getch();
	}
	
}

//流输出运算符重载
//参数：output：输出流、rhs：目标People object
//return：ostream& 返回输出流本身。
ostream& operator<<(ostream& output, const People&rhs)
{
	output << "姓名：" << rhs.name << endl;
	output << "编号：" << rhs.number << endl;
	output << "性别：" << rhs.sex << endl;
	output << "生日：" << rhs.birthday << endl;
	return output;
}

//修改对象保存函数
//参数：target：用来储存对象所在文件行数/ i：目标文件所在的行数 / line_num:总行数 / line：string类数组指针 分别储存了文件中每一行的字符串 / ofile:输出流文件
//在modifymode()中调用此函数，可以把修改过的对象存入txt文件中。
// 用于保存，并非用于修改。
//return: 无

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
			ofile.open("学校人员记录表格.txt", ios::app);
			continue;
		}
	}
	cout << "新信息已保存。" << endl;
}