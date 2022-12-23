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
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
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
	regex re(R"r((sk-circle(\d) sk-circle))r"); //중첩된 캡쳐 그룹
	smatch match;

	regex_replace(ostreambuf_iterator<char>(cout), html.begin(), html.end(), re, "$2-sk-circle");
	//regex_replace(ostreambuf_iterator<char>(cout), html.begin(), html.end(), re, "$1-sk-circle"); //치환된 문자열을 생성하지 않고 stdout에 출력하는 방법

	//string modified_html = regex_replace(html, re, "$1-sk-circle");
	//cout << modified_html;
}


/*
int main() {
	string html = R"(
        <div class="social-login">
          <div class="small-comment">다음으로 로그인 </div>
          <div>
            <i class="xi-facebook-official fb-login"></i>
            <i class="xi-google-plus goog-login"></i>
          </div>
        </div>
        <div class="manual">
          <div class="small-comment">
            또는 직접 입력하세요 (댓글 수정시 비밀번호가 필요합니다)
          </div>
          <input name="name" id="name" placeholder="이름">
          <input name="password" id="password" type="password" placeholder="비밀번호">
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
	smatch match; //매칭된 결과를 string 에 보관
		//std::boolalpha 는 bool 을 0 과 1 대신에 false, true 로 표현하게 해준다.
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
//T는 반드시 정수 타입을 리턴하는 멤버 함수 func 을 가지고 있어야 한다.
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

	//test(A{}); 정수 타입이 아닌 객체 전달 시 오류
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

	//static assertion failed 라는 컴파일 오류 발생
	//A a;
	//only_integer(a);
}*/

/*
template <typename T>
struct is_void {
	static constexpr bool value = false;
};

//템플릿 특수화 적용 가능
template <>
struct is_void<void> {
	static constexpr bool value = true;
};

template <typename T>
void tell_type() {
	if (is_void<T>::value) {
		cout << "T 는 void ! \n";
	}else {
		cout << "T 는 void 가 아니다. \n";
	}
}

int main() {
	tell_type<int>();

	tell_type<void>();
}*/

/*
int main() {
	//시드값을 얻기 위한 random_device 생성
	random_device rd;

	//random_device 를 통해 난수 생성 엔진을 초기화한다
	mt19937 gen(rd());

	//1부터 45까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의
	uniform_int_distribution<int> dis(1, 45);

	for (int i = 0; i < 6; i++) {
		cout << "난수 : " << dis(gen) << endl;
	}
}*/
/*
template <typename T>
decltype(declval<T>().f()) call_f_and_return(T& t) { 
	//std::declval에 타입 T 를 전달하면 , T 의 생성자를 직접 호출하지 않더라도 T 가 생성된 객체를 나타낼수있다.
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
		cout << "포인터 이다 : " << *t << endl;
	}else {
		cout << "포인터가 아니다 : " << t << endl;
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

	//constexpr 객체의 constexpr 멤버함수는 역시 constexpr
	A<v1.x()> a;
	cout << a() << endl;

	//AddVec 역시 constexpr 를 리턴한다
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
	A(int x, double y) { cout << "일반 생성자" << endl; }

	A(initializer_list<string> lst) {
		cout << "초기화자 사용 생성자" << endl;
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
	A(int x, double y) {cout << "A의 생성자 호출" << endl;}
};

A func() {
	return { 1, 2.3 };
}
int main() { func(); }
/
/*
class A {
public:
	A(int x) { cout << "A의 생성자 호출" << endl; }
};

int main() {
	//A a(); 출력 안됌
	A a(3.5); // Narrow-conversion 가능
	//A b{3.5}; // Narrow-conversion 불가
}*/
