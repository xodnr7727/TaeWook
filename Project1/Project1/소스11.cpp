#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <initializer_list>
#include <random>
#include <cstdlib>
#include <type_traits>
#include <ctime>
#include <regex>
#include <iomanip>
#include <type_traits>
using namespace std;

int main() {
	string html = R"(
        <div class="social-login">
          <div class="small-comment">�������� �α��� </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            �Ǵ� ���� �Է��ϼ��� (��� ������ ��й�ȣ�� �ʿ��մϴ�)
          </div>
          <input name="name" id="name" placeholder="�̸�">
          <input name="password" id="password" type="password" placeholder="��й�ȣ">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
  )";

	//regex re(R"r(sk-circle(\d))r");
	regex re(R"r((sk-circle(\d) sk-circle))r"); //��ø�� ĸ�� �׷�
	smatch match;

	regex_replace(ostreambuf_iterator<char>(cout), html.begin(), html.end(), re, "$2-sk-circle");
	//regex_replace(ostreambuf_iterator<char>(cout), html.begin(), html.end(), re, "$1-sk-circle"); //ġȯ�� ���ڿ��� �������� �ʰ� stdout�� ����ϴ� ���

	//string modified_html = regex_replace(html, re, "$1-sk-circle");
	//cout << modified_html;
}


/*
int main() {
	string html = R"(
        <div class="social-login">
          <div class="small-comment">�������� �α��� </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            �Ǵ� ���� �Է��ϼ��� (��� ������ ��й�ȣ�� �ʿ��մϴ�)
          </div>
          <input name="name" id="name" placeholder="�̸�">
          <input name="password" id="password" type="password" placeholder="��й�ȣ">
        </div>
        <div id="adding-comment" class="sk-fading-circle">
          <div class="sk-circle1 sk-circle">a</div>
          <div class="sk-circle2 sk-circle">b</div>
          <div class="sk-circle3 sk-circle">asd</div>
          <div class="sk-circle4 sk-circle">asdfasf</div>
          <div class="sk-circle5 sk-circle">123</div>
          <div class="sk-circle6 sk-circle">aax</div>
          <div class="sk-circle7 sk-circle">sxz</div>
        </div>
  )";

	regex re(R"(<div class="sk[\w -]*">\w*</div>)");
	smatch match;
	
	auto start = sregex_iterator(html.begin(), html.end(), re);
	auto end = sregex_iterator();

	while (start != end) {
		cout << start->str() << endl;
		++start;
	}
}*/

/*
int main() {
	vector <string> phone_numbers = {"010-1234-5678", "010-123-4567",
		                            "011-1234-5567", "010-12345-6789",
		                            "123-4567-8901", "010-1234-567" };
	regex re("[01]{3}-(\\d{3,4})-(\\d{4})");
	smatch match; //��Ī�� ����� string �� ����
		//std::boolalpha �� bool �� 0 �� 1 ��ſ� false, true �� ǥ���ϰ� ���ش�.
	for (const auto& number : phone_numbers) {
		if (regex_match(number, match, re)) {
			for(size_t i =0; i < match.size(); i++){
			cout << "Match : " << match[i].str() << endl;
		}
		cout << "-----------------------\n";
		//cout << number << ": " << boolalpha
		//<< regex_match(number, re) << '\n';
	   }
	}
}*/

/*
template <typename Cont>
	void_t<decltype(declval<Cont>().begin()),
	decltype(declval<Cont>().end())>
	print(const Cont& container) {
	cout << "[ ";
	for (auto if = container.begin(); it != container.end(); ++it) {
		cout << *it << " ";
	}
	cout << "]\n";
}
struct Bad {};
*/
/*
//T�� �ݵ�� ���� Ÿ���� �����ϴ� ��� �Լ� func �� ������ �־�� �Ѵ�.
template <typename T, typename = enable_if_t<
	                     is_integral_v<decltype(declval<T>().func())>>>
void test(const T& t) {
	cout << "t.func() : " << t.func() << endl;
}

struct A {
	int func() const { return 1; }
};

struct B {
	char func() const { return 'a'; }
};

int main() {
	test(A{}); 
	test(B{});
}*/
/*
template <typename T, enable_if_t<is_integral_v<T>,bool> =true>
	void test(const T& t) {
	cout << "t : " << t << endl;
}

int main() {
	test(1); //int
	test(false); //bool
	test('c'); //char

	//test(A{}); ���� Ÿ���� �ƴ� ��ü ���� �� ����
}*/

/*
template <typename T>
void test(typename T::x a) {
	cout << "T::x \n";
}

template <typename T>
void test(typename T::y b) {
	cout << "T::y \n";
}

struct A {
	using x = int;
};
struct B {
	using y = int;
};

int main() {
	test<A>(33);

	test<B>(22);
}*/

/*
class A {
public:
	int n;

	A(int n) : n(n) {}
};
int main() {
	int A::*p_n = &A::n;

	A a(3);
	cout << "a.n : " << a.n << endl;
	cout << "a.*p_n : " << a.*p_n << endl;
}*/

/*
class A{};

template <typename T>
void only_integer(const T& t) {
	static_assert(is_integral<T>::value);
	cout << "T is an integer \n";
}

int main() {
	int n = 3;
	only_integer(n);

	//static assertion failed ��� ������ ���� �߻�
	//A a;
	//only_integer(a);
}*/

/*
template <typename T>
struct is_void {
	static constexpr bool value = false;
};

//���ø� Ư��ȭ ���� ����
template <>
struct is_void<void> {
	static constexpr bool value = true;
};

template <typename T>
void tell_type() {
	if (is_void<T>::value) {
		cout << "T �� void ! \n";
	}else {
		cout << "T �� void �� �ƴϴ�. \n";
	}
}

int main() {
	tell_type<int>();

	tell_type<void>();
}*/

/*
int main() {
	//�õ尪�� ��� ���� random_device ����
	random_device rd;

	//random_device �� ���� ���� ���� ������ �ʱ�ȭ�Ѵ�
	mt19937 gen(rd());

	//1���� 45���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����
	uniform_int_distribution<int> dis(1, 45);

	for (int i = 0; i < 6; i++) {
		cout << "���� : " << dis(gen) << endl;
	}
}*/
/*
template <typename T>
decltype(declval<T>().f()) call_f_and_return(T& t) { 
	//std::declval�� Ÿ�� T �� �����ϸ� , T �� �����ڸ� ���� ȣ������ �ʴ��� T �� ������ ��ü�� ��Ÿ�����ִ�.
	return t.f();
}
struct A {
	int f() { return 0; }
};
struct B {
	B(int x){}
	int f() { return 0; }
};
int main() {
	A a;
	B b(1);

	call_f_and_return(a);
	call_f_and_return(b);
}*/

/*
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
	return t + u;
}*/
/*
struct A {
	double d;
};

int main() {
	int a = 3;
	decltype(a) b = 2; //int

	int& r_a = a;
	decltype(r_a) r_b = b;//int&

	int&& x = 3;
	decltype(x) y = 2; //int&&

	A* aa;
	decltype(aa->d) dd = 0.1; //double
}*/

/*
template <typename T>
void show_value(T t) {
	if constexpr(is_pointer_v<T>) {
		cout << "������ �̴� : " << *t << endl;
	}else {
		cout << "�����Ͱ� �ƴϴ� : " << t << endl;
	}
}

int main() {
	int x = 3;
	show_value(x);

	int* p = &x;
	show_value(p);
}*/

/*
class Vector {
public:
	constexpr Vector(int x, int y) : x_(x), y_(y) {}

	constexpr int x() const { return x_; }
	constexpr int y() const { return y_; }

private:
	int x_;
	int y_;
};
constexpr Vector AddVec(const Vector& v1, const Vector& v2) {
	return { v1.x() + v2.x(), v1.y() + v2.y() };
}
template <int N>
struct A {
	int operator()() { return N; }
};

int main() {
	constexpr Vector v1{ 1,2 };
	constexpr Vector v2{ 2,3 };

	//constexpr ��ü�� constexpr ����Լ��� ���� constexpr
	A<v1.x()> a;
	cout << a() << endl;

	//AddVec ���� constexpr �� �����Ѵ�
	A<AddVec(v1, v2).x()> b;
	cout << b() << endl;
}*/

/*
constexpr int factorial(int N) {
	int total = 1;
	for (int i = 1; i <= N; i++) {
		total *= i;
	}
	return total;
}

template <int N> 
struct A {
	int operator()() { return N; }
};

int main() {
	A<factorial(10)> a;

	cout << a() << endl;
}*/

/*
template <int N>
struct A {
	int operator()() { return N; }
};

int main() {
	constexpr int size = 3;
	int arr[size];

	constexpr int N = 10;
	A<N> a;
	cout << a() << endl;

	constexpr int number = 3;
	enum B {x = number , y ,z};
	cout << B::x << endl;
}*/

/*
class A {
public:
	A(int x, double y) { cout << "�Ϲ� ������" << endl; }

	A(initializer_list<string> lst) {
		cout << "�ʱ�ȭ�� ��� ������" << endl;
	}
};

int main() {
	A a(3, 1.5); //Good
	A B{ 3, 1.5 };
	A c{ "abc","def" };
	//A b{ 3, 1.5 }; // Bad
}*/

/*
template <typename T>
void print_vec(const vector<T>& vec) {
	cout << "[";
	for (const auto& e : vec) {
		cout << e << " ";
	}
	cout << "]" << endl;
}

template <typename K, typename V>
void print_map(const map<K, V>& m) {
	for (const auto& kv : m) {
		cout << kv.first << " : " << kv.second << endl;
	}
}

int main() {
	vector<int> v = { 1,2,3,4,5 };
	print_vec(v);

	cout << "--------------------" << endl;
	map<string, int> m = {
		{"abc",1},{"hi",3},{"hello",5},{"c++",2},{"java",6}};
	print_map(m);
}*/

/* 
class A {
public:
	A(initializer_list<int> l) {
		for (auto itr = l.begin(); itr != l.end(); ++itr) {
			cout << *itr << endl;
		}
	}
};

int main() { A a = { 1,2,3,4,5 }; }*/

/*
class A {
public:
	A(int x, double y) {cout << "A�� ������ ȣ��" << endl;}
};

A func() {
	return { 1, 2.3 };
}
int main() { func(); }
/
/*
class A {
public:
	A(int x) { cout << "A�� ������ ȣ��" << endl; }
};

int main() {
	//A a(); ��� �ȉ�
	A a(3.5); // Narrow-conversion ����
	//A b{3.5}; // Narrow-conversion �Ұ�
}*/
