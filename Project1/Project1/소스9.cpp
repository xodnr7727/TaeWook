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

			//m1이 이미 lock 되어있다면 "야 차 뺴" 를 수행하게 된다.
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

	cout << "끝!" << endl;
}*/

/*
void worker(int& result, mutex& m) {
	for (int i = 0; i < 10000; i++) {
		lock_guard<mutex> lock(m);
		result += 1;
		
		//scope를 빠져 나가면 lock이 소멸되면서
		//m을 알아서 unlock 한다.
	}
}
int main() {
	int counter = 0;
	mutex m;

	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		//레퍼런스로 전달하려면 ref 함수로 감싸야한다.
		workers.push_back(thread(worker, ref(counter), ref(m)));
	}
	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}
	cout << "Counter 최종 값 : " << counter << endl;
}*/

/*
void worker(vector<int>::iterator start, vector<int>::iterator end,
	int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; ++itr) {
		sum += *itr;
	}
	*result = sum;

	//쓰레드의 id를 구한다.
	thread::id this_id = this_thread::get_id();
	printf("쓰레드 %x 에서 %d 까지 계산한 결과 : %d \n", this_id, *start,
		*(end - 1), sum);
}
int main() {
	vector<int> data(10000);
	for (int i = 0; i < 10000; i++) {
		data[i] = i;
	}

	//각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
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
	cout << "전체 합 : " << total << endl;
}*/
/*
void func1() {
	for (int i = 0; i < 10; i++) {
		cout << "쓰레드 1 작동중! \n";
	}
}

void func2() {
	for (int i = 0; i < 10; i++) {
		cout << "쓰레드 2 작동중! \n";
	}
}

void func3() {
	for (int i = 0; i < 10; i++) {
		cout << "쓰레드 3 작동중! \n";
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

	cout << "메인 함수 종료 \n";
}*/

/*
using std::vector;

struct S {
	int data;
	S(int data) : data(data) { cout << "일반 생성자 호출" << endl; }
	S(const S& s) {
		cout << "복사 생성자 호출" << endl;
		data = s.data;
	}

	S(S&& s) noexcept {
		cout << "이동 생성자 호출" << endl;
		data = s.data;
	} 
};

void do_something(S& s1, const S& s2) { s1.data = s2.data + 3; }

int main() {
	S s1(1), s2(2);

	cout << "Before : " << s1.data << endl;

	//s1이 그대로 전달된 것이 아니라 s1의 복사본이 전달됨
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

	//두 번째 인자는 무시된다.
	add_with_2(3, 4);

	auto subtract_from_2 = bind(subtract, placeholders::_1, 2);
	auto negate =
		bind(subtract, placeholders::_2, placeholders::_1);

	subtract_from_2(3); // 3 - 2 를 계산한다
	negate(4, 2); // 2 - 4 를 계산한다
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
		cout << "벡터 크기 :: " << *itr << endl;
	}
}*/

/*
class A {
	int c;

public:
	A(int c) : c(c) {}
	int some_func() { 
	cout << "비상수 함수 : "<< ++c << endl; 
	return c;
	}

	int some_const_function() const {
		cout << "상수 함수 : " << c << endl;
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
	cout << "Func1 호출 " << a << endl;
	return 0;
}

struct S {
	void operator()(char c) { cout << "Func2 호출 " << c << endl; }
};

int main() {
	std::function<int(const std::string&)> f1 = some_func1;
	std::function<void(char)> f2 = S();
	std::function<void()> f3 = []() {cout << "Func3 호출 " << endl; };

	f1("hello");
	f2('c');
	f3();
}*/

/*
class A {
	string s;
	weak_ptr<A> other;

public:
	A(const string& s) : s(s) { cout << "자원을 획득함!" << endl; }

	~A() { cout << "소멸자 호출!" << endl; }

	void set_other(weak_ptr<A> o) { other = o; }
	void accees_other() {
		shared_ptr<A> o = other.lock();
		if (o) {
			cout << "접근 : " << o->name() << endl;
		}else {
			cout << "이미 소멸됨" << endl;
		}
	}
	string name() { return s; }
};

int main() {
	vector<shared_ptr<A>> vec;
	vec.push_back(make_shared<A>("자원 1"));
	vec.push_back(make_shared<A>("자원 2"));
	
	vec[0]->set_other(vec[1]);
	vec[1]->set_other(vec[0]);

	//pa와 pb의 ref count 는 그대로다
	cout << "vec[0] ref count : " << vec[0].use_count() << endl;
	cout << "vec[1] ref count : " << vec[1].use_count() << endl;

	//weak_ptr로 해당 객체 접근하기
	vec[0]->accees_other();

	//벡터 마지막 원소 제거 (vec[1] 소멸)
	vec.pop_back();
	vec[0]->accees_other(); //접근 실패
}*/
/*
class A {
	int* data;
	shared_ptr<A> other;

public:
	A() {
		data = new int[100];
		cout << "자원을 획득함!" << endl;
	}
	~A() {
		cout << "소멸자 호출!" << endl;
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
		cout << "자원을 획득함!" << endl;
	}

	~A() {
		cout << "소멸자 호출!" << endl;
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
		cout << "자원을 획득함!" << endl;
	}
	~A() {
		cout << "소멸자 호출!" << endl;
		delete[] data;
	}
};

int main() {
	vector<shared_ptr<A>> vec;

	vec.push_back(shared_ptr<A>(new A()));
	vec.push_back(shared_ptr<A>(vec[0]));
	vec.push_back(shared_ptr<A>(vec[1]));

	//벡터의 첫번쨰 원소를 소멸 시킨다.
	cout << "첫 번째 소멸!" << endl;
	vec.erase(vec.begin());

	//그 다음 원소를 소멸시킨다.
	cout << "다음 원소 소멸!" << endl;
	vec.erase(vec.begin());

	//마지막 원소를 소멸시킨다.
	cout << "마지막 원소 소멸!" << endl;
	vec.erase(vec.begin());

	cout << "프로그램 종료!" << endl;
}*/

/*
class A {
	int* data;

public:
	A(int i) {
		cout << "자원을 획득함!" << endl;
		data = new int[100];
		data[0] = i;
	}

	void some() { cout << "일반 포인터와 동일하게 사용 가능!" << endl; }

	~A() {
		cout << "자원을 해제함!" << endl;
		delete[] data;
	}
};

int main() {
	vector<unique_ptr<A>> vec;

	//vec.push_back(std::unique_back<A>(new A(1))); 과 동일
	vec.emplace_back(new A(1));

	vec.back()->some();
	
}
*/
/*
class Foo {
	int a, b;

public:
	Foo(int a, int b) : a(a), b(b) { cout << "생성자 호출!" << endl; }
	void print() { cout << "a : " << a << ", b :" << b << endl; }
	~Foo() { cout << "소멸자 호출!" << endl; }
};

int main() {
	auto ptr = make_unique<Foo>(3, 5); //unique_ptr을 간단히 만들 수 있는 make_unique
	ptr->print();
}*/

/*
class A {
	int* data;

public:
	A() {
		data = new int[100];
		cout << "자원을 획득함!" << endl;
	}
	
	void some() { cout << "일반 포인터와 동일하게 사용가능!" << endl; }

	void do_sth(int a) {
		cout << "무언가를 한다!" << endl;
		data[0] = a;
	}

	~A() {
		cout << "자원을 해제함!" << endl;
		delete[] data;
	}
};

//올바르지 않는 전달 방식 void do_something(unique_ptr<A>& ptr) { ptr->do_sth(3); }

void do_something(A* ptr) { ptr->do_sth(3); }

int main() {
	unique_ptr<A> pa(new A());
	do_something(pa.get());
}*/

/*void do_something() {
	unique_ptr<A> pa(new A()); //특정 객체에 유일한 소유권을 부여하는 포인터 객체 unique_ptr
	cout << "pa : ";
	pa->some();

	//pb에 소유권을 이전.
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
	A(const A& a) = delete; //C++11에 추가된 사용을 원치 않는 함수를 삭제 시키는 방법 (프로그래머가 명시적으로 이 함수를 쓰지말라고 표현하는 방법이다.)
};
int main() {
	A a(3); //가능
	A b(a); //불가능(복사 생성자는 삭제됨)
}*/
/*
void show_value(int&& t) { std::cout << "우측값 : " << t << std::endl; }

int main() {
	show_value(5);  // 우측값 ok!

	int x = 3;
	show_value(x);  // 에러
}*/
/*
template <typename T>
void wrapper(T&& u) {
	g(forward<T>(u));
}


class A {};

void g(A& a) { cout << "좌측값 레퍼런스 호출" << endl; }
void g(const A& a) { cout << "좌측값 상수 레퍼런스 호출" << endl; }
void g(A&& a) { cout << "우측값 레퍼런스 호출" << endl; }

int main() {
	A a;
	const A ca;

	cout << "원본 --------" << endl;
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