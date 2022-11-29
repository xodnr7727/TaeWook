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
/* //transform(원소 수정하기) 함수
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

	cout << "처음 vec 과 vec2 상태-----" << endl;
	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());

	cout << "vec 전체에 1을 더한 것을 vec2 에 저장-----" << endl;
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

	cout << "처음 vec 상태-----" << endl;
	print(vec.begin(), vec.end());

	cout << "벡터에서 홀수인 원소 제거 ---" << endl;
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

	cout << "처음 vec의 상태 ----" << endl;
	print(vec.begin(), vec.end());

	cout << "벡터에서 홀수 인 원소 앞의 2개 제거 ----" << endl;
	int num_delete = 0;
	vec.erase(remove_if(vec.begin(), vec.end(), is_odd(&num_delete)), vec.end());
	//remove_if함수는 세번째 인자로 조건을 설명할 함수 객체를 전달 받는다.
	
	//cout << "벡터에서 값이 3인 원소 제거 ----" << endl;
	//vec.erase(remove(vec.begin(), vec.end(), 3), vec.end()); 
	//remove함수를 이용해서 3 인 원소들을 뒤로 보내버리고 erase 함수를 호출하여 실제로 원소를 지워준다.
	print(vec.begin(), vec.end());
}*/

/* //stable_sort 함수
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

	cout << "정렬 전 ----" << endl;
	print(vec.begin(), vec.end());
	
	sort(vec.begin(), vec.end());

	cout << "정렬 후 ----" << endl;
	print(vec.begin(), vec.end());

	cout << "stable_sort의 경우 ---" << endl;
	stable_sort(vec2.begin(), vec2.end());
	print(vec2.begin(), vec2.end());
}*/
/*
//partial_sort 함수
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

	cout << "정렬 전 ----" << endl;
	print(vec.begin(), vec.end());
	partial_sort(vec.begin(), vec.begin() + 3, vec.end());

	cout << "정렬 후 ----" << endl;
	print(vec.begin(), vec.end());
}*/
/* //sort 함수
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
	
	cout << "정렬 전 ----" << endl;
	print(vec.begin(), vec.end());
	sort(vec.begin(), vec.end(), greater<int>());

	cout << "정렬 후 ----" << endl;
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
		cout << key << " 가 존재!" << endl;
	}else {
		cout << key << "가 없다" << endl;
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

//Todo 해시 함수를 위한 함수객체(Functor) 를 만들어준다
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
	o << "[중요도 : " << t.priority << " ] " << t.job_desc;
	return o;
}
int main() {
	unordered_set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));
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
	cout << "hi를 삭제" << endl;
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

	//1을 키로 가지는 반복자들의 시작과 끝을
	//pair로 만들어서 리턴한다.
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
	//멀티셋의 경우 중복된 원소를 허락하기 때문에 insert한 모든 원소들이 쭈르륵 나온다.
	print_set(s);
}*/

/*
template <typename K, typename V>
void print_map(map<K, V>& m) {
	//kv에는 맵의 key와 value가 pair로 들어갑니다.
	for (const auto& kv : m) { // 범위 기반 for문
		cout << kv.first << " " << kv.second << endl;
	}
}
template <typename K, typename V>
void search_and_print(map<K, V>& m, K key) {
	auto itr = m.find(key); //find 함수를 이용해서 안전하게 키에 대응되는 값을 찾는다.
	if (itr != m.end()) {
		cout << key << " --> " << itr->second << endl;
	}else{
		cout << key << "은(는) 목록에 없습니다." << endl;
	}
}
int main() {
	map<string, double> pitcher_list;

	pitcher_list["오승환"] = 3.58;

	print_map(pitcher_list);
	cout << "---------------" << endl;

	search_and_print(pitcher_list, string("오승환"));
	search_and_print(pitcher_list, string("류현진"));
}*/

/*
template <typename K, typename V>
void print_map(const std::map<K, V>& m) {
	// kv 에는 맵의 key 와 value 가 std::pair 로 들어갑니다.
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

int main() {
	std::map<std::string, double> pitcher_list;

	pitcher_list["오승환"] = 3.58;
	std::cout << "류현진 방어율은? :: " << pitcher_list["류현진"] << std::endl; // 맵에 없는 키를 참조, 자동으로 값의 디폴트 생성자를 호출해서 원소를 추가해버린다.

	std::cout << "-----------------" << std::endl;
	print_map(pitcher_list);
}*/
/*
template <typename K, typename V>
void print_map(map<K, V>& m) {
	//kv에는 맵의 key와 value가 pair로 들어갑니다.
	for (const auto& kv: m) { // 범위 기반 for문
		cout << kv.first << " " << kv.second << endl;
	}
}
int main() {
	map<string, double> pitcher_list; // 첫 번째는 키의 타입, 두 번째는 값의 타입

	//맵의 insert 함수는 pair 객체를 인자로 받습니다
	//pitcher_list.insert(pair<string, double>("박세웅", 2.23));
	//pitcher_list.insert(pair<string, double>("해커", 2.93));

	//pitcher_list.insert(pair<string, double>("피어밴드", 2.95));
	
	//타입을 지정하지 않아도 간단히 mke_pair 함수로
	//pair 객체를 만들 수 도 있다.
	pitcher_list.insert(make_pair("차우진", 3.04));
	pitcher_list.insert(make_pair("장원준", 3.05));
	pitcher_list.insert(make_pair("헥터", 3.09));

	//혹은 insert를 안쓰더라도 []로 바로
	//원소를 추가할 수 있다.
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;

	print_map(pitcher_list);

	cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << endl;

}*/

/*
//클래스 객체를 셋에 넣고 싶을때
template <typename T, typename C>
void print_set(set<T,C>& s) {
	for (const auto& elem : s) {
		cout << elem << " " << endl;
	}
}
class Todo {
	int priority; //중요도, 높을 수록 급한것
	string jop_desc;

public:
	Todo(int priority, string job_desc)
		: priority(priority), jop_desc(job_desc) {}

	friend struct TodoCmp;

	friend ostream& operator<<(ostream& o, const Todo& td);
};
struct TodoCmp{
	bool operator()(const Todo& t1, const Todo& t2)const { //함수 객체
		if (t1.priority == t2.priority) {
			return t1.jop_desc < t2.jop_desc;
		}
		return t1.priority > t2.priority;
	}
};
ostream& operator<<(ostream& o, const Todo& td) {
	o << "{ 중요도: " << td.priority << "] " << td.jop_desc;
	return o;
}
int main() {
	set<Todo, TodoCmp> todos;

	todos.insert(Todo(1, "농구하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));

	print_set(todos);

	cout << "-------------" << endl;
	cout << "숙제를 끝냈다면!" << endl;
	todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
	print_set(todos);
}*/