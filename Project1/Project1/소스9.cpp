#include <functional>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory>
#include <thread>
#include <mutex>
using namespace std;
using std::thread;
using std::vector;


/*
void worker1(mutex& m1, mutex& m2) {
	for (int i = 0; i < 10; i++) {
		m1.lock();
		m2.lock();
		cout << "Worker1 Hi! " << i << endl;

		m2.unlock();
		m1.unlock();
	}
}

void worker2(mutex& m1, mutex& m2) noexcept {
	for (int i = 0; i < 10; i++) {
		while (true) {
			m2.lock();

			//m1�� �̹� lock �Ǿ��ִٸ� "�� �� ��" �� �����ϰ� �ȴ�.
			if (m1.try_lock()) {
				m2.unlock();
				continue;
			}
			cout << "Worker2 Hi! " << i << endl;
			m1.unlock();
			m2.unlock();
			break;
		}
	}
}
int main() {

	mutex m1, m2;

	thread t1(worker1, ref(m1), ref(m2));
	thread t2(worker2, ref(m1), ref(m2));

	t1.join();
	t2.join();

	cout << "��!" << endl;
}*/

/*
void worker(int& result, mutex& m) {
	for (int i = 0; i < 10000; i++) {
		lock_guard<mutex> lock(m);
		result += 1;
		
		//scope�� ���� ������ lock�� �Ҹ�Ǹ鼭
		//m�� �˾Ƽ� unlock �Ѵ�.
	}
}
int main() {
	int counter = 0;
	mutex m;

	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		//���۷����� �����Ϸ��� ref �Լ��� ���ξ��Ѵ�.
		workers.push_back(thread(worker, ref(counter), ref(m)));
	}
	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}
	cout << "Counter ���� �� : " << counter << endl;
}*/

/*
void worker(vector<int>::iterator start, vector<int>::iterator end,
	int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) {
		sum += *itr;
	}
	*result = sum;

	//�������� id�� ���Ѵ�.
	thread::id this_id = this_thread::get_id();
	printf("������ %x ���� %d ���� ����� ��� : %d \n", this_id, *start,
		*(end - 1), sum);
}
int main() {
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	//�� �����忡�� ���� �κ� �յ��� �����ϴ� ����
	vector<int> partial_sums(4);

	vector<thread> workers;
	for(int i =0; i < 4; i++){
		workers.push_back(thread(worker, data.begin() + i * 2500,
			data.begin() + (i + 1) * 2500, &partial_sums[i]));	
	}
	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}
	int total = 0;
	for (int i = 0; i < 4; i++) {
		total += partial_sums[i];
	}
	cout << "��ü �� : " << total << endl;
}*/
/*
void func1() {
	for (int i = 0; i < 10; i++) {
		cout << "������ 1 �۵���! \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		cout << "������ 2 �۵���! \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		cout << "������ 3 �۵���! \n";
	}
}
int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	//t1.join();
	//t2.join();
	//t3.join();

	t1.detach();
	t2.detach();
	t3.detach();

	cout << "���� �Լ� ���� \n";
}*/

/*
using std::vector;

struct S {
	int data;
	S(int data) : data(data) { cout << "�Ϲ� ������ ȣ��" << endl; }
	S(const S& s) {
		cout << "���� ������ ȣ��" << endl;
		data = s.data;
	}

	S(S&& s) noexcept {
		cout << "�̵� ������ ȣ��" << endl;
		data = s.data;
	} 
};

void do_something(S& s1, const S& s2) { s1.data = s2.data + 3; }

int main() {
	S s1(1), s2(2);

	cout << "Before : " << s1.data << endl;

	//s1�� �״�� ���޵� ���� �ƴ϶� s1�� ���纻�� ���޵�
	auto do_something_with_s1 = bind(do_something, ref(s1), placeholders::_1);
	do_something_with_s1(s2);

	cout << "After :: " << s1.data << endl;
}*/

/*
void add(int x, int y) {
	cout << x << " + " << y << " = " << x + y << endl;
}

void subtract(int x, int y) {
	cout << x << " - " << y << " = " << x - y << endl;
}
int main() {
	auto add_with_2 = bind(add, 2, placeholders::_1);
	add_with_2(3);

	//�� ��° ���ڴ� ���õȴ�.
	add_with_2(3, 4);

	auto subtract_from_2 = bind(subtract, placeholders::_1, 2);
	auto negate =
		bind(subtract, placeholders::_2, placeholders::_1);

	subtract_from_2(3); // 3 - 2 �� ����Ѵ�
	negate(4, 2); // 2 - 4 �� ����Ѵ�
}*/
/*
int main() {
	vector<int> a(1);
	vector<int> b(2);
	vector<int> c(3);
	vector<int> d(4);

	vector<vector<int>> container;
	container.push_back(a);
	container.push_back(b);
	container.push_back(c);
	container.push_back(d);

	//function<size_t(const vector<int>&)> sz_func = &vector<int>::size;

	vector<int> size_vec(4);
	transform(container.begin(), container.end(), size_vec.begin(), 
		[](const auto& v){ return v.size(); });
	for (auto itr = size_vec.begin(); itr != size_vec.end(); ++itr) {
		cout << "���� ũ�� :: " << *itr << endl;
	}
}*/

/*
class A {
	int c;

public:
	A(int c) : c(c) {}
	int some_func() { 
	cout << "���� �Լ� : "<< ++c << endl; 
	return c;
	}

	int some_const_function() const {
		cout << "��� �Լ� : " << c << endl;
		return c;
	}
	static void st(){}
};
int main() {
	A a(5);
	function<int(A&)> f1 = &A::some_func;
	function<int(const A&)> f2 = &A::some_const_function;

	f1(a);
	f2(a);
}*/
/*
int some_func1(const std::string& a) {
	cout << "Func1 ȣ�� " << a << endl;
	return 0;
}

struct S {
	void operator()(char c) { cout << "Func2 ȣ�� " << c << endl; }
};

int main() {
	std::function<int(const std::string&)> f1 = some_func1;
	std::function<void(char)> f2 = S();
	std::function<void()> f3 = []() {cout << "Func3 ȣ�� " << endl; };

	f1("hello");
	f2('c');
	f3();
}*/

/*
class A {
	string s;
	weak_ptr<A> other;

public:
	A(const string& s) : s(s) { cout << "�ڿ��� ȹ����!" << endl; }

	~A() { cout << "�Ҹ��� ȣ��!" << endl; }

	void set_other(weak_ptr<A> o) { other = o; }
	void accees_other() {
		shared_ptr<A> o = other.lock();
		if (o) {
			cout << "���� : " << o->name() << endl;
		}else {
			cout << "�̹� �Ҹ��" << endl;
		}
	}
	string name() { return s; }
};

int main() {
	vector<shared_ptr<A>> vec;
	vec.push_back(make_shared<A>("�ڿ� 1"));
	vec.push_back(make_shared<A>("�ڿ� 2"));
	
	vec[0]->set_other(vec[1]);
	vec[1]->set_other(vec[0]);

	//pa�� pb�� ref count �� �״�δ�
	cout << "vec[0] ref count : " << vec[0].use_count() << endl;
	cout << "vec[1] ref count : " << vec[1].use_count() << endl;

	//weak_ptr�� �ش� ��ü �����ϱ�
	vec[0]->accees_other();

	//���� ������ ���� ���� (vec[1] �Ҹ�)
	vec.pop_back();
	vec[0]->accees_other(); //���� ����
}*/
/*
class A {
	int* data;
	shared_ptr<A> other;

public:
	A() {
		data = new int[100];
		cout << "�ڿ��� ȹ����!" << endl;
	}
	~A() {
		cout << "�Ҹ��� ȣ��!" << endl;
		delete[] data;
	}

	void set_other(shared_ptr < A> o) { other = o; }
};
int main() {
	shared_ptr<A> pa = make_shared<A>();
	shared_ptr<A> pb = make_shared<A>();

	pa->set_other(pb);
	pa->set_other(pa);
}*/
/*
class A : public enable_shared_from_this<A> {
	int* data;

public: 
	A() {
		data = new int[100];
		cout << "�ڿ��� ȹ����!" << endl;
	}

	~A() {
		cout << "�Ҹ��� ȣ��!" << endl;
		delete[] data;
	}

	shared_ptr<A> get_shared_ptr() { return shared_from_this(); }
};

int main() {
	A* a = new A();

	shared_ptr<A> pa1 = make_shared<A>();
	shared_ptr<A> pa2 = pa1->get_shared_ptr();

	cout << pa1.use_count() << endl;
	cout << pa2.use_count() << endl;
}*/
/*
class A {
	int* data;

public:
	A() {
		data = new int[100];
		cout << "�ڿ��� ȹ����!" << endl;
	}
	~A() {
		cout << "�Ҹ��� ȣ��!" << endl;
		delete[] data;
	}
};

int main() {
	vector<shared_ptr<A>> vec;

	vec.push_back(shared_ptr<A>(new A()));
	vec.push_back(shared_ptr<A>(vec[0]));
	vec.push_back(shared_ptr<A>(vec[1]));

	//������ ù���� ���Ҹ� �Ҹ� ��Ų��.
	cout << "ù ��° �Ҹ�!" << endl;
	vec.erase(vec.begin());

	//�� ���� ���Ҹ� �Ҹ��Ų��.
	cout << "���� ���� �Ҹ�!" << endl;
	vec.erase(vec.begin());

	//������ ���Ҹ� �Ҹ��Ų��.
	cout << "������ ���� �Ҹ�!" << endl;
	vec.erase(vec.begin());

	cout << "���α׷� ����!" << endl;
}*/

/*
class A {
	int* data;

public:
	A(int i) {
		cout << "�ڿ��� ȹ����!" << endl;
		data = new int[100];
		data[0] = i;
	}

	void some() { cout << "�Ϲ� �����Ϳ� �����ϰ� ��� ����!" << endl; }

	~A() {
		cout << "�ڿ��� ������!" << endl;
		delete[] data;
	}
};

int main() {
	vector<unique_ptr<A>> vec;

	//vec.push_back(std::unique_back<A>(new A(1))); �� ����
	vec.emplace_back(new A(1));

	vec.back()->some();
	
}
*/
/*
class Foo {
	int a, b;

public:
	Foo(int a, int b) : a(a), b(b) { cout << "������ ȣ��!" << endl; }
	void print() { cout << "a : " << a << ", b :" << b << endl; }
	~Foo() { cout << "�Ҹ��� ȣ��!" << endl; }
};

int main() {
	auto ptr = make_unique<Foo>(3, 5); //unique_ptr�� ������ ���� �� �ִ� make_unique
	ptr->print();
}*/

/*
class A {
	int* data;

public:
	A() {
		data = new int[100];
		cout << "�ڿ��� ȹ����!" << endl;
	}
	
	void some() { cout << "�Ϲ� �����Ϳ� �����ϰ� ��밡��!" << endl; }

	void do_sth(int a) {
		cout << "���𰡸� �Ѵ�!" << endl;
		data[0] = a;
	}

	~A() {
		cout << "�ڿ��� ������!" << endl;
		delete[] data;
	}
};

//�ùٸ��� �ʴ� ���� ��� void do_something(unique_ptr<A>& ptr) { ptr->do_sth(3); }

void do_something(A* ptr) { ptr->do_sth(3); }

int main() {
	unique_ptr<A> pa(new A());
	do_something(pa.get());
}*/

/*void do_something() {
	unique_ptr<A> pa(new A()); //Ư�� ��ü�� ������ �������� �ο��ϴ� ������ ��ü unique_ptr
	cout << "pa : ";
	pa->some();

	//pb�� �������� ����.
	unique_ptr<A> pb = move(pa);
	cout << "pb : ";
	pb->some();
}
int main() {
	do_something();
}*/
/*
class A {
public:
	A(int a) {};
	A(const A& a) = delete; //C++11�� �߰��� ����� ��ġ �ʴ� �Լ��� ���� ��Ű�� ��� (���α׷��Ӱ� ��������� �� �Լ��� ��������� ǥ���ϴ� ����̴�.)
};
int main() {
	A a(3); //����
	A b(a); //�Ұ���(���� �����ڴ� ������)
}*/
/*
void show_value(int&& t) { std::cout << "������ : " << t << std::endl; }

int main() {
	show_value(5);  // ������ ok!

	int x = 3;
	show_value(x);  // ����
}*/
/*
template <typename T>
void wrapper(T&& u) {
	g(forward<T>(u));
}


class A {};

void g(A& a) { cout << "������ ���۷��� ȣ��" << endl; }
void g(const A& a) { cout << "������ ��� ���۷��� ȣ��" << endl; }
void g(A&& a) { cout << "������ ���۷��� ȣ��" << endl; }

int main() {
	A a;
	const A ca;

	cout << "���� --------" << endl;
	g(a);
	g(ca);
	g(A());

	cout << "Wrapper ------" << endl;
	wrapper(a);
	wrapper(ca);
	wrapper(A());
}*/
/*
class A {
public:
	A() { cout << "ctor\n"; }
	A(const A& a) { cout << "copy ctor\n"; }
	A(A&& a) { cout << "move ctor\n"; }
};

class B {
public:
	B(A&& a) : a_(move(a)) {}

	A a_;
};

int main() {
	A a;

	cout << "create B-- \n";
	B b(move(a));
}*/