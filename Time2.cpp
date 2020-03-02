#include "Time2.h"
using namespace std;
#include <iostream>

Time2::Time2(int h, int m, int s) 
{
	
	try {
		setHour(h);
		setMin(m);
		setSec(s);
	}
	catch (const char* e) {		//error message
		throw e;
	}

}
Time2::~Time2() 
{
	
}
Time2& Time2::setAll(int h, int m, int s)
{
	try {
		setHour(h);
		setMin(m);
		setSec(s);
	}
	catch (const char* e) {		//error message
		throw e;
	}
}
int Time2::getHour() 
{
	return hour;
}
int Time2::getMin() 
{
	return minute;
}
int Time2::getSec() 
{
	return second;
}
void Time2::setHour(int h) 
{
	if (h >= 1 && h <= 24) {
		hour = h;
	}else
		throw "invalid hours";
}
void Time2::setMin(int m)
{
	if (m >= 0 && m <= 59) {
		minute = m;
	}
	else
		throw "invalid minutes";
}
void Time2::setSec(int s) 
{
	if (s >= 0 && s <= 59) {
		second = s;
	}
	else
		throw "invalid seconds";
}
Time2& Time2::addHour(int addH) 
{
	hour = hour + addH;
	if (hour < 24) {
		return*this;
	}
	else
		while (hour > 24) {
			hour = hour - 24;
		}
	
	return *this;
}
Time2& Time2::addMin(int addM) 
{
	minute = minute + addM;
	if (minute < 60) {
		return *this;
	}
	else {
		while (minute > 60 || hour > 24)
			if (hour > 24) {
				hour = 1;
			}
			else{
				++hour;
				minute = minute - 60;
			}
				
	}
	return *this;
}
Time2& Time2::addSec(int addS) 
{
	second = second + addS;           //second = 31 + 15
	if (second < 60) {
		return *this;
	}
	else {
		while(second > 60 || minute > 60 || hour > 24)
			if (minute >= 60) {
				hour++;
				minute = 0;
				if (hour > 24) {
					hour = 1;
					minute = 0;
				}
			
			}
			else {
				++minute;
				second = second - 60;
			}
	
	}
	return *this;
}
Time2& Time2::subHour(int subH) 
{
	hour = hour - subH;
	if (hour < 24 && hour > 0)
	{
		return *this;
	}
	else {
		while (hour <= 1){
			hour = hour + 24;
			}
}
	return *this;
}
Time2& Time2::subMin(int subM) {
	minute = minute - subM;
	if (minute > 0 && minute < 60) {
		return *this;
	}
	else {
		while (minute < 1 || hour < 1) {
			if (hour < 1) {
				hour = 24;
			}
			else {
				--hour;
				minute = minute + 60;
			}
		}
	}

	return *this;
}
bool Time2::operator == (Time2 rhs)
{
	if (hour == rhs.getHour() && minute == rhs.getMin() && second == rhs.getSec()) {
		cout << "true";
		return true;
	}
	else {
		cout << "false";
		return false;
	}
}
bool Time2::operator!=(Time2 rhs) {
	return !(*this == rhs);
}
Time2& Time2::operator ++() 
{
	hour++;
	if (hour > 24) {
		hour = 1;
	}
	return *this;
}
Time2 Time2::operator++(int) {
	Time2 temp = *this;
	++(*this);
	return temp;
}
Time2& Time2::operator --() {
	hour--;
	if (hour < 1) {
		hour = 24;
	}
	return *this;
}
Time2 Time2::operator --(int) //subtracts 1 hr postfix
{
	Time2 temp = *this;
	--(*this);
	return temp;
}
Time2& Time2::estTime() 
{
	hour = hour + 1;
	cout << "Eastern Standard Time" << endl;
	return *this;
}
Time2& Time2::pstTime() {
	hour = hour - 2;
	cout << "Pacific Standard Time" << endl;
	return *this;
}
Time2& Time2::MNTime()
{
	hour = hour - 1;
	cout << "Mountain Time" << endl;
	return *this;
}
Time2& Time2::timeOfDay()
{
	if (hour >= 3 && hour <= 11)
	{
		cout << "Early Morning" << endl;
	}
	if (hour == 12) {
		cout << "High Noon" << endl;
	}
	if (hour >= 13 && hour <= 19)
	{
		cout << "Afternoon" << endl;
	}
	if (hour >= 20 && hour <= 24 || hour <= 2) {
		cout << "Late Night" << endl;
	}
	return *this;
}
Time2& Time2::printTime() 
{
	switch (hour) {
	case 1:
		hour = 1;
		cout << "AM";
		break;
	case 2:
		hour = 2;
		cout << "AM ";
		break;
	case 3:
		hour = 3;
		cout << "AM ";
		break;
	case 4:
		hour = 4;
		cout << "AM ";
		break;
	case 5:
		hour = 5;
		cout << "AM ";
		break;
	case 6:
		hour = 6;
		cout << "AM ";
		break;
	case 7:
		hour = 7;
		cout << "AM ";
		break;
	case 8:
		hour = 8;
		cout << "AM ";
		break;
	case 9:
		hour = 9;
		cout << "AM ";
		break;
	case 10:
		hour = 10;
		cout << "AM ";
		break;
	case 11:
		hour = 11;
		cout << "AM ";
		break;
	case 12:
		hour = 12;
		cout << "PM ";
		break;
	case 13:
		hour = 1;
		cout << "PM ";
		break;
	case 14:
		hour = 2;
		cout << "PM ";
		break;
	case 15:
		hour = 3;
		cout << "PM "; 
		break;
	case 16:
		hour = 4;
		cout << "PM" ;
		break;
	case 17:
		hour = 5;
		cout << "PM ";
		break;
	case 18:
		hour = 6;
		cout << "PM ";
		break;
	case 19:
		hour = 7;
		cout << "PM ";
		break;
	case 20:
		hour = 8;
		cout << "PM ";
		break;
	case 21:
		hour = 9;
		cout << "PM ";
		break;
	case 22:
		hour = 10;
		cout << "PM ";
		break;
	case 23:
		hour = 11;
		cout << "PM" ;
		break;
	case 24:
		hour = 12;
		cout << "AM ";
		break;
	}
	cout << "|Hours|  |Minutes|  |Seconds|" << endl;
	cout << "\n" << getHour() << "   :   " << getMin() << "   :   " << getSec() << "\n" << endl;
		return *this;
}
