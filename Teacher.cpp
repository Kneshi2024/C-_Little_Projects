#include"Teacher.h"

Teacher::Teacher() {

}
Teacher::Teacher(int empid, string name, string pwd) {
	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�Ӳ˵�
void Teacher::operMenu() {
	cout << "��ӭ��ʦ:" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -------------------------\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.�鿴����ԤԼ    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.���ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.ע����¼        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t -------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//��ʾ����ԤԼ
void Teacher::ShowAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0;i < of.m_Size;i++) {
			cout << i + 1 << "��" << " ";
			cout << "ԤԼ����: ��" << of.m_OrderData[i]["date"];
			cout << "  ʱ���: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "  ѧ��: " << of.m_OrderData[i]["stuId"];
			cout << "  ����: " << of.m_OrderData[i]["stuName"];
			cout << "  ������: " << of.m_OrderData[i]["roomId"];
			string status = "  ԤԼ״̬: ";
			if (of.m_OrderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2") {
				status += "��ԤԼ";
			}
			else if (of.m_OrderData[i]["status"] == "3") {
				status += "ԤԼʧ��";
			}
			else if (of.m_OrderData[i]["status"] == "0") {
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::ValidOrder() {
	vector<int>v;
	OrderFile of;
	int index = 0;
	if (of.m_Size == 0) {
		cout << "ԤԼ�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
			return;
	}
	else {
		cout << "�����ԤԼ��¼����:" << endl;
		for (int i = 0;i < of.m_Size;i++) {
			if (of.m_OrderData[i]["status"] == "1") {
				v.push_back(i);
				cout << ++index << "�� ";
				cout << "ԤԼ����: �� " << of.m_OrderData[i]["date"];
				cout << "  ʱ���: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "  �����: " << of.m_OrderData[i]["roomId"];
				string status = " ԤԼ״̬: �����";
				cout << status << endl;
			}
			/*else{
				cout << "�޴���˵�ԤԼ�ļ�" << endl;
				system("pause");
				system("cls");
				break;
			}*/
		}
		cout << "��ѡ��Ҫ��˵ļ�¼��0��ʾ����" << endl;
		int select = 0;
		int ret = 0;
		while (true) {
			cin >> select;
			if (select >= 0 && select <= v.size()) {
				if (select == 0) {
					break;
				}
				else {
					cout << "��������˵Ľ��:" << endl;
					cout << "1--���ͨ��" << endl;
					cout << "2--��˲�ͨ��" << endl;
					cin >> ret;
					if (ret == 1) {
						of.m_OrderData[v[select - 1]]["status"] = "2";
					}
					else if (ret == 2) {
						of.m_OrderData[v[select - 1]]["status"] = "3";
					}
					of.updateOrder();
					cout << "�����ɣ�" << endl;
					break;
				}
			}
			else {
				cout << "������������������" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}