#include"conductor.h"
int main()
{
	conductor Init;
	Init.mainpage();
	return 0;
}

//2021年7月17日： 进行了主界面的设计和封装操作
//Todo：
//modify_mode()暂时只能进行同类别的修改。
//add_mode()增加对选择的提示。
//把 助教类 改为 辅导员类
//部门改为科目

//饼：增加输入密码登录系统 的操作。

/*2021年7月18日： 
Finished:
add_mode()增加了对选择的提示。
改善了modify_mode()的结构，使之可以进行多类别的修改。
进行了各处无关紧要的修缮。

Todo：
增加输入密码登录系统的操作
改善抽象类的结构，使之具有意义。
*/

/*2021年7月19日
Finished:
给delete_mode()和modify_mode()接口中new生成的line指针增加了delete，避免了潜在的内存泄漏问题
删减了很多实现文件中不必要的头文件引用
修改了exit_mode()的退出方式（从exit修改为return），并给conductor对象增加了析构函数，避免了对象未析构就中途退出的问题。
把抽象类改为abstract_human了，并实现了了抽象类指针对save()和modify()函数的调用。

Todo:
给学号和生日等数字的输入添加限制条件
增加输入密码登陆系统的操作
*/