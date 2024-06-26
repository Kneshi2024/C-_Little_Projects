#pragma once
#include"Identify.h"
#include"Student.h"
#include"Teacher.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include<algorithm>
#include"ComputerRoom.h"
#include<iostream>

using namespace std;

class Student;//声明标识符
class ComputerRoom;

class Manager :public Identify{
public:
	Manager();
	Manager(string name,string pwd);

	//子菜单
	virtual void operMenu();

	//添加账号
	void AddPerson();

	//查看账号
	void ShowPerson();

	//查看机房信息
	void ShowComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//检测是否重复
	bool checkRepeat(int id, int type);

	//创建学生和老师的容器
	vector<Student>vStu;

	vector<Teacher>vTea;

	//创建机房容器
	vector<ComputerRoom>vCom;

	//初始化机房信息
	void initComVector();

	
};
