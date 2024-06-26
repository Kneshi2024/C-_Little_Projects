#pragma once
#include"Identify.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"ComputerRoom.h"
#include"Manager.h"
#include"orderFile.h"

class Student:public Identify{
public:
	Student();
	Student(int id, string name, string pwd);
	virtual void operMenu();//子类重定义子菜单

	//申请预约
	void applyOrder();

	//查看自身预约
	void ShowMyOrder();

	//查看所有预约
	void ShowAllOrder();

	//取消预约
	void CancelOrder();

	void initComVector();


	vector<ComputerRoom>vCom;


	int m_Id=0;

};