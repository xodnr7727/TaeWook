/*
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;*/

/*
int main() {
	//파일 읽기 준비
	ifstream in("text.txt");
	char buf[100];

	if (!in.is_open()) {
		cout << "파일을 찾을 수 없습니다!" << endl;
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
	//파일 읽기 준비
	ifstream in("text.txt");
	string s;

	if (in.is_open()) {
		//위치 지정자를 파일 끝으로 옭긴다.
		in.seekg(0, ios::end);

		//그리고 그 위치를 읽는다. ( 파일의 크기 )
		int size = in.tellg();

		//그 크기의 문자열을 할당한다.
		s.resize(size);

		//위치 지정자를 다시 파일 맨 앞으로 옮긴다.
		in.seekg(0, ios::beg);

		//파일 전체 내용을 읽어서 문자열에 저장한다.
		in.read(&s[0], size);
		cout << s << endl;
	}else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}
	return 0;
}*/
/*
int main() {
	// 파일 읽기 준비
	std::ifstream in("test.txt");
	std::string s;

	if(in.is_open()){
	in >> s;
		cout << "입력 받은 문자열 :: " << s << endl;
	}else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	in.close();
	in.open("other.txt");

	if (in.is_open()) {
		in >> s;
		cout << "입력 받은 문자열 :: " << s << endl;
	}
	else {
		cout << "파일을 찾을 수 없습니다!" << endl;
	}

	return 0;
}*/
/*
int main() {
	string s;
	cin >> s;

	char peek = cin.rdbuf()->snextc();
	if (cin.fail()) cout << "Failed";
	cout << "두 번째 단어 맨 앞 글자 : " << peek << endl;
	cin >> s;
	cout << "다시 읽으면 : " << s <<endl;
}*/

/*
int main() {
	int t;
	while (true) {
		cin >> hex >> t;  //조작자 hex 사용, 여기서 hex 는 ios 에 정의되어 있는 함수 
		cout << "입력 : " << t << endl;
		if (cin.fail()) {
			cout << "제대로 입력해주세요" << endl;
			cin.clear(); //플래그들을 초기화 하고
			cin.ignore(100, '\n'); //개행문자가 나올 떄 까지 무시한다.
		}
		if (t == 1) break;
	}
}*/

/*
int main() {
	int t;
	while (true) {
		cin.setf(ios_base::hex , ios_base::basefield); //형식 플래그 hex 사용 여기서 hex는 ios_base에 선언되어 있는 단순한 상수 '값'
		cin >> t;
		cout << "입력 : " << t << endl;
		if (cin.fail()) {
			cout << "제대로 입력해주세요" << endl;
			cin.clear(); //플래그들을 초기화 하고
			cin.ignore(100, '\n'); //개행문자가 나올 떄 까지 무시한다.
		}
		if (t == 1) break;
	}
}*/

/*
int main() {
	int t;
	while (true) {
		cin >> t;
		cout << "입력 : " << t << endl;
		if (cin.fail()) {
			cout << "제대로 입력해주세요" << endl;
			cin.clear();           //플래그들을 초기화 하고
			cin.ignore(100, '\n'); //개행문자가 나올 떄 까지 무시한다.
		}
		if (t == 1) break;
	}
}*/

/*
int main() {
	int t;
	cin >> t; //고의적으로 문자를 입력하면 failbit 가 켜진다.
	cout << "fail 비트가 켜진 상태이므로, 입력받지 않는다" << endl;
	string s;
	cin >> s;
}*/
/*
class Human { //다이아몬드 상속의 해결 방법 
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

	A() { cout << "A 생성자 호출" << endl; }
};

class B {
public:
	int b;

	B() { cout << "B 생성자 호출" << endl; }
};

class C : public A, public B {
public:
	int c;

	C() : A(), B() { cout << "C 생성자 호출" << endl; }
};
int main() {
	C c;
}*/
/*
class Animal { //추상 클래스
public:
	Animal() {} 
	virtual ~Animal() {}
	virtual void speak() = 0; 
};
class Dog : public Animal {
public:
	void speak() override { cout << "왈왈" << endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { cout << "야옹" << endl; }
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
	Parent() { cout << "Parent 생성자 호출" << endl; }
	virtual ~Parent() { cout << "Parent 소멸자 호출" << endl; }
};
class Child : public Parent {
public:
	Child() { cout << "Chlid 생성자 호출" << endl;}
	~Child() { cout << "Chlid 소멸자 호출" << endl; }
};
int main() {
	cout << "--- 평범한 Child 만들었을때 ---" << endl;
	{Child c; }
	cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << endl;
	{
		Parent* p = new Child();
		delete p;
	}
}*/

/*
class Base {
	string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	string s;

public:
	Derived() : s("파생") ,Base() { cout << "파생 클래스 " << endl;
		
	void what() override { cout << s << endl; } 
	// C +11에서는 파생 클래스에서 기반 클래스의 가상 함수를 오버라이드 하는 경우, override 키워드를 통해서 명시적으로 나타낼 수 있습니다.
};*/
/*
class Base {

public:
	Base() { cout << "기반 클래스" << endl; }

	virtual void what() { cout << "기반 클래스의 what()" << endl; } //가상함수
};

class Derived : public Base {

public:
	Derived() : Base() { cout << "파생 클래스" << endl; }
	
	void what() { cout << "파생 클래스의 what()" << endl; }
	//파생 클래스의 함수가 기반 클래스의 함수를 오버라이드 하기 위해서는 두 함수의 꼴이 정확히 같아야 한다.
};
int main() {
	Base p;
	Derived c;

	Base* p_c = &c; 
	Base* p_p = &p;

	cout << " === 실제 객체는 Base === " << endl;
	p_p->what();

	cout << " === 실제 객체는 Derived === " << endl;
	p_c->what();

	return 0;
}*/

/*
class Base {
	string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	string s;

public:
		Derived() : Base(), s("파생") {
			std::cout << "파생 클래스 " << std::endl;

			what();
		}
		void what() { cout << s << endl; } // 같은 이름이어도 (인자도 같지만) 다른 클래스에 정의 되어 있는 것이기 때문에 다른 함수로 취급된다.
};
int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	return 0;
}
*/
/*
class Employee {
protected:
	string name;
	int age;

	string position; //직책 (이름)
	int rank;        // 순위 (값이 클 수록 높은 순위)

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank){}

//복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

//디폴트 생성자
	Employee() {}

	virtual void print_info() {
		cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "만원" << endl;
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
				<< year_of_service << "년차) ==> " << calculate_pay() << "만원"
				<< endl;
	}
};

class EmployeeList {
	int alloc_employee; //할당한 총 직원 수
	int current_employee; //현재 직원 수
	Employee **employee_list; //직원 데이터

public: 

	Employeelist(int alloc_employee) : alloc_employee(alloc_employee){
		employee_list = new Employee*[alloc_employee];

		current_employee = 0;
	}

	void add_employee(Employee* employee) {
		//사실 current_employee 보다 alloc_employee가 더
		//많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
		//최대한 단순하게 생각해서 alloc_employee 는
		//언제나 current_employee보다 크다고 생각한다.
		//(즉 할당된 크기는 현재 총 직원수 보다 많음)
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

		cout << "총 비용 : " << total_pay << "만원 " << endl;
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
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

	emp_list.add_employee(new Employee("유재석", 41, "부장", 7));
	emp_list.add_employee(new Employee("정준한", 43, "과장", 4));
	emp_list.add_employee(new Employee("박명수", 43, "차장", 5));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36,  "인턴", -2));
	emp_list.print_employee_info();
	return 0;
}
*/
/*
int main() {
	string s = "abc";
	string t = "def";
	string s2 = s;

	cout << s << " 의 길이 : " << s.length() << endl;
	cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t << endl;

	if (s == s2) {
		cout << s << " 와 " << s2 << " 는 같다 " << endl;
	}
	if (s != t) {
		cout << s << " 와 " << t << " 는 다르다 " << endl;
	}

	return 0;
}*/