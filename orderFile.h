#pragma once
#include <iostream>
#include"globalFile.h"
#include<map>
using namespace std;


class OrderFile {
public:
	OrderFile();

	//����ԤԼ��¼�ļ�
	void updateOrder();

	//��ʼ����¼�ļ�
	void initOrderFile();

	//��¼ԤԼ������
	int m_Size;

	map<int, map<string, string>>m_OrderData;
};