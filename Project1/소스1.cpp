/*
#include <cstdio>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")
#include <string.h>
#include <iostream>
#include <vector>
#include <cstring>
/*
using namespace std;
class Test {
	int x;

public:
	Test(int x) : x(x){}
	Test(const Test& t) : x(t.x) {}

	Test& operator++() {
		x++;
		cout << "���� ���� ������" << endl;
		return *this;
	}

	//���� ������ ���� ������ ���̸� �α� ���� ���� ������ ��� ���ڷ� int�� ������ �����δ� �ƹ��͵� ���޵��� �ʴ´�.

	Test operator++(int) {
		Test temp(*this);
		x++;
		cout << "���� ���� ������" << endl;
		return temp;
	}

	int get_x() const {
		return x;
	}
};
void func(const Test& t) {
	cout << "x : " << t.get_x() << endl;
}
int main() {
	Test t(3);

	func(++t); //4
	func(t++); //4�� ��µ�
	cout << "x : " << t.get_x() << endl;
}*/
/*
class Int //�ڷ����� ��ü�ν� �ٷ���Ҷ� Wrapper Ŭ������ �̿�
{
	int data;
	//some other data

public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}

	operator int() { return data; } // Ÿ�� ��ȯ ������ 
};
int main() {
	Int x = 3;
	int a = x + 4;

	x = a * 2 + x + 4;
	cout << x << endl;
}*/


/*class Complex {
private:
	double real, img;

	double get_number(const char* str, int from, int to) const;

public:

	Complex(double real, double img) : real(real), img(img) {}
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex(const char* str);

	



	Complex& operator=(const Complex& c);

	void println() {
		cout << "( " << real << " , " << img << " ) " << endl; }

	friend Complex operator+(const Complex& a, const Complex& b);
};

Complex operator+(const Complex& a, const Complex& b) {
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

Complex::Complex(const char* str) {
	int begin = 0, end = strlen(str);
	img = 0.0;
	real = 0.0;

	int pos_i = -1;
	for (int i = 0; i != end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}
	if (pos_i == -1) {
		real = get_number(str, begin, end - 1);
		return;
	}

	real = get_number(str, begin, pos_i);
	img = get_number(str, pos_i + 1, end - 1);

	if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

double Complex::get_number(const char* str, int from, int to) const {
	bool minus = false;
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.')
			integer_part =false;
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);	
		}
		else
			break;
	}
	if (minus) num *= -1.0;

	return num;
}

// �ڱ� �ڽ��� �����ϴ� ���� �����ڴ� ��� �Լ���, �ƴ� �ֵ��� �ܺ� �Լ��� ��������! return temp; < ��� return this; < �ܺ�

Complex& Complex::operator=(const Complex& c) {
	real = c.real;
	img = c.img;
	return *this;
}


int main() {
	Complex a(0, 0);

	a = "-1.1 + i3.923" + a;
	a = a + a;

	Complex b(1, 2);
	b = a + b;
	 
	b.println();
}*/


/*class string {
	char* str;
	int len;

public:
	string(char c, int n);
	string(const char* s);
	string(const string& s);
	~string();

	void add_string(const string& s);
	void copy_string(const string& s);
	int strlen();
};
string::string(char c, int n) {
	 
}*/

/*class Photon_Cannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	Photon_Cannon(int x, int y);
	Photon_Cannon(const Photon_Cannon& pc);
	Photon_Cannon(int x, int y, const char* cannon_name);
	~Photon_Cannon();

	void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
	cout << "������ ȣ�� !" << endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
	cout << "���� ������ ȣ��" << endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;
	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = new char[strlen(cannon_name + 1)];
	strcpy(name, cannon_name);
}
	Photon_Cannon::~Photon_Cannon() {
		if (name) delete[] name;
	
}

void Photon_Cannon::show_status() {
	cout << "Photon Cannon : " << name << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " Hp : " << hp << endl;
}
int main() {
	Photon_Cannon pc1(3,3,"Cannon");
	Photon_Cannon pc2(pc1);

	pc1.show_status();
	pc2.show_status();
}
*/

/*class Test {
	char c;

public:
	Test(char _c) {
		c = _c;
		cout << "������ ȣ��" << c << endl;
	}
	~Test() { cout << "�Ҹ��� ȣ��" << c << endl; }
};
void simple_function() { Test b('b'); }
int main() {
	Test a('a');
	simple_function();
}*/
/*
//�ڱ� �ڽ��� ����Ű�� ������ this
class A {
	int x;
public:
	A(int c) : x(c) {}
	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { cout << x << endl; }

};
int main() {
	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();

	//�Ʒ��� ����
	//int &e = a.get();
	//e = 2;
	//a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();
}
*/
/*
class A {
	int x;

public:
	A(int c) : x(c) {}
	A(const A& a) {
		x = a.x;
		cout << "���� ����" << endl;
	}
};
class B {
	A a;

public:
	B(int c) : a(c) {}
	B(const B& b) : a(b.a) {}
	A get_A() {
		A temp(a);
		return temp;
	}
};
int main() {
	B b(10);

	cout << "------------" << endl;
	A a1 = b.get_A();
}
*/


/*
class Marine {
	static int total_marine_num;
	const static int i = 0;

	int hp;
	int coord_x, coord_y; //���� ��ġ
	bool is_dead;

	const int default_damage;

public :
	Marine(); //�⺻ ������
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack() const; //�������� �����Ѵ�
	Marine& be_attacked(int damage_earn); //�Դ� ������
	void move(int x, int y); //���ο� ��ġ

	void show_status();
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
	cout << "��ü ���� �� : " << total_marine_num << endl;
}
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y) 
	: coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int dafault_damage) 
	: coord_x(x),
	coord_y(y),
	hp(50),
	default_damage(5),
	is_dead(false) {
	total_marine_num++;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() const { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;
}
void Marine::show_status() {
	cout << " *** Marine ***" << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
	cout << "���� �� ������ �� : " << total_marine_num << endl;
}
void create_marine() {
	Marine marine3(10, 10, 4);
	marine3.show_status();
}

int main() {

	Marine marine1(2, 3, 10);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	create_marine();

	cout << endl << "���� 1�� ���� 2�� �� �� ����" << endl;
	marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();

}*/