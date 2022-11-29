#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "utils.h"

using namespace std;
/*
namespace MyExcel {
	Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

	void Vector::push_back(string s) {
		if (capacity <= length) {
			string* temp = new string[capacity * 2];
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

	string Vector::operator[](int i) { return data[i]; }

	void Vector::remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	int Vector::size() { return length; }

	Vector::~Vector() {
		if (data) {
			delete[] data;
		}
	}
	

	Stack::Stack() : start(NULL, "") { current = &start; }
	void Stack::push(string s) {
		Node* n = new Node(current, s);
		current = n;
	}
	string Stack::pop() {
		if (current == &start) return "";

		string s = current->s;
		Node* prev = current;
		current = current->prev;

		//Delete popped node
		delete prev;
		return s;
	}
	string Stack::peek() { return current->s; }
	bool Stack::is_empty() {
		if (current == &start) return true;
		return false;
	}
	Stack::~Stack() {
		while (current != &start) {
			Node* prev = current;
			current = current->prev;
			delete prev;
		}
	}
	NumStack::NumStack() :start(NULL, 0) { current = &start; }
	void NumStack::push(double s) {
		Node* n = new Node(current, s);
		current = n;
	}
	double NumStack::pop() {
		if (current == &start) return 0;
		double s = current->s;
		Node* prev = current;
		current = current->prev;

		//Delete popped node
		delete prev;
		return s;
	}
	double NumStack::peek() { return current->s; }

	bool NumStack::is_empty() {
		if (current == &start) return true;
		return false;
	}
	NumStack::~NumStack() {
		while (current != &start) {
			Node* prev = current;
			current = current->prev;
			delete prev;
		}
	}
	Cell::Cell(string data, int x, int y, Table* table)
		:data(data), x(x), y(y), table(table) {}
	string Cell::stringify() { return data; }
	int Cell::to_numeric(){ return 0; }

	Table::Table(int max_row_size, int max_col_size)
		: max_row_size(max_row_size), max_col_size(max_col_size) {
		data_table = new Cell**[max_row_size];
		for (int i = 0; i < max_row_size; i++) {
			data_table[i] = new Cell * [max_col_size];
		for (int j = 0; j < max_col_size; j++) {
			data_table[i][j] = NULL;
			}
		}
	}
	void Table::reg_cell(Cell* c, int row, int col) {
		if (!(row < max_row_size && col < max_col_size)) return;

		if (data_table[row][col]) {
			delete data_table[row][col];
		}
		data_table[row][col] = c;
	}
	int Table::to_numeric(const string& s) {
		// Cell 이름으로 받는다.
		int col = s[0] - 'A';
		int row = atoi(s.c_str() + 1) - 1;

		if (row < max_row_size && col < max_col_size) {
			if (data_table[row][col]) {
				return data_table[row][col]->to_numeric();
			}
		}
		return 0;
	}
	int Table::to_numeric(int row, int col) {
		if (row < max_row_size && col < max_col_size && data_table[row][col]) {
			return data_table[row][col]->to_numeric();
		}
		return 0;
	}
	string Table::stringify(const string& s) {
		// Cell 이름으로 받는다.
		int col = s[0] - 'A';
		int row = atoi(s.c_str() + 1) - 1;

		if (row < max_row_size && col < max_col_size) {
			if (data_table[row][col]) {
				return data_table[row][col]->stringify();
			}
		}
		return 0;
	}
	string Table::stringify(int row, int col) {
		if (row < max_row_size && col < max_col_size && data_table[row][col]) {
			return data_table[row][col]->stringify();
		}
		return "";
	}
	std::ostream& operator<<(std::ostream& o, Table& table) {
		o << table.print_table();
		return o;
	}
	Table::~Table() {
		for (int i = 0; i < max_row_size; i++) {
			for (int j = 0; j < max_col_size; j++) {
				if (data_table[i][j]) delete data_table[i][j];
			}
		}
		for (int i = 0; i < max_row_size; i++) {
			delete[] data_table[i];
		}
		delete[] data_table;
	}
	TxtTable::TxtTable(int row, int col) : Table(row, col){}

	//텍스트로 표를 깨끗하게 출력해준다.
	string TxtTable::print_table() {
		string total_table;

		int* col_max_wide = new int[max_col_size];
		for (int i = 0; i < max_col_size; i++) {
			unsigned int max_wide = 2;
			for (int j = 0; j < max_row_size; j++) {
				if (data_table[j][i] &&
					data_table[j][i]->stringify().length() > max_wide) {
					max_wide = data_table[j][i]->stringify().length();
				}
			}
			col_max_wide[i] = max_wide;
		}
		//맨 상단에 열 정보 표시
		total_table += "     ";
		int total_wide = 4;
		for (int i = 0; i < max_col_size; i++) {
			if (col_max_wide[i]) {
				int max_len = max(2, col_max_wide[i]);
				total_table += " | " + col_num_to_str(i);
				total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

				total_wide += (max_len + 3);
			}
		}
		total_table += "\n";
		//일반 기본적으로 최대 9999번째 행 까지 지원한다고 생각한다.
		for (int i = 0; i < max_row_size; i++) {
			total_table += repeat_char(total_wide, '-');
			total_table += "\n" + to_string(i + 1);
			total_table += repeat_char(4 - to_string(i + 1).length(), ' ');

			for (int j = 0; j < max_col_size; j++) {
				if (col_max_wide[j]) {
					int max_len = max(2, col_max_wide[j]);

					string s = "";
					if (data_table[i][j]) {
						s = data_table[i][j]->stringify();
					}
					total_table += " | " + s;
					total_table += repeat_char(max_len - s.length(), ' ');
				}
			}
			total_table += "\n";
		}
		return total_table;
	}
	string TxtTable::repeat_char(int n, char c) {
		string s = "";
		for (int i = 0; i < n; i++) s.push_back(c);

		return s;
	}
	//숫자로 된 열 번호를 A, B, ..... Z, AA, AB, ... 이런 순으로 매겨준다.
	string TxtTable::col_num_to_str(int n) {
		string s = "";
		if (n < 26) {
			s.push_back('A' + n);
		}else{
			char first = 'A' + n / 26 - 1;
			char second = 'A' + n % 26;

			s.push_back(first);
			s.push_back(second);
		}

		return 0;
	}
	int main() {
		MyExcel::TxtTable table(5, 5);
		ofstream out("text.txt");

		table.reg_cell(new Cell("Hello~", 0, 0, &table), 0, 0);
		table.reg_cell(new Cell("C++", 0, 0, &table), 0, 1);

		table.reg_cell(new Cell("Programming", 0, 0, &table), 1, 1);
		cout << endl << table;
		out << table;
	}
}*/

/*
string to_str(int x) {
	ostringstream ss;
	ss << x;

	return ss.str();
}
int main() {
	cout << "문자열로 변환:: 1 + 2 = " << to_str(1 + 2) << endl;

	return 0;
}*/
/*
int main() {
	std::istringstream ss("123");
	int x;
	ss >> x;

	cout << "입력 받은 데이터 :: " << x << endl;

	return 0;
}*/

/*
class Human {
	string name;
	int age;

public:
	Human(const string& name, int age) : name(name), age(age) {}
	string get_info() {
		return "Name :: " + name + " / Age :: " + to_string(age);
	}

	friend ofstream& operator<<(ofstream& o, Human& h);
};
ofstream& operator<<(ofstream& o, Human& h) {
	o << h.get_info();
	return o;
}
int main() {
	//파일 쓰기 준비
	ofstream out("text.txt");

	Human h("이현아", 23);
	out << h << endl;

	return 0;
}*/

/*
int main() {
	ofstream out1("text1.txt", ios::app);
	ofstream out2("text2.txt", ios::ate);

	out1.seekp(3, ios::beg);
	out2.seekp(3, ios::beg);

	out1 << "추가";
	out2 << "추가";

	return 0;
}*/
/*
int main() {
	//파일 쓰기 준비
	ofstream out("text.txt",ios::app);

	string s;
	if (out.is_open()) {
		out << "덧붙이기";
	}
	return 0;
}*/