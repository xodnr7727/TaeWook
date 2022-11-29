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
		return 29; //윤년
	}
	else {
		return 28;
	}
}
void Date::AddDay(int inc) {
	while (true) {
		//현재 달의 총일수
		int Current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		//같은 달 안에 들어온다면
		if (day_ + inc <= Current_month_total_days) {
			day_ += inc;
			return;
		}else {
			//다음 달로 넘어가야 한다
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
	cout << "오늘은 " << year_ << "년 " << month_ << "월 " << day_ << "일입니다. " << endl;
}
int main() {
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();
	
	Date day1 = Date(); //디폴트 생성자 예시
	day1.SetDate(2011, 3, 1);
	day1.ShowDate();
  
	return 0;
}

/*  Date day(2011, 3, 1);        암시적 방법 (implicit) (선호)
	Date day = Date(2012, 3, 1); 명시적 방법 (explicit) */

/*class Test {
public:
	Test() = default;  // 디폴트 생성자를 정의해라
};*/


/*레퍼런스는 메모리상 존재하지 않을 수 도 있다.

int a = 10;
int* p = &a; // p는 메모리 상에서 당당히 8 바이트를 차지.

int a = 10;
int another_a = a; // another_a 가 자리를 차지 할 필요가 있을까?
*/


/*int user_input;
cout << "아이유에 대해 궁금한것은?" << endl;
cout << "1. 이름" << endl;
cout << "2. 생년월일" << endl;
cout << "3. 데뷔곡" << endl;
cin >> user_input;

sndPlaySoundA("C:\\Users\\xodnr\\source\\repos\\Project2\\Project2\\video.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP); // 음악연주 C:\\~~~ 는 경로명을 입력합니다. (단, 폴더를 구분하는 역슬래쉬는 2번 써 줘야 합니다. 예) C:\test\aa.wav  일 경우 "C:\\test\\aa.wav"
system("pause");

switch (user_input)
{
case 1:
	cout << "이지은 !" << endl;
	break;
case 2:
	cout << "1993년 5월 16일" << endl;
	break;
case 3:
	cout << "미아" << endl;
	break;
default:
	cout << "궁금한게 없군요" << endl;
	break;
}
return 0;
*/

/*int lucky_number = 3;
	cout << "내 숫자를 맞혀보세요!" << endl;

	int user_input;

	while (1) {
		cout << "입력: ";
		cin >> user_input;
		if (lucky_number == user_input) {
			cout << "맞추셨습니다!" << endl;
			break;
		}
		else {
			cout << "다시 생각해보세요~" << endl;
		}
	}
	return 0;
}

/*
	int arr[10];
	int* parr = arr;

	int* p = &i;
*/
