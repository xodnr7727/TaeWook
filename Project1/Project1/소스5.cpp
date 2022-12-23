#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <typeinfo>
using namespace std;
/*
template <int N>
struct Int
{
	const static int num = N;
};

template <typename T, typename U>
struct add{
	typedef Int<T::num + U::num> result; //���ο� Ÿ���� result ����
};

int main() {
	typedef Int<1> one; //one �� two�� ��ü�� �ƴϴ�. 1�� 2�� ���� ��Ÿ���� Ÿ��
	typedef Int<2> two;

	typedef add<one, two>::result three;

	cout << "Addtion result : " << three::num << endl;
}*/
/*
template <typename T, unsigned int N>
class Array {
	T data[N];

public:

	//�迭�� �޴� ���۷��� arr
	Array(T (&arr)[N]) {
		for (int i = 0; i < N; i++) {
			data[i] = arr[i];
		}
	}

	T* get_array() { return data; }

	unsigned int size() { return N; }

	void print_all() {
		for (int i = 0; i < N; i++) {
			cout << data[i] << ", ";
		}
		cout << endl;
	}
};

int main() {
	int arr[3] = { 1,2,3 };

	//�迭 wrapper Ŭ����
	Array<int, 3> arr_w(arr);

	arr_w.print_all();

	cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << endl;
}*/
/*
template <typename... Ints>
int sum_all(Ints... nums) { 
	return (... + nums); //C+17 ���� ���� ���Ե� Fold ����
}
int main() {
	cout << sum_all(1, 4, 2, 3, 10) << endl;
}*/
/*
//��� ȣ�� ���Ḧ ���� ���̽� ���̽� //�ڵ��� ���⵵�� �ø�
int sum_all() { return 0; }

template <typename... Ints>
int sum_all(int num, Ints... nums) {
	return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums) {
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int main() {
	cout << average(1, 4, 2, 3, 10) << endl;
}*/

/* ���� ���� ���ø� ��� ����
template <typename String>
string StrCat(const String& s) {
	return std::string(s);
}

template <typename String, typename... Strings>
string StrCat(const String& s, Strings... strs) {
	return std::string(s) + StrCat(strs...);
}

int main() {
	//string �� const char* �� ȥ���ؼ� ��� �����ϴ�.
	cout << StrCat(string("this"), " ", "is", " ", string("a"),
		" ", string("sentence"));
}*/
/* ���� ���� ���ø� ��� ����
template <typename T>
void print(T arg) {
	cout << arg << endl;
}

template <typename T, typename... Types> //���ø� �Ķ���� ��
void print(T arg, Types... args) { //�Լ� �Ķ���� ��
	cout << arg << ", ";
	print(args...);
}

int main() {
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);
}*/
/*
template <typename T> //Ÿ�� ���� Ƽ��Ʈ�� ���� �����ϴ�.
struct Compare {
	bool operator()(const T& a, const T& b) const { return a < b; }
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
	Comp comp;
	if (comp(a, b)) {
		return a;
	}
	return b;
}
int main() {
	int a = 3, b = 5;
	cout << "Min " << a << " , " << b << " :: " << Min(a, b) << endl;

	string s1 = "abc", s2 = "def";
	cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2) << endl;
}*/
/*
template <typename T, int num = 5> //����Ʈ ���ø� ����
T add_num(T t) { 
	return t + num;
}
int main() {
	int x = 3;
	cout << "x : " << add_num(x) << endl; 
	                 //add_num<int,5> �� �Ͱ� ����
}*/
/*
template <typename T>
	void print_array(const T&arr) {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int main() {
		array<int, 5> arr = { 1,2,3,4,5 };
		array<int, 7> arr1 = { 1,2,3,4,5,8,9 };
		array<int, 9> arr2 = { 1,2,3,4,5,6,7,7,9 };

		print_array(arr);
		print_array(arr1);
		print_array(arr2);
	}*/

/*
int main() {
	// ��ġ C������ �迭 ó�� {} �� ���� �迭�� ������ �� �ִ�.
	array<int, 5> arr = { 1,2,3,4,5 };
	//int arr[5] = {1,2,3,4,5}; �� ����
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}*/

/*
template <typename T, int num>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	cout << "x : " << add_num<int, 5 > (x) << endl;
}*/
/*
template <typename T>
T max(T& a, T& b) {
	return a > b ? a : b;
}

int main() {
	int a = 1, b = 2;
	cout << "Max (" << a << "," << b << ") ? : " << max(a, b) << endl; //�����Ϸ��� �˾Ƽ� max<int>(a, b)�� �����ؼ� �ν��Ͻ�ȭ ���ش�.

	string s = "hello", t = "world";
	cout << "Max (" << s << "," << t << ") ? : " << max(s, t) << endl; //�����Ϸ��� �˾Ƽ� max<string>(s, t)�� �����ؼ� �ν��Ͻ�ȭ ���ش�.
}*/
/*
template <typename T>
class Vector {
	T* data;
	int capacity;
	int length;

public:
	// � Ÿ���� �����ϴ���
	typedef T value_type;

	//������
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	//�� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
	void push_back(int s) {
		if (capacity <= length) {
			int* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		data[length] = s;
		length++;
	}

	//������ ��ġ�� ���ҿ� �����Ѵ�.
	T operator[](int i) { return data[i]; }

	//x��° ��ġ�� ���Ҹ� �����Ѵ�.
	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	//���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length; }

	void swap(int i, int j) {
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};
template <typename Cont>
void bubble_sort(Cont& cont) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i; j < cont.size(); j++) {
			if (cont[i] > cont[j]) {
				cont.swap(i, j);
			}
		}
	}
}
template <typename Cont, typename Comp>
void bubble_sort(Cont& cont, Comp& comp) {
	for (int i = 0; i < cont.size(); i++) {
		for (int j = i; j < cont.size(); j++) {
			if (!comp(cont[i],cont[j])) {
				cont.swap(i,j);
			}
		}
	}
}
struct Comp1
{
	bool operator()(int a, int b) { return a > b; }
};
struct Comp2
{
	bool operator()(int a, int b) { return a < b; }
};
int main() {
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(8);
	int_vec.push_back(5);
	int_vec.push_back(3);

	cout << "���� ���� ---- " << endl;
	for (int i = 0; i < int_vec.size(); i++) {
		cout << int_vec[i] << " ";
	}

	Comp1 comp1;
	bubble_sort(int_vec, comp1);

	cout << endl << endl << "�������� ���� ���� ---- " << endl;
	bubble_sort(int_vec);
	for (int i = 0; i < int_vec.size(); i++) {
		cout << int_vec[i] << " ";
	}
	cout << endl;

	Comp2 comp2;
	bubble_sort(int_vec, comp2);

	cout << endl << "�������� ���� ���� ---- " << endl;
	bubble_sort(int_vec);
	for (int i = 0; i < int_vec.size(); i++) {
		cout << int_vec[i] << " ";
	}

	cout << endl;
}*/
/*
template<>
class Vector<bool> {
	unsigned int* data;
	int capacity;
	int length;

public:
	typedef bool value_type;

	//������
	Vector(int n = 1)
		: data(new unsigned int[n / 32 + 1]), capacity(n / 32 + 1), length(0) {
		for (int i = 0; i < capacity; i++) {
			data[i] = 0;
		}
	}
	//�� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
	void push_back(bool s) {
		if (capacity * 32 <= length) {
			unsigned int* temp = new unsigned int[capacity * 2];
			for (int i = 0; i < capacity; i++) {
				temp[i] = data[i];
			}
			for (int i = capacity; i < 2 * capacity; i++) {
				temp[i] = 0;
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		if (s) {
			data[length / 32] |= (1<< (length %32));
		}
		length++;
	}

	//������ ��ġ�� ���ҿ� �����Ѵ�.
	bool operator[](int i) { return (data[i / 32] & (1 << (i & 32))) != 0; }

	//x��° ��ġ�� ���Ҹ� �����Ѵ�.
	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			int prev = i - 1;
			int curr = i;

			//���� curr ��ġ�� �ִ� ��Ʈ�� 1�̶��
			//prev ��ġ�� �ִ� ��Ʈ�� 1�� �����.
			if (data[curr / 32] & (i << (curr % 32))) {
				data[prev / 32] |= (1 << (prev % 32));
			}
			//�ƴϸ� prev ��ġ�� �ִ� ��Ʈ�� 0���� �����.
			else {
				unsigned int all_ones_except_prev = 0xFFFFFFFF;
				all_ones_except_prev ^= (1 << (prev % 32));
				data[prev / 32] &= all_ones_except_prev;
			}
		}
		length--;
	}

	//���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length; }

	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

int main() {
	//int �� �����ϴ� ���͸� �����.

	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(2);

	cout << "----------- int vector ------------" << endl;
	cout << "ù��° ���� : " << int_vec[0] << endl;
	cout << "�ι�° ���� : " << int_vec[1] << endl;

	Vector<string> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("world");
	cout << "---------- string vector ----------" << endl;
	cout << "ù��° ���� : " << str_vec[0] << endl;
	cout << "�ι�° ���� : " << str_vec[1] << endl;

	Vector<bool> bool_vec;
	bool_vec.push_back(true);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);
	bool_vec.push_back(true);
	bool_vec.push_back(false);

	cout << "-------- bool vector ---------" << endl;
	for (int i = 0; i < bool_vec.size(); i++) {
		cout << bool_vec[i];
	}
	cout << endl;
}*/
