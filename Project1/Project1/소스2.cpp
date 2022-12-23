/*
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;*/

/*
int main() {
	//���� �б� �غ�
	ifstream in("text.txt");
	char buf[100];

	if (!in.is_open()) {
		cout << "������ ã�� �� �����ϴ�!" << endl;
		return 0;
	}
	while (in) {
		in.getline(buf, 100, '.');
		cout << buf << endl;
	}
	return 0;
}*/
/*
int main() {
	//���� �б� �غ�
	ifstream in("text.txt");
	string s;

	if (in.is_open()) {
		//��ġ �����ڸ� ���� ������ �ı��.
		in.seekg(0, ios::end);

		//�׸��� �� ��ġ�� �д´�. ( ������ ũ�� )
		int size = in.tellg();

		//�� ũ���� ���ڿ��� �Ҵ��Ѵ�.
		s.resize(size);

		//��ġ �����ڸ� �ٽ� ���� �� ������ �ű��.
		in.seekg(0, ios::beg);

		//���� ��ü ������ �о ���ڿ��� �����Ѵ�.
		in.read(&s[0], size);
		cout << s << endl;
	}else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}
	return 0;
}*/
/*
int main() {
	// ���� �б� �غ�
	std::ifstream in("test.txt");
	std::string s;

	if(in.is_open()){
	in >> s;
		cout << "�Է� ���� ���ڿ� :: " << s << endl;
	}else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	in.close();
	in.open("other.txt");

	if (in.is_open()) {
		in >> s;
		cout << "�Է� ���� ���ڿ� :: " << s << endl;
	}
	else {
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	return 0;
}*/
/*
int main() {
	string s;
	cin >> s;

	char peek = cin.rdbuf()->snextc();
	if (cin.fail()) cout << "Failed";
	cout << "�� ��° �ܾ� �� �� ���� : " << peek << endl;
	cin >> s;
	cout << "�ٽ� ������ : " << s <<endl;
}*/

/*
int main() {
	int t;
	while (true) {
		cin >> hex >> t;  //������ hex ���, ���⼭ hex �� ios �� ���ǵǾ� �ִ� �Լ� 
		cout << "�Է� : " << t << endl;
		if (cin.fail()) {
			cout << "����� �Է����ּ���" << endl;
			cin.clear(); //�÷��׵��� �ʱ�ȭ �ϰ�
			cin.ignore(100, '\n'); //���๮�ڰ� ���� �� ���� �����Ѵ�.
		}
		if (t == 1) break;
	}
}*/

/*
int main() {
	int t;
	while (true) {
		cin.setf(ios_base::hex , ios_base::basefield); //���� �÷��� hex ��� ���⼭ hex�� ios_base�� ����Ǿ� �ִ� �ܼ��� ��� '��'
		cin >> t;
		cout << "�Է� : " << t << endl;
		if (cin.fail()) {
			cout << "����� �Է����ּ���" << endl;
			cin.clear(); //�÷��׵��� �ʱ�ȭ �ϰ�
			cin.ignore(100, '\n'); //���๮�ڰ� ���� �� ���� �����Ѵ�.
		}
		if (t == 1) break;
	}
}*/

/*
int main() {
	int t;
	while (true) {
		cin >> t;
		cout << "�Է� : " << t << endl;
		if (cin.fail()) {
			cout << "����� �Է����ּ���" << endl;
			cin.clear();           //�÷��׵��� �ʱ�ȭ �ϰ�
			cin.ignore(100, '\n'); //���๮�ڰ� ���� �� ���� �����Ѵ�.
		}
		if (t == 1) break;
	}
}*/

/*
int main() {
	int t;
	cin >> t; //���������� ���ڸ� �Է��ϸ� failbit �� ������.
	cout << "fail ��Ʈ�� ���� �����̹Ƿ�, �Է¹��� �ʴ´�" << endl;
	string s;
	cin >> s;
}*/
/*
class Human { //���̾Ƹ�� ����� �ذ� ��� 
public:
	// ...
};
class HandsomeHuman : public virtual Human {
	// ...
};
class SmartHuman : public virtual Human {
	// ...
};
class Me : public HandsomeHuman, public SmartHuman {
	// ...
};*/
/*
class A {
public:
	int a;

	A() { cout << "A ������ ȣ��" << endl; }
};

class B {
public:
	int b;

	B() { cout << "B ������ ȣ��" << endl; }
};

class C : public A, public B {
public:
	int c;

	C() : A(), B() { cout << "C ������ ȣ��" << endl; }
};
int main() {
	C c;
}*/
/*
class Animal { //�߻� Ŭ����
public:
	Animal() {} 
	virtual ~Animal() {}
	virtual void speak() = 0; 
};
class Dog : public Animal {
public:
	void speak() override { cout << "�п�" << endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { cout << "�߿�" << endl; }
};
int main() {
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
}
*/
/*
class Parent {
public:
	Parent() { cout << "Parent ������ ȣ��" << endl; }
	virtual ~Parent() { cout << "Parent �Ҹ��� ȣ��" << endl; }
};
class Child : public Parent {
public:
	Child() { cout << "Chlid ������ ȣ��" << endl;}
	~Child() { cout << "Chlid �Ҹ��� ȣ��" << endl; }
};
int main() {
	cout << "--- ����� Child ��������� ---" << endl;
	{Child c; }
	cout << "--- Parent �����ͷ� Child �������� �� ---" << endl;
	{
		Parent* p = new Child();
		delete p;
	}
}*/

/*
class Base {
	string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	string s;

public:
	Derived() : s("�Ļ�") ,Base() { cout << "�Ļ� Ŭ���� " << endl;
		
	void what() override { cout << s << endl; } 
	// C +11������ �Ļ� Ŭ�������� ��� Ŭ������ ���� �Լ��� �������̵� �ϴ� ���, override Ű���带 ���ؼ� ��������� ��Ÿ�� �� �ֽ��ϴ�.
};*/
/*
class Base {

public:
	Base() { cout << "��� Ŭ����" << endl; }

	virtual void what() { cout << "��� Ŭ������ what()" << endl; } //�����Լ�
};

class Derived : public Base {

public:
	Derived() : Base() { cout << "�Ļ� Ŭ����" << endl; }
	
	void what() { cout << "�Ļ� Ŭ������ what()" << endl; }
	//�Ļ� Ŭ������ �Լ��� ��� Ŭ������ �Լ��� �������̵� �ϱ� ���ؼ��� �� �Լ��� ���� ��Ȯ�� ���ƾ� �Ѵ�.
};
int main() {
	Base p;
	Derived c;

	Base* p_c = &c; 
	Base* p_p = &p;

	cout << " === ���� ��ü�� Base === " << endl;
	p_p->what();

	cout << " === ���� ��ü�� Derived === " << endl;
	p_c->what();

	return 0;
}*/

/*
class Base {
	string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	string s;

public:
		Derived() : Base(), s("�Ļ�") {
			std::cout << "�Ļ� Ŭ���� " << std::endl;

			what();
		}
		void what() { cout << s << endl; } // ���� �̸��̾ (���ڵ� ������) �ٸ� Ŭ������ ���� �Ǿ� �ִ� ���̱� ������ �ٸ� �Լ��� ��޵ȴ�.
};
int main() {
	std::cout << " === ��� Ŭ���� ���� ===" << std::endl;
	Base p;

	std::cout << " === �Ļ� Ŭ���� ���� ===" << std::endl;
	Derived c;

	return 0;
}
*/
/*
class Employee {
protected:
	string name;
	int age;

	string position; //��å (�̸�)
	int rank;        // ���� (���� Ŭ ���� ���� ����)

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank){}

//���� ������
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

//����Ʈ ������
	Employee() {}

	virtual void print_info() {
		cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "����" << endl;
	}
	virtual int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
	int year_of_service;

public:
	Manager(string name, int age, string position, int rank,
		int year_of_service)
		:year_of_service(year_of_service), Employee(name, age, position,rank) {}

	Manager(const Manager& manager) {
		Employee(name = manager.name,age = manager.age,position = manager.position, rank = manager.rank) {
		year_of_service = manager.year_of_service;
	}

	Manager() : Employee() {}

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }

	void print_info() {
		   cout << name << " (" << position << " , " << age << ", "
				<< year_of_service << "����) ==> " << calculate_pay() << "����"
				<< endl;
	}
};

class EmployeeList {
	int alloc_employee; //�Ҵ��� �� ���� ��
	int current_employee; //���� ���� ��
	Employee **employee_list; //���� ������

public: 

	Employeelist(int alloc_employee) : alloc_employee(alloc_employee){
		employee_list = new Employee*[alloc_employee];

		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		//��� current_employee ���� alloc_employee�� ��
		//�������� ��� �ݵ�� ���Ҵ��� �ؾ� ������, ���⼭��
		//�ִ��� �ܼ��ϰ� �����ؼ� alloc_employee ��
		//������ current_employee���� ũ�ٰ� �����Ѵ�.
		//(�� �Ҵ�� ũ��� ���� �� ������ ���� ����)
		employee_list[current_employee] = employee;
		current_employee++;
	}

	int current_employee_info() { return current_employee + current_manager; }

	void print_employee_info() {
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) {
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}

		for (int i = 0; i < current_manager; i++) {
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}

		cout << "�� ��� : " << total_pay << "���� " << endl;
	}
	~EmployeeList() {
		for (int i = 0; i < current_employee; i++) {
			delete employee_list[i];
		}
		for (int i = 0; i < current_manager; i++) {
			delete manager_list[i];
		}
		delete[] employee_list;
		delete[] manager_list;
	}
};

int main() {
	EmployeeList emp_list(10);
	emp_list.add_employee(new Employee("��ȫö", 34, "����", 1));
	emp_list.add_employee(new Employee("����", 34, "����", 1));

	emp_list.add_employee(new Employee("���缮", 41, "����", 7));
	emp_list.add_employee(new Employee("������", 43, "����", 4));
	emp_list.add_employee(new Employee("�ڸ��", 43, "����", 5));
	emp_list.add_employee(new Employee("������", 36, "�븮", 2));
	emp_list.add_employee(new Employee("��", 36,  "����", -2));
	emp_list.print_employee_info();
	return 0;
}
*/
/*
int main() {
	string s = "abc";
	string t = "def";
	string s2 = s;

	cout << s << " �� ���� : " << s.length() << endl;
	cout << s << " �ڿ� " << t << " �� ���̸� : " << s + t << endl;

	if (s == s2) {
		cout << s << " �� " << s2 << " �� ���� " << endl;
	}
	if (s != t) {
		cout << s << " �� " << t << " �� �ٸ��� " << endl;
	}

	return 0;
}*/