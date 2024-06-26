#pragma once
#include"Identify.h"
#include<iostream>
#include"orderFile.h"
#include<vector>
using namespace std;


class Teacher :public Identify{
public:
	Teacher();
	Teacher(int empid,string name,string pwd);

	//子菜单
	virtual void operMenu();

	//显示所有预约
	void ShowAllOrder();

	//审核预约
	void ValidOrder();



	int m_EmpId=0;
};