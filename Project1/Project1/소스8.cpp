#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <typeinfo>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <exception>
#include <utility>
using namespace std;
using namespace string_literals;
/*
class Mystring {
	char* string_content;
	int string_length;

	int memory_capacity;

public:
	Mystring();

	//���ڿ��κ��� ����
	Mystring(const char* str);

	//���� ������
	Mystring(const Mystring& str);

	//�̵� ������
	Mystring(Mystring&& str) noexcept ;

	//�Ϲ����� ���� ������
	Mystring &operator=(const Mystring &s);

	//�̵� ���� ������
	Mystring& operator=(Mystring&& s);

	~Mystring();

	int length() const;

	void println();
};

Mystring::Mystring() {
	cout << "������ ȣ��" << endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = nullptr;
}
Mystring::Mystring(const char *str) {
	cout << "������ ȣ��" << endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i < string_length; i++) string_content[i] = str[i];
}
Mystring::Mystring(const Mystring& str) {
	cout << "���� ������ ȣ��" << endl;
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	string_content = new char[string_length];

	for (int i = 0; i < string_length; i++)
		string_content[i] = str.string_content[i];
}
Mystring::Mystring(Mystring&& str) noexcept {
	cout << "�̵� ������ ȣ��" << endl;
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	string_content = str.string_content;

	//�ӽ� ��ü �Ҹ� �ÿ� �޸𸮸� ��������
	//���ϰ� �Ѵ�
	str.string_content = nullptr;
}
Mystring::~Mystring() {
	if (string_content) delete[] string_content;
}

Mystring &Mystring::operator=(const Mystring& s) {
	cout << "����" << endl;
	if (s.string_length > memory_capacity) {
		delete[] string_content;
		string_content = new char[s.string_length];
		memory_capacity = s.string_length;
	}
	string_length = s.string_length;
	for (int i = 0; i != string_length; i++) {
		string_content[i] = s.string_content[i];
	}

	return *this;
}
Mystring& Mystring::operator=(Mystring&& s) {
	cout << "�̵�" << endl;
	string_content = s.string_content;
	memory_capacity = s.memory_capacity;
	string_length = s.string_length;

	s.string_content = nullptr;
	s.memory_capacity = 0;
	s.string_length = 0;
	return *this;
}
int Mystring::length() const { return string_length; }
void Mystring::println() {
	for (int i = 0; i != string_length; i++) cout << string_content[i];
	cout << endl;
}
template <typename T>
void my_swap(T& a, T& b) {
	T tmp(move(a));
	a = move(b);
	b = move(tmp);
}
int main() {
	Mystring str1("abc");
	Mystring str2("def");
	cout << "Swap �� ---" << endl;
	cout << "str1 : ";
	str1.println();
	cout << "str2 : ";
	str2.println();

	cout << "Swap �� ---" << endl;
	my_swap(str1, str2);
	cout << "str1 : ";
	str1.println();
	cout << "str2 : ";
	str2.println();
}*/


//class A {
//public:
//	A() { cout << "�Ϲ� ������ ȣ��" << endl; }
//	A(const A& a) { cout << "���� ������ ȣ��" << endl; }
//	A(A&& a) { cout << "�̵� ������ ȣ��" << endl; }
//};

//int main() {
//A a;
//	cout << "----------" << endl;
//	A b(a);
//	cout << "----------" << endl;
//	A c(move(a));}

/*
class A {
	int data_;

public:
	A(int data) : data_(data) { cout << "�Ϲ� ������ ȣ��" << endl; }

	A(const A& a) : data_(a.data_) {
		cout << "���� ������ ȣ��" << endl;
	}
};
int main() {
	A a(1); //�Ϲ�
	A b(a); //����

	A c(A(2));
}*/

/*
int foo() noexcept {}
int bar() noexcept { throw 1;}

int main() {
	foo();
	try {
		bar();
	}
	catch (int x) {
		cout << "Error : " << x << endl;
	}
}
*/
/*
int func(int c) {
	if (c == 1) {
		throw 1;
	}else if (c == 2) {
		throw "hi";
	}else if (c == 3) {
		throw runtime_error("error");
	}
	return 0;
}
int main() {
	int c;
	cin >> c;
	try {
		func(c);
	}catch (int e) {
		cout << "Catch int : " << e << endl;
	}catch (...) {
		cout << "Default Catch!" << endl;
	}
}*/
/*
class Parent : public exception {
public:

	// what�� std::exception�� ���ǵ� �Լ���, �� ���ܰ� �������� �����ϴ� ���ڿ���
	// �����ϴ� �Լ��̴�.
	virtual const char* what() const noexcept override { return "Parent!\n"; }
};
class Child : public Parent {
public:
	const char* what() const noexcept override { return "Child!\n"; }
};

int func(int c) {
	if (c == 1) {
		throw Parent();
	}else if (c == 2) {
		throw Child();
	}
	return 0;
}
int main() {
	int c;
	cin >> c;

	try {
		func(c);
	}catch (Child& c) {
		cout << "Child Catch!" << endl;
		cout << c.what();
	}
	catch (Parent& p) {
		cout << "Parent Catch!" << endl;
		cout << p.what();
	}
}*/

/*
int func(int c) {
	if (c == 1) {
		throw 10;
	}else if(c == 2){
		throw string("hi");
	}else if(c == 3){
		throw 'a';
	}else if (c == 4) {
		throw "hello!";
	}
	return 0;
}
int main() {
	int c;
	cin >> c;

	try {
		func(c);
	}catch(char x){
		cout << "Char : " << x << endl;
	}catch (int x) {
		cout << "Int : " << x << endl;
	}catch (string& s) {
		cout << "String : " << s << endl;
	}catch(const char* s){
		cout << "String Literal : " << s << endl;
	}
}*/
/*
class Resource {
public:
	Resource(int id) : id_(id) {}
	~Resource() { cout << "���ҽ� ���� : " << id_ << endl; }

private:
	int id_;
};
int func3() {
	Resource r(3);
	throw runtime_error("Exception from 3!\n"); //throw�� �ϰ� �Ǹ� ���� ����� catch�� �����Ѵ�.
}
int func2() {
	Resource r(2);
	func3();
	cout << "���� �ȵ�!" << endl;
	return 0;
}
int func1() {
	Resource r(1);
	func2();
	cout << "���� �ȵ�!" << endl;
	return 0;
}
int main() {
	try {
		func1();
	}catch (exception& e) { // <<-- �����
		cout << "Exception : " << e.what();
	}
}*/

/*
template <typename T>
class Vector {
public:
	Vector(size_t size) : size_(size) {
		data_ = new T[size_];
		for (int i = 0; i < size_; i++) {
			data_[i] = 3;
		}
	}
	const T& at(size_t index) const {
		if (index >= size_) {
			//���ܸ� �߻���Ų��!
			throw out_of_range("vector�� index�� ������ �ʰ��Ͽ����ϴ�.");
		}
		return data_[index];
	}
	~Vector() { delete[] data_; }

private:
	T* data_;
	size_t size_;
};
int main() {
	Vector<int> vec(3);

	int index, data = 0;
	cin >> index;

	try {
		data = vec.at(index);
	}
	catch (out_of_range& e) { //catch���� throw �� ���ܸ� �޴� �κ��ε�, catch �� �ȿ� ���ǵ� ������ �ÿ� �´� ��ü�� �޴´�.
		cout << "���� �߻� ! " << e.what() << endl;
	}
	//���ܰ� �߻����� �ʾҴٸ� 3�� ��µǰ�, ���ܰ� �߻��Ͽ��ٸ� ���� data��
	//�� �ִ� 0 �� ��µȴ�.
	cout << "���� ������ : " << data << endl;

}*/

/*
int main(){

	u32string u32_str = U"�̰� UTF-32 ���ڿ� �Դϴ�";
	cout << u32_str.size() << endl;
}
*/
/*
int main() {
	string str = R"doo(
)"; <-- ���õ�
)doo";
	cout << str;
}*/
/*
int main() {
	auto s1 = "hello"s; //c++14 �������� ���� ���ͷ� ������ 
	cout << "s1 �� ���� : " << s1.size() << endl; 
}*/

/*
//�̿� ���� new�� ���� �Լ��� �����ϸ� ��� new �����ڸ� �����ε��ع�����
//(� Ŭ������ ��� �Լ��� �����ϸ� �ش� Ŭ������ new�� �����ε���)
void* operator new(size_t count) {
	cout << count << " bytes �Ҵ� " << endl;
	return malloc(count);
}

int main() {
	cout << "s1 ���� --- " << endl;
	string s1 = "this is a pretty long sentence!!!";
	cout << "s1 ũ�� : " << sizeof(s1) << endl;

	cout << "s2 ���� --- " << endl;
	string s2 = "short";
	cout << "s2 ũ�� : " << sizeof(s2) << endl;
}*/

/*
template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << "[" << *begin << "] ";
		begin++;
	}
	cout << endl;
}

struct User {
	string name;
	int level;

	User(string name, int level) : name(name), level(level) {}
	bool operator==(const User& user)const {
		if (name == user.name && level == user.level) return true;
		return false;
	}
};

class Party {
	vector<User> users;

public:
	bool add_user(string name, int level) {
		User new_user(name, level);
		if (find(users.begin(), users.end(), new_user) != users.end()) {
			return false;
		}
		users.push_back(new_user);
		return true;
	}

	//��Ƽ�� ��ΰ� 15���� �̻��̾���� ���� ���� ����
	bool can_join_dungeon() {
		return all_of(users.begin(), users.end(), //all_of �Լ� AND ����� ���
			[](User& user) {return user.level >= 15; });
	}

	//��Ƽ�� �� �Ѹ��̶� 19���� �̻��̾���� ����� ������ ��� ����
	bool can_use_special_item() {
		return any_of(users.begin(), users.end(), //any_of �Լ� OR ����� ���
			[](User& user) {return user.level >= 19; });
	}
};
int main() {
	Party party;
	party.add_user("ö��", 15);
	party.add_user("����", 18);
	party.add_user("����", 13);
	party.add_user("�ξ�", 19);

	cout << boolalpha;
	cout << "���� ���� ���� ? " << party.can_join_dungeon() << endl;
	cout << "Ư�� ������ ��� ����? " << party.can_use_special_item() << endl;
}*/

/*
template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << "[" << *begin << "] ";
		begin++;
	}
	cout << endl;
}

int main() {
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	//find �Լ�
	auto current = vec.begin();
	while (true) {
		current = find_if(current, vec.end(), [](int i) {return i % 3 == 2; }); // find_if �Լ��� ���� �Լ� ���
		if (current == vec.end()) break;
		cout << "3 ���� ���� �������� 2�� ���Ҵ� : " << *current << " �̴� " << endl;
		current++;
	}
	//auto result = find(vec.begin(), vec.end(), 3); //�ϳ��� 3 �� ã��ʹٸ�
	//cout << "3 �� " << distance(vec.begin(), result) + 1 << " ��° ����" << endl;
}*/