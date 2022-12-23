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
	//���� ��� ���Ҹ� ����ϱ�
	cout << "[ ";
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << " ] " << endl;
}
int main() {
	set<int> s;
	s.insert(10); //������ �����̳� ó�� '���' �߰������� ���� ������ ���ٴ���.
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);

	cout << "������� ���ĵǼ� ���´�" << endl;
	print_set(s);

	cout << "20�� s�� �����ΰ���? :: ";
	auto itr = s.find(20);
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}else {
		cout << "No" << endl;
	}

	cout << "25 �� s�� �����ΰ���? :: ";
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
	//��ü ���� ����ϱ�
	cout << "[ ";
	for (const auto& elem : iu) {
		cout << elem << " ";
	}
	cout << " ] " << endl;
}

int main() {
	deque<string> iu;
	iu.push_back("������");
	iu.push_back("������");
	iu.push_back("������");
	iu.push_back("�常��");

	cout << "�ʱ� iu ����" << endl;
	print_deque(iu);

	cout << "�� ���� ���� ����" << endl;
	iu.pop_front();
	print_deque(iu);
}*/

/*
template <typename T>
void print_list(list<T>& iu) {
	cout << "[ ";
	//��ü ����Ʈ�� ����ϱ�( �� ���� ���� ��� for ���� �� �� �ִ�.
	for (const auto& elem : iu) {
		cout << elem << " ";
	}
	cout << "]" << endl;
}

int main() {
	list<string> iu;

	iu.push_back("������");
	iu.push_back("������");
	iu.push_back("������");
	iu.push_back("�常��");

	cout << "ó�� ����Ʈ�� ����" << endl;
	print_list(iu);

	for (list<string>::iterator itr = iu.begin(); itr != iu.end(); ++itr) { // ++�� --���길 �����ϱ⶧���� for������ �ϳ��ϳ� ���Ҹ� Ȯ���ϴ°��� �����ϴ�.
		//���� ���� ���Ұ� ������ �̶��
		//�� �տ� �ؼ��� ���� �ִ´�.
		if (*itr == "������") {
			iu.insert(itr, "�ؼ�"); //vector�� �ٸ��� insert �۾��� O(1)���� �ſ� ������ ����ȴ�.
		}
	}
	cout << "���� �������� ���� �տ� 50�� �߰� " << endl;
	print_list(iu);

	for (list<string>::iterator itr = iu.begin(); itr != iu.end(); ++itr) {
		//���� �������� ���Ҹ� �����Ѵ�.
		if (*itr == "������") {
			iu.erase(itr); //����Ʈ�� ��� ���Ϳʹ� �ٸ���, ���Ҹ� ������ �ݺ��ڰ� ��ȿȭ���� �ʴ´�. �� ���ҵ��� �ּҰ����� �ٲ��� �ʱ� ������.
			break;
		}
	}
	cout << "���� �������� ���Ҹ� �����Ѵ�" << endl;
	print_list(iu);
}*/

/*
template <typename T>
void print_vector(vector<T>& iu) {
	//��ü ���� ����ϱ�
	for (typename vector<T>::iterator itr = iu.begin(); itr != iu.end(); ++itr) {
		cout << *itr << endl;
	}
}
template <typename T>
void print_vector_range_based(vector<T>& iu) {
	//��ü ���� ����ϱ�
	for (const auto& elem : iu) { //elem�� iu�� ���ҵ��� ��� ���۷����� �����ϰ� ��
		cout << elem << endl;
	}
}
int main() {
	vector<string> iu;
	iu.push_back("������");
	iu.push_back("������");
	iu.push_back("������");
	iu.push_back("�常��");

	cout << "print_vector" << endl;
	print_vector(iu);
	cout << "print_vector_range_based" << endl;
	print_vector_range_based(iu);

	return 0;
}*/
/*
int main() {
	vector<string> IU;
	IU.push_back("������");
	IU.push_back("������");
	IU.push_back("�常��");

	//range_based for ��
	for (string elem : IU) {
		cout << "���� : " << elem << endl;
	}

	return 0;
}*/

/*
template <typename T>
void print_vector(vector<T>& IU) {
	//��ü ���� ����ϱ�
	for (typename vector<T>::iterator itr = IU.begin(); itr != IU.end(); ++itr) { //�տ� typename�� �߰�������Ѵ�. iterator�� vector<T>�� ���� Ÿ���̱� ������.
	cout << *itr << endl; 
    }
}
int main() {
	vector<string> IU;
	IU.push_back("���� ��");
	IU.push_back("�ʶ� ��");
	IU.push_back("�ݿ��Ͽ� ������");
	IU.push_back("�� ��� ���� ����");

	cout << "ó�� ���� ����" << endl;
	print_vector(IU);
	cout << "-----------------------------" << endl;

	//IU[2] �տ� ���϶� �߰�
	IU.insert(IU.begin() + 2, "���϶�");
	print_vector(IU);
    cout << "-----------------------------" << endl;

	cout << "������ vec ����ϱ�" << endl;
	vector<string>::reverse_iterator r_iter = IU.rbegin();
	for (; r_iter != IU.rend(); r_iter++) {
		cout << *r_iter << endl;
	}
}*/
/*
int main() {
	vector<string> vec;
	vec.push_back("������");
	vec.push_back("������");
	vec.push_back("�常��");
	vec.push_back("�ؼ�");

	//��ü ���͸� ����ϱ�
	for (vector<string>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << endl; //* �����ڸ� �����ε��ؼ� ��ġ ������ó�� �����ϰ� ���� ���̴�. * �����ڴ� itr�� ����Ű�� ������ ���۷����� ����
	}

	//int arr[4] = {10, 20, 30, 40}
	// *(arr + 2) == arr[2] == 30;
	// *(itr + 2) == vec[2] == 30;

	vector<string>::iterator itr = vec.begin() + 2;
	cout << "3��° ���� :: " << *itr << endl;
}*/
/*
int main() {
	vector <int> vec;
	vec.push_back(10); //�ǵڿ� 10 �߰�
	vec.push_back(20); //�ǵڿ� 20 �߰�
	vec.push_back(30); //�ǵڿ� 30 �߰�
	vec.push_back(40); //�ǵڿ� 40 �߰�

	for (vector <int>::size_type i = 0; i < vec.size(); i++) {
		cout << "vec �� " << i + 1 << " ��° ���� :: " << vec[i] << endl;
	}
}*/
 
/* // Ÿ���� �˾Ƽ� �������ִ� auto Ű���� ���
int sum(int a, int b) { return a + b; }

class SomeClass {
	int data;

public:
	SomeClass(int d) : data(d) {}
	SomeClass(const SomeClass& s) : data(s.data) {}
};

int main() {
	auto c = sum(1, 2); //�Լ� ���� Ÿ�����κ��� int ��� ���� ����
	auto num = 1.0 + 2.0; //double�� ���� ����

	SomeClass some(10);
	auto some2 = some;

	auto some3(10); //SomeClass ��ü�� ������?

	cout << "c�� Ÿ����? :: " << typeid(c).name() << endl;
	cout << "num�� Ÿ����? :: " << typeid(num).name() << endl;
	cout << "some2�� Ÿ����? :: " << typeid(some2).name() << endl;
	cout << "some3�� Ÿ����? :: " << typeid(some3).name() << endl;
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
	//���ڷ� �޴� quantity�� ������ Ÿ�԰� Dim�� ������ Ÿ���� ��ġ�ؾ����� �ν��Ͻ�ȭ�ȴ�.(��ġ�����ʴٸ� ���� �߻���Ŵ)
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
	cout << "2kg ��ü�� 3m/s^2 �� ���ӵ��� �б� ���� ���� ũ���? " << F
		<< endl;

	//Good //�� ������ ��
	//kg + kg;

	//Bad //������ �ٸ��� ������ ���� �߻�
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
// �� ���� �ִ� ������� ���ϱ�
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
struct Ratio //�������� �������� ǥ�����ִ� Ŭ���� 
			 // ��ġ Ratio Ŭ������ ��ü�� ������ �� ������, ������ ������ ��ü�� �� ���� ����, �ܼ��� Ÿ�Ե鸸 ���� �� ���Դϴ�.
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
	using R1 = Ratio<2, 3>;  //C+11���� ���Ӱ� ���� using Ű���带 ����ϸ� typedef���� �� ���������� ��Ÿ���� �ִ�.
	using R2 = Ratio<3, 2>;

	using R3 = Ratio_add<R1, R2>;
	
	//typedef Ratio<2, 3> R1;
	//typedef Ratio<3, 2> R2;
	//typedef Ratio_add<R1, R2> R3;

	cout << R3::num << " / " << R3::den << endl;

	return 0;
}*/
/*
//���ø� ��Ÿ ���α׷���(TMP) ������� ���丮�� �� ���ϱ� 
template <int N> 
struct Factorial
{
	static const int result = N * Factorial<N - 1>::result;
};

template<> //���ø� Ư��ȭ ���
struct Factorial<1> 
{
	static const int result = 1; //����� ������ ���� �� �ְ� ���ش�.
};

int main() {
	cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << endl;
}*/