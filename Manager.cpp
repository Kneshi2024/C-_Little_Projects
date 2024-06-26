#include"Manager.h"

Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
	this->initComVector();
}

//子菜单
void Manager::operMenu() {
	cout << "欢迎管理员" << this->m_Name << "登录！" << endl;
	cout << "\t\t -------------------------\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       1.添加账号        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       2.查看账号        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       3.查看机房        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       4.清空预约        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t|       0.注销登录        |\n";
	cout << "\t\t|                         |\n";
	cout << "\t\t -------------------------\n";
	cout << "请选择您的操作:" << endl;
}

//检测是否重复
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

//添加账号
void Manager::AddPerson() {
	string fileName;//操作的文件名
	string tip;//提示要输入id
	ofstream ofs;
	string errorTip;
	int select = 0;
	while (true) {
		cout << "请选择要添加的类别:" << endl;
		cout << "1--学生" << endl;
		cout << "2--老师" << endl;
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "请输入你的学号:";
			errorTip = "学号重复，请重新输入";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "请输入您的职工号:";
			errorTip = "职工号重复，请重新输入";

			break;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
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
	cout << "请输入你的姓名:" << endl;
	cin >> name;
	cout << "请输入你的密码" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initVector();
}

//输出打印学生函数
void PrintStudent(Student&s) {
	cout << "姓名: " << s.m_Name << "  学号: " << s.m_Id << "  密码: " << s.m_Pwd << endl;
}

//输出打印老师函数
void PrintTeacher(Teacher& t) {
	cout << "姓名: " << t.m_Name << "  职工号: " << t.m_EmpId << "  密码: " << t.m_Pwd << endl;
}

//查看账号
void Manager::ShowPerson() {
	cout << "请选择要查看的对象:" << endl;
	cout << "1--查看所有学生的信息" << endl;
	cout << "2--查看所有老师的信息" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "所有的学生信息如下:" << endl;
		for_each(vStu.begin(), vStu.end(), PrintStudent);
	}
	else if (select == 2) {
		cout << "所有的老师信息如下:" << endl;
		for_each(vTea.begin(), vTea.end(), PrintTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::ShowComputer() {
	cout << "机房的信息如下:" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++) {
		cout << "机房编号: " << it->m_ComId << "  机房最大容量: " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile() {
	cout << "是否清空所有记录？" << endl;
	cout << "1--清空" << endl;
	cout << "2--返回" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "已全部清空！" << endl;
	}
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector() {
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	else {
		Student s;
		while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
			vStu.push_back(s);
		}
	}
	cout << "当前学生数量为:" << vStu.size() << endl;   //测试代码
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
	}
	else {
		Teacher t;
		while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
			vTea.push_back(t);
		}
	}
	cout << "当前教师数量为:" <<vTea.size()<< endl;
	ifs.close();
}


//初始化机房信息
void Manager::initComVector() {
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为 :" << vCom.size() << endl;
}
