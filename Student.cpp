#include"Student.h"



Student::Student() {

}
Student::Student(int id, string name, string pwd) {
	this->m_Name = name;
	this->m_Id = id;
	this->m_Pwd = pwd;
	this->initComVector();
}

//�����ض����Ӳ˵�
void Student::operMenu() {
	cout << "��ӭѧ������:" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -------------------------\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.����ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.�鿴�ҵ�ԤԼ    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       3.�鿴����ԤԼ    |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       4.ȡ��ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.ע����¼        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t -------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//����ԤԼ
void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ��:" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date=0;//����
	int inteval=0;//ʱ���
	int room=0;//�����

	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5) {
			break;
		}
		else {
			cout << "������������������:" << endl;
		}
	}

	cout << "����������ԤԼʱ���:" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true) {
		cin >> inteval;
		if (inteval >= 1 && inteval <= 2) {
			break;
		}
		else {
			cout << "�����������������룡" << endl;
		}
	}

	cout << "��ѡ�����:" << endl;

	for (int i = 0;i < vCom.size();i++) {
		cout << vCom[i].m_ComId<< "�Ż���������Ϊ:" << vCom[i].m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		else {
			cout << "�����������������룡" << endl;
		}
	}

	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << inteval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::ShowMyOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0;i < of.m_Size;i++) {
			if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str())) {
				cout << "ԤԼ����: ��" << of.m_OrderData[i]["date"];
				cout << "  ʱ���: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "  ������: " << of.m_OrderData[i]["roomId"];
				string status="  ԤԼ״̬: ";
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
				cout<<status<<endl;

			}
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::ShowAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		for (int i = 0;i < of.m_Size;i++) {
			cout << i+1<<"��" << " ";
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

//ȡ��ԤԼ
void Student::CancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "�ļ�Ϊ�գ��޷�ɾ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "����л�ԤԼ�ɹ��ļ�¼����ɾ����������Ҫɾ���ļ�¼" << endl;
		vector<int> v;
		int index = 1;
		for (int i = 0;i < of.m_Size;i++) {
			if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str())) {
				if (of.m_OrderData[i]["status"] == "1"||of.m_OrderData[i]["status"] == "2") {
					v.push_back(i);
					/*for (vector<int>::iterator it = v.begin();it != v.end();it++) {
						cout << *it << endl;
					}*/
					cout << index++ << "�� ";
					cout << "ԤԼʱ��:  ��" << of.m_OrderData[i]["date"] ;
					cout << "  ʱ���: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
					cout << "  �����: " << of.m_OrderData[i]["roomId"] ;
					string status = " ״̬: ";
					if (of.m_OrderData[i]["status"] == "1") {
						status += "�����";
					}
					else if (of.m_OrderData[i]["status"] == "2") {
						status += "ԤԼ�ɹ�";
					}
					cout << status << endl;
					
				}
			}
		}
		cout << "������ȡ���ļ�¼��0��ʾ����" << endl;
		int select = 0;
		while (true) {
			cin >> select;
			if (select >= 0 && select<=v.size()) {
				if (select == 0) {
					break;
				}
				else {
					of.m_OrderData[v[select-1]]["status"]="0";
					of.updateOrder();
					cout << "��ȡ��ԤԼ" << endl;
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

void Student::initComVector() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	ifs.close();
}