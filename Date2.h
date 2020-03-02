#pragma once
using namespace std;
#include <string>
using std::string;
class Date2
{
public:
	Date2(int, int, int);
	~Date2();
	int getDay();
	int getMonth();
	int getYear();
	int getDaysInMonth();
	Date2& setAll(int, int, int);
	Date2& setDayPub(int);
	Date2& setMonthPub(int);
	Date2& setYearPub(int);
	bool operator == (Date2);
	bool operator != (Date2);
	Date2& operator ++(); //prefix ++
	Date2 operator ++(int); //postfix ++
	Date2& operator --(); //prefix --
	Date2 operator --(int); //postfix --
	Date2& addYear(int);
	Date2& operator+(unsigned int);
	Date2& operator-(unsigned int);
	Date2& operator+=(unsigned int);
	int operator - (Date2);

	Date2& addMonth(int);
	Date2& printDate();

private:
	int day;
	int month;
	int year;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string monthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
protected:

};

