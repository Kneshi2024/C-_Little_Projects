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
	virtual void operMenu();//�����ض����Ӳ˵�

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void ShowMyOrder();

	//�鿴����ԤԼ
	void ShowAllOrder();

	//ȡ��ԤԼ
	void CancelOrder();

	void initComVector();


	vector<ComputerRoom>vCom;


	int m_Id=0;

};