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

	//문자열로부터 생성
	Mystring(const char* str);

	//복사 생성자
	Mystring(const Mystring& str);

	//이동 생성자
	Mystring(Mystring&& str) noexcept ;

	//일반적인 대입 연산자
	Mystring &operator=(const Mystring &s);

	//이동 대입 연산자
	Mystring& operator=(Mystring&& s);

	~Mystring();

	int length() const;

	void println();
};

Mystring::Mystring() {
	cout << "생성자 호출" << endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = nullptr;
}
Mystring::Mystring(const char *str) {
	cout << "생성자 호출" << endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i < string_length; i++) string_content[i] = str[i];
}
Mystring::Mystring(const Mystring& str) {
	cout << "복사 생성자 호출" << endl;
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	string_content = new char[string_length];

	for (int i = 0; i < string_length; i++)
		string_content[i] = str.string_content[i];
}
Mystring::Mystring(Mystring&& str) noexcept {
	cout << "이동 생성자 호출" << endl;
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	string_content = str.string_content;

	//임시 객체 소멸 시에 메모리를 해제하지
	//못하게 한다
	str.string_content = nullptr;
}
Mystring::~Mystring() {
	if (string_content) delete[] string_content;
}

Mystring &Mystring::operator=(const Mystring& s) {
	cout << "복사" << endl;
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
	cout << "이동" << endl;
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
	cout << "Swap 전 ---" << endl;
	cout << "str1 : ";
	str1.println();
	cout << "str2 : ";
	str2.println();

	cout << "Swap 후 ---" << endl;
	my_swap(str1, str2);
	cout << "str1 : ";
	str1.println();
	cout << "str2 : ";
	str2.println();
}*/


//class A {
//public:
//	A() { cout << "일반 생성자 호출" << endl; }
//	A(const A& a) { cout << "복사 생성자 호출" << endl; }
//	A(A&& a) { cout << "이동 생성자 호출" << endl; }
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
	A(int data) : data_(data) { cout << "일반 생성자 호출" << endl; }

	A(const A& a) : data_(a.data_) {
		cout << "복사 생성자 호출" << endl;
	}
};
int main() {
	A a(1); //일반
	A b(a); //복사

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

	// what은 std::exception에 정의된 함수로, 이 예외가 무엇인지 설명하는 문자열을
	// 리턴하는 함수이다.
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
	~Resource() { cout << "리소스 해제 : " << id_ << endl; }

private:
	int id_;
};
int func3() {
	Resource r(3);
	throw runtime_error("Exception from 3!\n"); //throw를 하게 되면 가장 가까운 catch로 점프한다.
}
int func2() {
	Resource r(2);
	func3();
	cout << "실행 안됨!" << endl;
	return 0;
}
int func1() {
	Resource r(1);
	func2();
	cout << "실행 안됨!" << endl;
	return 0;
}
int main() {
	try {
		func1();
	}catch (exception& e) { // <<-- 여기로
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
			//예외를 발생시킨다!
			throw out_of_range("vector의 index가 범위를 초과하였습니다.");
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
	catch (out_of_range& e) { //catch문은 throw 된 예외를 받는 부분인데, catch 문 안에 정의된 예외의 꼴에 맞는 객체를 받는다.
		cout << "예외 발생 ! " << e.what() << endl;
	}
	//예외가 발생하지 않았다면 3이 출력되고, 예외가 발생하였다면 원래 data에
	//들어가 있던 0 이 출력된다.
	cout << "읽은 데이터 : " << data << endl;

}*/

/*
int main(){

	u32string u32_str = U"이건 UTF-32 문자열 입니다";
	cout << u32_str.size() << endl;
}
*/
/*
int main() {
	string str = R"doo(
)"; <-- 무시됨
)doo";
	cout << str;
}*/
/*
int main() {
	auto s1 = "hello"s; //c++14 에서부터 사용된 리터럴 연산자 
	cout << "s1 의 길이 : " << s1.size() << endl; 
}*/

/*
//이와 같이 new를 전역 함수로 정의하면 모든 new 연산자를 오버로딩해버린다
//(어떤 클래스의 멤버 함수로 정의하면 해당 클래스의 new만 오버로딩됨)
void* operator new(size_t count) {
	cout << count << " bytes 할당 " << endl;
	return malloc(count);
}

int main() {
	cout << "s1 생성 --- " << endl;
	string s1 = "this is a pretty long sentence!!!";
	cout << "s1 크기 : " << sizeof(s1) << endl;

	cout << "s2 생성 --- " << endl;
	string s2 = "short";
	cout << "s2 크기 : " << sizeof(s2) << endl;
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

	//파티원 모두가 15레벨 이상이어야지 던전 입장 가능
	bool can_join_dungeon() {
		return all_of(users.begin(), users.end(), //all_of 함수 AND 연산과 비슷
			[](User& user) {return user.level >= 15; });
	}

	//파티원 중 한명이라도 19레벨 이상이어야지 스페셜 아이템 사용 가능
	bool can_use_special_item() {
		return any_of(users.begin(), users.end(), //any_of 함수 OR 연산과 비슷
			[](User& user) {return user.level >= 19; });
	}
};
int main() {
	Party party;
	party.add_user("철수", 15);
	party.add_user("영수", 18);
	party.add_user("수빈", 13);
	party.add_user("민아", 19);

	cout << boolalpha;
	cout << "던전 입장 가능 ? " << party.can_join_dungeon() << endl;
	cout << "특별 아이템 사용 가능? " << party.can_use_special_item() << endl;
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

	//find 함수
	auto current = vec.begin();
	while (true) {
		current = find_if(current, vec.end(), [](int i) {return i % 3 == 2; }); // find_if 함수에 람다 함수 사용
		if (current == vec.end()) break;
		cout << "3 으로 나눈 나머지가 2인 원소는 : " << *current << " 이다 " << endl;
		current++;
	}
	//auto result = find(vec.begin(), vec.end(), 3); //하나의 3 만 찾고싶다면
	//cout << "3 은 " << distance(vec.begin(), result) + 1 << " 번째 원소" << endl;
}*/