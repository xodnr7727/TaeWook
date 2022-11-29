/*#include <cstdio>
#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <vector>
using namespace std;

class Date {
	int year_;
	int month_;
	int day_;
public:
	void SetDate(int year, int month, int day); 
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();
};
void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}
int Date::GetCurrentMonthTotalDays(int year, int month) {
	static int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if(month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29; //����
	}
	else {
		return 28;
	}
}
void Date::AddDay(int inc) {
	while (true) {
		//���� ���� ���ϼ�
		int Current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		//���� �� �ȿ� ���´ٸ�
		if (day_ + inc <= Current_month_total_days) {
			day_ += inc;
			return;
		}else {
			//���� �޷� �Ѿ�� �Ѵ�
			inc -= (Current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}
void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
	cout << "������ " << year_ << "�� " << month_ << "�� " << day_ << "���Դϴ�. " << endl;
}
int main() {
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();
	
	Date day1 = Date(); //����Ʈ ������ ����
	day1.SetDate(2011, 3, 1);
	day1.ShowDate();
  
	return 0;
}

/*  Date day(2011, 3, 1);        �Ͻ��� ��� (implicit) (��ȣ)
	Date day = Date(2012, 3, 1); ����� ��� (explicit) */

/*class Test {
public:
	Test() = default;  // ����Ʈ �����ڸ� �����ض�
};*/


/*���۷����� �޸𸮻� �������� ���� �� �� �ִ�.

int a = 10;
int* p = &a; // p�� �޸� �󿡼� ����� 8 ����Ʈ�� ����.

int a = 10;
int another_a = a; // another_a �� �ڸ��� ���� �� �ʿ䰡 ������?
*/


/*int user_input;
cout << "�������� ���� �ñ��Ѱ���?" << endl;
cout << "1. �̸�" << endl;
cout << "2. �������" << endl;
cout << "3. ���߰�" << endl;
cin >> user_input;

sndPlaySoundA("C:\\Users\\xodnr\\source\\repos\\Project2\\Project2\\video.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP); // ���ǿ��� C:\\~~~ �� ��θ��� �Է��մϴ�. (��, ������ �����ϴ� ���������� 2�� �� ��� �մϴ�. ��) C:\test\aa.wav  �� ��� "C:\\test\\aa.wav"
system("pause");

switch (user_input)
{
case 1:
	cout << "������ !" << endl;
	break;
case 2:
	cout << "1993�� 5�� 16��" << endl;
	break;
case 3:
	cout << "�̾�" << endl;
	break;
default:
	cout << "�ñ��Ѱ� ������" << endl;
	break;
}
return 0;
*/

/*int lucky_number = 3;
	cout << "�� ���ڸ� ����������!" << endl;

	int user_input;

	while (1) {
		cout << "�Է�: ";
		cin >> user_input;
		if (lucky_number == user_input) {
			cout << "���߼̽��ϴ�!" << endl;
			break;
		}
		else {
			cout << "�ٽ� �����غ�����~" << endl;
		}
	}
	return 0;
}

/*
	int arr[10];
	int* parr = arr;

	int* p = &i;
*/
