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

	//�Ӳ˵�
	virtual void operMenu();

	//��ʾ����ԤԼ
	void ShowAllOrder();

	//���ԤԼ
	void ValidOrder();



	int m_EmpId=0;
};