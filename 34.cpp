#include<iostream>
#include"globalFile.h"
#include<fstream>
#include"Identify.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"

using namespace std;


//����Ա����
void managerMenu(Identify *&manager){
	while (true) {
		manager->operMenu();
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//cout << "����˺�" << endl;
			man->AddPerson();
		}
		else if (select == 2) {
			//cout << "�鿴�˺�" << endl;
			man->ShowPerson();
		}
		else if (select == 3) {
			//cout << "�鿴����" << endl;
			man->ShowComputer();
		}
		else if (select == 4) {
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ������
void studentMenu(Identify*&student) {
	while (true) {
		student->operMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1) {
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴�Լ���ԤԼ
			stu->ShowMyOrder();
		}
		else if (select == 3) {
			//�鿴����ԤԼ
			stu->ShowAllOrder();
		}
		else if (select == 4) {
			//ȡ��ԤԼ
			stu->CancelOrder();
		}
		else {
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ����
void teacherMenu(Identify*&teacher) {
	while (true) {
		teacher->operMenu();
		Teacher* t = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1) {
			t->ShowAllOrder();
		}
		else if (select == 2) {
			t->ValidOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}


void LoginIn(string filename,int type) {
	//����ָ�룬����ָ���������
	Identify* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û�����Ϣ
	int id=0;
	string name;
	string pwd;

	//�ж��û���Ϣ
	if (type == 1) {
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ�����:" << endl;
		cin >> id;
	}

	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ�������֤
		int fid;//���ļ��ж�ȡ��id��
		string fname;//���ļ��ж�ȡ������
		string fpwd;//���ļ��ж�ȡ������
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "ѧ����¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ�����֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && pwd == fpwd) {
				cout << "��ʦ��¼��֤�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�����ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա�����֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && pwd == fpwd) {
				cout << "����Ա��¼��֤�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager( name, pwd);

				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��¼��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}



int main() {
	int select = 0;
	while (true) {
		cout << "--------------  ��ӭ��������ԤԼϵͳ  --------------" << endl;
		cout << endl << "�������������:" << endl;
		cout << "\t\t -------------------------\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       1.ѧ������        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       2.��    ʦ        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       3.�� �� Ա        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t|       0.��    ��        |\n";
		cout << "\t\t|                         |\n";
		cout << "\t\t -------------------------\n";
		cout << "����������ѡ��:" << endl;
		cin >> select;
		switch (select){
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;

			break;
		default:
			cout << "������������������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return(0);
}