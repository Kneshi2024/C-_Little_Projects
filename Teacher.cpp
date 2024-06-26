#include"Teacher.h"

Teacher::Teacher() {

}
Teacher::Teacher(int empid, string name, string pwd) {
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//子菜单
void Teacher::operMenu() {
	cout << "欢迎教师:" << this->m_Name << "登录！" << endl;
	cout << "\t\t -------------------------\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.查看所有预约    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.审核预约        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.注销登录        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t -------------------------\n";
	cout << "请选择您的操作:" << endl;
}

//显示所有预约
void Teacher::ShowAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0;i < of.m_Size;i++) {
			cout << i + 1 << "、" << " ";
			cout << "预约日期: 周" << of.m_OrderData[i]["date"];
			cout << "  时间段: " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "  学号: " << of.m_OrderData[i]["stuId"];
			cout << "  姓名: " << of.m_OrderData[i]["stuName"];
			cout << "  机房号: " << of.m_OrderData[i]["roomId"];
			string status = "  预约状态: ";
			if (of.m_OrderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_OrderData[i]["status"] == "2") {
				status += "已预约";
			}
			else if (of.m_OrderData[i]["status"] == "3") {
				status += "预约失败";
			}
			else if (of.m_OrderData[i]["status"] == "0") {
				status += "取消预约";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::ValidOrder() {
	vector<int>v;
	OrderFile of;
	int index = 0;
	if (of.m_Size == 0) {
		cout << "预约文件为空" << endl;
		system("pause");
		system("cls");
			return;
	}
	else {
		cout << "待审核预约记录如下:" << endl;
		for (int i = 0;i < of.m_Size;i++) {
			if (of.m_OrderData[i]["status"] == "1") {
				v.push_back(i);
				cout << ++index << "、 ";
				cout << "预约日期: 周 " << of.m_OrderData[i]["date"];
				cout << "  时间段: " << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "  房间号: " << of.m_OrderData[i]["roomId"];
				string status = " 预约状态: 审核中";
				cout << status << endl;
			}
			/*else{
				cout << "无待审核的预约文件" << endl;
				system("pause");
				system("cls");
				break;
			}*/
		}
		cout << "请选择要审核的记录，0表示返回" << endl;
		int select = 0;
		int ret = 0;
		while (true) {
			cin >> select;
			if (select >= 0 && select <= v.size()) {
				if (select == 0) {
					break;
				}
				else {
					cout << "请输入审核的结果:" << endl;
					cout << "1--审核通过" << endl;
					cout << "2--审核不通过" << endl;
					cin >> ret;
					if (ret == 1) {
						of.m_OrderData[v[select - 1]]["status"] = "2";
					}
					else if (ret == 2) {
						of.m_OrderData[v[select - 1]]["status"] = "3";
					}
					of.updateOrder();
					cout << "审核完成！" << endl;
					break;
				}
			}
			else {
				cout << "输入有误，请重新输入" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}