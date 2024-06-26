#pragma once
#include <iostream>
#include"globalFile.h"
#include<map>
using namespace std;


class OrderFile {
public:
	OrderFile();

	//更新预约记录文件
	void updateOrder();

	//初始化记录文件
	void initOrderFile();

	//记录预约的条数
	int m_Size;

	map<int, map<string, string>>m_OrderData;
};