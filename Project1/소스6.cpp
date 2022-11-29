#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <typeinfo>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;
/*
template <typename T>
void print_set(set<T>& s) {
	//셋의 모든 원소를 출력하기
	cout << "[ ";
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << " ] " << endl;
}
int main() {
	set<int> s;
	s.insert(10); //시퀀스 컨테이너 처럼 '어디에' 추가할지에 대한 정보가 없다는점.
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);

	cout << "순서대로 정렬되서 나온다" << endl;
	print_set(s);

	cout << "20이 s의 원소인가요? :: ";
	auto itr = s.find(20);
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}

	cout << "25 가 s의 원소인가요? :: ";
	itr = s.find(25);
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}
}*/

/*
template <typename T>
void print_deque(deque<T>& iu) {
	//전체 덱을 출력하기
	cout << "[ ";
	for (const auto& elem : iu) {
		cout << elem << " ";
	}
	cout << " ] " << endl;
}

int main() {
	deque<string> iu;
	iu.push_back("이지은");
	iu.push_back("이지금");
	iu.push_back("아이유");
	iu.push_back("장만월");

	cout << "초기 iu 상태" << endl;
	print_deque(iu);

	cout << "맨 앞의 원소 제거" << endl;
	iu.pop_front();
	print_deque(iu);
}*/

/*
template <typename T>
void print_list(list<T>& iu) {
	cout << "[ ";
	//전체 리스트를 출력하기( 이 역시 범위 기반 for 문을 쓸 수 있다.
	for (const auto& elem : iu) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

int main() {
	list<string> iu;

	iu.push_back("아이유");
	iu.push_back("이지은");
	iu.push_back("이지금");
	iu.push_back("장만월");

	cout << "처음 리스트의 상태" << endl;
	print_list(iu);

	for (list<string>::iterator itr = iu.begin(); itr != iu.end(); ++itr) { // ++과 --연산만 가능하기때문에 for문으로 하나하나 원소를 확인하는것은 가능하다.
		//만일 현재 원소가 이지은 이라면
		//그 앞에 해수를 집어 넣는다.
		if (*itr == "이지은") {
			iu.insert(itr, "해수"); //vector와 다르게 insert 작업은 O(1)으로 매우 빠르게 실행된다.
		}
	}
	cout << "값이 이지은인 원소 앞에 50을 추가 " << endl;
	print_list(iu);

	for (list<string>::iterator itr = iu.begin(); itr != iu.end(); ++itr) {
		//값이 이지금인 원소를 삭제한다.
		if (*itr == "이지금") {
			iu.erase(itr); //리스트의 경우 벡터와는 다르게, 원소를 지워도 반복자가 무효화되지 않는다. 각 원소들의 주소값들은 바뀌지 않기 때문에.
			break;
		}
	}
	cout << "값이 이지금인 원소를 제거한다" << endl;
	print_list(iu);
}*/

/*
template <typename T>
void print_vector(vector<T>& iu) {
	//전체 벡터 출력하기
	for (typename vector<T>::iterator itr = iu.begin(); itr != iu.end(); ++itr) {
		cout << *itr << endl;
	}
}
template <typename T>
void print_vector_range_based(vector<T>& iu) {
	//전체 벡터 출력하기
	for (const auto& elem : iu) { //elem은 iu의 원소들을 상수 레퍼런스로 접근하게 됌
		cout << elem << endl;
	}
}
int main() {
	vector<string> iu;
	iu.push_back("이지금");
	iu.push_back("이지은");
	iu.push_back("아이유");
	iu.push_back("장만월");

	cout << "print_vector" << endl;
	print_vector(iu);
	cout << "print_vector_range_based" << endl;
	print_vector_range_based(iu);

	return 0;
}*/
/*
int main() {
	vector<string> IU;
	IU.push_back("아이유");
	IU.push_back("이지금");
	IU.push_back("장만월");

	//range_based for 문
	for (string elem : IU) {
		cout << "원소 : " << elem << endl;
	}

	return 0;
}*/

/*
template <typename T>
void print_vector(vector<T>& IU) {
	//전체 벡터 출력하기
	for (typename vector<T>::iterator itr = IU.begin(); itr != IU.end(); ++itr) { //앞에 typename을 추가해줘야한다. iterator은 vector<T>의 의존 타입이기 때문에.
	cout << *itr << endl; 
    }
}
int main() {
	vector<string> IU;
	IU.push_back("좋은 날");
	IU.push_back("너랑 나");
	IU.push_back("금요일에 만나요");
	IU.push_back("봄 사랑 벚꽃 말고");

	cout << "처음 벡터 상태" << endl;
	print_vector(IU);
	cout << "-----------------------------" << endl;

	//IU[2] 앞에 라일락 추가
	IU.insert(IU.begin() + 2, "라일락");
	print_vector(IU);
    cout << "-----------------------------" << endl;

	cout << "역으로 vec 출력하기" << endl;
	vector<string>::reverse_iterator r_iter = IU.rbegin();
	for (; r_iter != IU.rend(); r_iter++) {
		cout << *r_iter << endl;
	}
}*/
/*
int main() {
	vector<string> vec;
	vec.push_back("아이유");
	vec.push_back("이지금");
	vec.push_back("장만월");
	vec.push_back("해수");

	//전체 벡터를 출력하기
	for (vector<string>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << endl; //* 연산자를 오버로딩해서 마치 포인터처럼 동작하게 만든 것이다. * 연산자는 itr이 가리키는 원소의 레퍼런스를 리턴
	}

	//int arr[4] = {10, 20, 30, 40}
	// *(arr + 2) == arr[2] == 30;
	// *(itr + 2) == vec[2] == 30;

	vector<string>::iterator itr = vec.begin() + 2;
	cout << "3번째 원소 :: " << *itr << endl;
}*/
/*
int main() {
	vector <int> vec;
	vec.push_back(10); //맨뒤에 10 추가
	vec.push_back(20); //맨뒤에 20 추가
	vec.push_back(30); //맨뒤에 30 추가
	vec.push_back(40); //맨뒤에 40 추가

	for (vector <int>::size_type i = 0; i < vec.size(); i++) {
		cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << endl;
	}
}*/
 
/* // 타입을 알아서 추측해주는 auto 키워드 사용
int sum(int a, int b) { return a + b; }

class SomeClass {
	int data;

public:
	SomeClass(int d) : data(d) {}
	SomeClass(const SomeClass& s) : data(s.data) {}
};

int main() {
	auto c = sum(1, 2); //함수 리턴 타입으로부터 int 라고 추측 가능
	auto num = 1.0 + 2.0; //double로 추측 가능

	SomeClass some(10);
	auto some2 = some;

	auto some3(10); //SomeClass 객체를 만들까요?

	cout << "c의 타입은? :: " << typeid(c).name() << endl;
	cout << "num의 타입은? :: " << typeid(num).name() << endl;
	cout << "some2의 타입은? :: " << typeid(some2).name() << endl;
	cout << "some3의 타입은? :: " << typeid(some3).name() << endl;
}*/
/*
template<int X, int Y>
struct GCD{
	static const int value = GCD<Y, X% Y>::value;
};

template<int X>
struct GCD<X, 0>{
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
private:
	const static int _gcd = GCD<N, D> ::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type;
	static const int num = N / _gcd;
	static const int den = D / _gcd;
};

template <class R1, class R2>
struct _Ratio_add{
	using type = Ratio<R1::num* R2::den + R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
	using type = Ratio<R1::num* R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
	using type = Ratio<R1::num * R2::num, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
	using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V,typename W>
struct Dim {
	using M = U; //kg
	using L = V; //m
	using T = W; //s

	using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
	typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
		typename Ratio_add<typename U::L, typename V::L>::type,
		typename Ratio_add<typename U::T, typename V::T>::type>
		type;
};

template <typename U, typename V>
struct subtract_dim_ {
	typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
		typename Ratio_subtract<typename U::L, typename V::L>::type,
		typename Ratio_subtract<typename U::T, typename V::T>::type>
		type;
};

template <typename T,typename D>
struct quantity {
	T q;
	using dim_type = D;

	quantity operator+(quantity<T, D> quant) {
		return quantity<T, D>(q + quant.q);
	}
	//인자로 받는 quantity의 데이터 타입과 Dim의 데이터 타입이 일치해야지만 인스턴스화된다.(일치하지않다면 오류 발생시킴)
	quantity operator-(quantity<T, D> quant) {
		return quantity<T, D>(q - quant.q);
	}

	template <typename D2>
	quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
		return quantity < T, typename add_dim_<D, D2>::type>(q * quant.q);
	}

	template <typename D2>
	quantity<T, typename subtract_dim_<D, D2>::type> operator/
		(quantity<T, D2> quant) {
		return quantity< T, typename subtract_dim_<D, D2>::type>(q / quant.q);
	}

	quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }

	quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }

quantity(T q) : q(q) {}
};

template <typename T,typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q) {
	out << q.q << "kg^" << D::M::num << D::M::den << "m^" << D::L::num / D::L::den
		<< "s^" << D::T::num / D::T::den;

	return out;
}
int main() {
	using one = Ratio<1, 1>;
	using zero = Ratio<0, 1>;

	quantity<double, Dim<one, zero, zero>> kg(2);
	quantity<double, Dim<zero, one, zero>> meter(3);
	quantity<double, Dim<zero, zero, one>> second(1);

	auto F = kg * meter / (second * second);
	cout << "2kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는? " << F
		<< endl;

	//Good //잘 컴파일 됨
	//kg + kg;

	//Bad //단위가 다르기 떄문에 오류 발생
	//kg + meter;
}*/

/*
template <int N>
struct INT{
	static const int num = N;
};

template <typename a, typename b>
struct add
{
	typedef INT<a::num + b::num> result;
};

template  <typename a, typename b>
struct divide {
	typedef INT<a::num + b::num>result;
};
using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div {
	static const bool result = (N::num % d::num == 0) ||
		                       check_div<N, typename add<d, one>::result>::result;
};

template<typename N>
struct _is_prime
{
	static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> {
	static const bool result = true;
};

template <>
struct _is_prime<three> {
	static const bool result = true;
};

template <typename N>
struct check_div<N,typename divide<N, two>::result>
{
	static const bool result =(N::num % (N::num /2) == 0);
};
template<int N>
struct is_prime
{
	static const bool result = _is_prime<INT<N>>::result;
};
int main() {
	cout << boolalpha;
	cout << "Is 2 prime ? :: " << is_prime<2>::result << endl;
	cout << "Is 10 prime ? :: " << is_prime<10>::result << endl;
	cout << "Is 11 prime ? :: " << is_prime<11>::result << endl;
	cout << "Is 61 prime ? :: " << is_prime<61>::result << endl;
}*/

/*
// 두 수의 최대 공약수를 구하기
template<int X, int Y>
struct GCD
{
	static const int value = GCD<Y, X % Y>::value;
};

template<int X>
struct GCD<X,0>
{
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio //유리수를 오차없이 표현해주는 클래스 
			 // 마치 Ratio 클래스의 객체를 생성한 것 같지만, 실제로 생성된 객체는 한 개도 없고, 단순히 타입들만 만들어낸 것 뿐입니다.
{
	typedef Ratio<N, D> type;
	static const int num = N;
	static const int den = D;
};

template <class R1, class R2>
struct _Ratio_add
{
	typedef Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

int main() {
	using R1 = Ratio<2, 3>;  //C+11부터 새롭게 나온 using 키워드를 사용하면 typedef보다 더 직관적으로 나타낼수 있다.
	using R2 = Ratio<3, 2>;

	using R3 = Ratio_add<R1, R2>;
	
	//typedef Ratio<2, 3> R1;
	//typedef Ratio<3, 2> R2;
	//typedef Ratio_add<R1, R2> R3;

	cout << R3::num << " / " << R3::den << endl;

	return 0;
}*/
/*
//템플릿 메타 프로그래밍(TMP) 사용으로 팩토리얼 값 구하기 
template <int N> 
struct Factorial
{
	static const int result = N * Factorial<N - 1>::result;
};

template<> //템플릿 특수화 사용
struct Factorial<1> 
{
	static const int result = 1; //재귀적 구조가 끝날 수 있게 해준다.
};

int main() {
	cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << endl;
}*/