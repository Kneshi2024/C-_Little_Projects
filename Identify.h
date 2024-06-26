#pragma once
#include<iostream>
using namespace std;

class Identify {
public:
	//虚函数
	virtual void operMenu() = 0;//子菜单

	//成员函数
	string m_Name;
	string m_Pwd;
};
