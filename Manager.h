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

class Student;//������ʶ��
class ComputerRoom;

class Manager :public Identify{
public:
	Manager();
	Manager(string name,string pwd);

	//�Ӳ˵�
	virtual void operMenu();

	//����˺�
	void AddPerson();

	//�鿴�˺�
	void ShowPerson();

	//�鿴������Ϣ
	void ShowComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����Ƿ��ظ�
	bool checkRepeat(int id, int type);

	//����ѧ������ʦ������
	vector<Student>vStu;

	vector<Teacher>vTea;

	//������������
	vector<ComputerRoom>vCom;

	//��ʼ��������Ϣ
	void initComVector();

	
};
