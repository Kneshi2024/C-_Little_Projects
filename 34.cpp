#include<iostream>
#include"globalFile.h"
#include<fstream>
#include"Identify.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"

using namespace std;


//管理员界面
void managerMenu(Identify *&manager){
	while (true) {
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//cout << "添加账号" << endl;
			man->AddPerson();
		}
		else if (select == 2) {
			//cout << "查看账号" << endl;
			man->ShowPerson();
		}
		else if (select == 3) {
			//cout << "查看机房" << endl;
			man->ShowComputer();
		}
		else if (select == 4) {
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生界面
void studentMenu(Identify*&student) {
	while (true) {
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//申请预约
			stu->applyOrder();
		}
		else if (select == 2) {
			//查看自己的预约
			stu->ShowMyOrder();
		}
		else if (select == 3) {
			//查看所有预约
			stu->ShowAllOrder();
		}
		else if (select == 4) {
			//取消预约
			stu->CancelOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//教师界面
void teacherMenu(Identify*&teacher) {
	while (true) {
		teacher->operMenu();
		Teacher* t = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			t->ShowAllOrder();
		}
		else if (select == 2) {
			t->ValidOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


void LoginIn(string filename,int type) {
	//父类指针，用于指向子类对象
	Identify* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户的信息
	int id=0;
	string name;
	string pwd;

	//判断用户信息
	if (type == 1) {
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工编号:" << endl;
		cin >> id;
	}

	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fid;//用文件中读取的id号
		string fname;//用文件中读取的姓名
		string fpwd;//用文件中读取的密码
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "学生登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				
				//进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//老师身份验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "教师登录验证成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "管理员登录验证成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);

				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "登录验证失败！" << endl;
	system("pause");
	system("cls");
}



int main() {
	int select = 0;
	while (true) {
		cout << "--------------  欢迎来到机房预约系统  --------------" << endl;
		cout << endl << "请输入您的身份:" << endl;
		cout << "\t\t -------------------------\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1.学生代表        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2.老    师        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3.管 理 员        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0.退    出        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t -------------------------\n";
		cout << "请输入您的选择:" << endl;
		cin >> select;
		switch (select){
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;

			break;
		default:
			cout << "输入有误请重新输入!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return(0);
}