#include"Manager.h"

Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	this->initComVector();
}

//�Ӳ˵�
void Manager::operMenu() {
	cout << "��ӭ����Ա" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -------------------------\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.����˺�        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.�鿴�˺�        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       3.�鿴����        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       4.���ԤԼ        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.ע����¼        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t -------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//����Ƿ��ظ�
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin();it != vStu.end();it++) {
			if (id == (*it).m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++) {
			if (id == (*it).m_EmpId) {
				return true;
			}
		}
	}
	return false;
}

//����˺�
void Manager::AddPerson() {
	string fileName;//�������ļ���
	string tip;//��ʾҪ����id
	ofstream ofs;
	string errorTip;
	int select = 0;
	while (true) {
		cout << "��ѡ��Ҫ��ӵ����:" << endl;
		cout << "1--ѧ��" << endl;
		cout << "2--��ʦ" << endl;
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "���������ѧ��:";
			errorTip = "ѧ���ظ�������������";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "����������ְ����:";
			errorTip = "ְ�����ظ�������������";

			break;
		}
		else {
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret=this->checkRepeat(id,select );
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}
	cout << "�������������:" << endl;
	cin >> name;
	cout << "�������������" << endl;
	cin >> pwd;
	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}

//�����ӡѧ������
void PrintStudent(Student&s) {
	cout << "����: " << s.m_Name << "  ѧ��: " << s.m_Id << "  ����: " << s.m_Pwd << endl;
}

//�����ӡ��ʦ����
void PrintTeacher(Teacher& t) {
	cout << "����: " << t.m_Name << "  ְ����: " << t.m_EmpId << "  ����: " << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::ShowPerson() {
	cout << "��ѡ��Ҫ�鿴�Ķ���:" << endl;
	cout << "1--�鿴����ѧ������Ϣ" << endl;
	cout << "2--�鿴������ʦ����Ϣ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "���е�ѧ����Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else if (select == 2) {
		cout << "���е���ʦ��Ϣ����:" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::ShowComputer() {
	cout << "��������Ϣ����:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++) {
		cout << "�������: " << it->m_ComId << "  �����������: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile() {
	cout << "�Ƿ�������м�¼��" << endl;
	cout << "1--���" << endl;
	cout << "2--����" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "��ȫ����գ�" << endl;
	}
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector() {
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	else {
		Student s;
		while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
			vStu.push_back(s);
		}
	}
	cout << "��ǰѧ������Ϊ:" << vStu.size() << endl;   //���Դ���
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
	}
	else {
		Teacher t;
		while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
			vTea.push_back(t);
		}
	}
	cout << "��ǰ��ʦ����Ϊ:" <<vTea.size()<< endl;
	ifs.close();
}


//��ʼ��������Ϣ
void Manager::initComVector() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ :" << vCom.size() << endl;
}
