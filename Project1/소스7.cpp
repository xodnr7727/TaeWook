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
using namespace std;
/* //transform(���� �����ϱ�) �Լ�
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

	vector<int> vec2(6, 0);

	cout << "ó�� vec �� vec2 ����-----" << endl;
	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());

	cout << "vec ��ü�� 1�� ���� ���� vec2 �� ����-----" << endl;
	transform(vec.begin(), vec.end(), vec2.begin(),
		[](int i) {return i + 1; });
	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());
}*/
/*
template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << "[" << *begin << "]";
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

	cout << "ó�� vec ����-----" << endl;
	print(vec.begin(), vec.end());

	cout << "���Ϳ��� Ȧ���� ���� ���� ---" << endl;
	int num_erased = 0;
	vec.erase(remove_if(vec.begin(), vec.end(),
		[&num_erased](int i) {
			if (num_erased >= 2)
				return false;
			else if (i % 2 == 1) {
				num_erased++;
				return true;
			}
			return false;
		}),
		vec.end());
	print(vec.begin(), vec.end());
}
*/
/*
template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << "[" << *begin << "] ";
		begin++;
	}
	cout << endl;
}

struct is_odd {
	int* num_delete;

	is_odd(int* num_delete) : num_delete(num_delete) {}

	bool operator()(const int& i) {
		if (*num_delete >= 2) return false;

		if (i % 2 == 1) {
			(*num_delete)++;
			return true;
		}
		return false;
	}
};
int main() {
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	cout << "ó�� vec�� ���� ----" << endl;
	print(vec.begin(), vec.end());

	cout << "���Ϳ��� Ȧ�� �� ���� ���� 2�� ���� ----" << endl;
	int num_delete = 0;
	vec.erase(remove_if(vec.begin(), vec.end(), is_odd(&num_delete)), vec.end());
	//remove_if�Լ��� ����° ���ڷ� ������ ������ �Լ� ��ü�� ���� �޴´�.
	
	//cout << "���Ϳ��� ���� 3�� ���� ���� ----" << endl;
	//vec.erase(remove(vec.begin(), vec.end(), 3), vec.end()); 
	//remove�Լ��� �̿��ؼ� 3 �� ���ҵ��� �ڷ� ���������� erase �Լ��� ȣ���Ͽ� ������ ���Ҹ� �����ش�.
	print(vec.begin(), vec.end());
}*/

/* //stable_sort �Լ�
template<typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << "[" << * begin << "] ";
		begin++;
	}
	cout << endl;
}
struct User {
	string name;
	int age;

	User(string name, int age) : name(name), age(age) {}

	bool operator<(const User& u) const { return age < u.age; }
};

ostream& operator<<(ostream& o, const User& u) {
	o << u.name << " , " << u.age;
	return o;
}
int main() {
	vector<User> vec;
	for (int i = 0; i < 100; i++) {
		string name = "";
		name.push_back('a' + 1 / 26);
		name.push_back('b' + 1 % 26);
		vec.push_back(User(name, static_cast<int>(rand() % 10)));
	}

	vector<User> vec2 = vec;

	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());
	
	sort(vec.begin(), vec.end());

	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());

	cout << "stable_sort�� ��� ---" << endl;
	stable_sort(vec2.begin(), vec2.end());
	print(vec2.begin(), vec2.end());
}*/
/*
//partial_sort �Լ�
template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << *begin << " ";
		begin++;
	}
	cout << endl;
}
int main() {
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);

	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());
	partial_sort(vec.begin(), vec.begin() + 3, vec.end());

	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());
}*/
/* //sort �Լ�
template <typename Iter>
void print(Iter begin, Iter end) {
	while (begin != end) {
		cout << *begin << " ";
		begin++;
	}
	cout << endl;
}
template<typename T>
struct greater_comp {
	bool operator()(const T& a, const T& b) const { return a > b; } 
};
int main() {
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(1);
	vec.push_back(6);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(2);
	
	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(), greater<int>());

	cout << "���� �� ----" << endl;
	print(vec.begin(), vec.end());
}
*/
/*
template <typename K>
void print_unordered_set(const unordered_set<K>& m) {
	for (const auto& elem : m) {
		cout << elem << endl;
	}
}
template <typename K>
void is_exist(unordered_set<K>& s, K key) {
	auto itr = s.find(key);
	if (itr != s.end()) {
		cout << key << " �� ����!" << endl;
	}else {
		cout << key << "�� ����" << endl;
	}
}
class Todo {
	int priority;
	string job_desc;

public:
	Todo(int priority, string job_desc)
		:priority(priority), job_desc(job_desc) {}

	bool operator==(const Todo& t)const {
		if (priority == t.priority && job_desc == t.job_desc) return true;
		return false;
	}

	friend ostream& operator<<(ostream& o, const Todo& t);
	friend struct hash<Todo>;
};

//Todo �ؽ� �Լ��� ���� �Լ���ü(Functor) �� ������ش�
namespace std {
	template <>
	struct hash<Todo> {
		size_t operator()(const Todo& t)const {
			hash<string> hash_func;

			return t.priority ^ (hash_func(t.job_desc));
		}
	};
} // namespace std
ostream& operator<<(ostream& o, const Todo& t) {
	o << "[�߿䵵 : " << t.priority << " ] " << t.job_desc;
	return o;
}
int main() {
	unordered_set<Todo> todos;

	todos.insert(Todo(1, "�� �ϱ�"));
	todos.insert(Todo(2, "���� ���� �ϱ�"));
	todos.insert(Todo(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo(3, "ģ�� ������"));
	todos.insert(Todo(2, "��ȭ ����"));
	print_unordered_set(todos);
	cout << "-------------------" << endl;
}*/
/*
int main() {
	unordered_set<string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("psi");
	s.insert("welcome");
	s.insert("to");
	s.insert("c++");

	print_unordered_set(s);
	cout << "--------------" << endl;
	is_exist(s, string("c++"));
	is_exist(s, string("c"));

	cout << "--------------" << endl;
	cout << "hi�� ����" << endl;
	s.erase(s.find("hi"));
	is_exist(s, string("hi"));
}*/
/*
template <typename K, typename V>
void print_map(const multimap<K, V>& m) {
	for (const auto& kv : m) {
		cout << kv.first << " " << kv.second << endl;
	}
}
int main() {
	multimap<int, string> m;
	m.insert(make_pair(1, "hello"));
	m.insert(make_pair(1, "hi"));
	m.insert(make_pair(1, "ahihi"));
	m.insert(make_pair(2, "bye"));
	m.insert(make_pair(2, "baba"));

	print_map(m);

	//1�� Ű�� ������ �ݺ��ڵ��� ���۰� ����
	//pair�� ���� �����Ѵ�.
	auto range = m.equal_range(1);
	for (auto itr = range.first; itr != range.second; ++itr) {
		cout << itr->first << " : " << itr->second << " " << endl;
	}
}*/

/*
template <typename K>
void print_set(const multiset<K>& s) {
	for (const auto& elem : s) {
		cout << elem << endl;
	}
}

int main() {
	multiset<string> s; 

	s.insert("a");
	s.insert("b");
	s.insert("a");
	s.insert("c");
	s.insert("d");
	s.insert("c");
	//��Ƽ���� ��� �ߺ��� ���Ҹ� ����ϱ� ������ insert�� ��� ���ҵ��� �޸��� ���´�.
	print_set(s);
}*/

/*
template <typename K, typename V>
void print_map(map<K, V>& m) {
	//kv���� ���� key�� value�� pair�� ���ϴ�.
	for (const auto& kv : m) { // ���� ��� for��
		cout << kv.first << " " << kv.second << endl;
	}
}
template <typename K, typename V>
void search_and_print(map<K, V>& m, K key) {
	auto itr = m.find(key); //find �Լ��� �̿��ؼ� �����ϰ� Ű�� �����Ǵ� ���� ã�´�.
	if (itr != m.end()) {
		cout << key << " --> " << itr->second << endl;
	}else{
		cout << key << "��(��) ��Ͽ� �����ϴ�." << endl;
	}
}
int main() {
	map<string, double> pitcher_list;

	pitcher_list["����ȯ"] = 3.58;

	print_map(pitcher_list);
	cout << "---------------" << endl;

	search_and_print(pitcher_list, string("����ȯ"));
	search_and_print(pitcher_list, string("������"));
}*/

/*
template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
	// kv ���� ���� key �� value �� std::pair �� ���ϴ�.
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

int main() {
	std::map<std::string, double> pitcher_list;

	pitcher_list["����ȯ"] = 3.58;
	std::cout << "������ �������? :: " << pitcher_list["������"] << std::endl; // �ʿ� ���� Ű�� ����, �ڵ����� ���� ����Ʈ �����ڸ� ȣ���ؼ� ���Ҹ� �߰��ع�����.

	std::cout << "-----------------" << std::endl;
	print_map(pitcher_list);
}*/
/*
template <typename K, typename V>
void print_map(map<K, V>& m) {
	//kv���� ���� key�� value�� pair�� ���ϴ�.
	for (const auto& kv: m) { // ���� ��� for��
		cout << kv.first << " " << kv.second << endl;
	}
}
int main() {
	map<string, double> pitcher_list; // ù ��°�� Ű�� Ÿ��, �� ��°�� ���� Ÿ��

	//���� insert �Լ��� pair ��ü�� ���ڷ� �޽��ϴ�
	//pitcher_list.insert(pair<string, double>("�ڼ���", 2.23));
	//pitcher_list.insert(pair<string, double>("��Ŀ", 2.93));

	//pitcher_list.insert(pair<string, double>("�Ǿ���", 2.95));
	
	//Ÿ���� �������� �ʾƵ� ������ mke_pair �Լ���
	//pair ��ü�� ���� �� �� �ִ�.
	pitcher_list.insert(make_pair("������", 3.04));
	pitcher_list.insert(make_pair("�����", 3.05));
	pitcher_list.insert(make_pair("����", 3.09));

	//Ȥ�� insert�� �Ⱦ����� []�� �ٷ�
	//���Ҹ� �߰��� �� �ִ�.
	pitcher_list["����Ʈ"] = 3.56;
	pitcher_list["������"] = 3.76;
	pitcher_list["�̸�"] = 3.90;

	print_map(pitcher_list);

	cout << "�ڼ��� �������? :: " << pitcher_list["�ڼ���"] << endl;

}*/

/*
//Ŭ���� ��ü�� �¿� �ְ� ������
template <typename T, typename C>
void print_set(set<T,C>& s) {
	for (const auto& elem : s) {
		cout << elem << " " << endl;
	}
}
class Todo {
	int priority; //�߿䵵, ���� ���� ���Ѱ�
	string jop_desc;

public:
	Todo(int priority, string job_desc)
		: priority(priority), jop_desc(job_desc) {}

	friend struct TodoCmp;

	friend ostream& operator<<(ostream& o, const Todo& td);
};
struct TodoCmp{
	bool operator()(const Todo& t1, const Todo& t2)const { //�Լ� ��ü
		if (t1.priority == t2.priority) {
			return t1.jop_desc < t2.jop_desc;
		}
		return t1.priority > t2.priority;
	}
};
ostream& operator<<(ostream& o, const Todo& td) {
	o << "{ �߿䵵: " << td.priority << "] " << td.jop_desc;
	return o;
}
int main() {
	set<Todo, TodoCmp> todos;

	todos.insert(Todo(1, "���ϱ�"));
	todos.insert(Todo(2, "���� ���� �ϱ�"));
	todos.insert(Todo(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo(3, "ģ�� ������"));
	todos.insert(Todo(2, "��ȭ ����"));

	print_set(todos);

	cout << "-------------" << endl;
	cout << "������ ���´ٸ�!" << endl;
	todos.erase(todos.find(Todo(2, "���� ���� �ϱ�")));
	print_set(todos);
}*/