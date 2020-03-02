#include "Date2.h"
using namespace std;
#include <iostream>;

Date2::Date2(int d, int m, int y)
{
    try {
        setAll(d, m, y);
    }
    catch (const char* e) {
        throw e;
    }
}

Date2::~Date2()
{

}

int Date2::getDay()
{
    return day;
}
int Date2::getMonth()
{
    return month;
}
int Date2::getYear()
{
    return year;
}
int Date2::getDaysInMonth()
{
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    if (month == 1) {
        return 31;
    }
    if (month == 2 && leapAdj == 1) {
        return 29;
    }
    if (month == 2 && leapAdj == 0) {
        return 28;
    }
    if (month == 3) {
        return 31;
    }
    if (month == 4) {
        return 30;
    }
    if (month == 5) {
        return 31;
    }
    if (month == 6) {
        return 30;
    }
    if (month == 7) {
        return 31;
    }
    if (month == 8) {
        return 31;
    }
    if (month == 9) {
        return 30;
    }
    if (month == 10) {
        return 31;
    }
    if (month == 11) {
        return 30;
    }
    if (month == 12) {
        return 31;
    }
}

void Date2::setDay(int d)
{
    /*
    int leapAdj;
    if(year%4 == 0 && month == 2 ){
        leapAdj = 1;
    }else{
        leapAdj = 0;
    }
    The above if else block can be summarized into following code line
    */
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;

    if (d >= 1 && d <= (daysInMonth[month - 1] + leapAdj)) {
        day = d;
    }
    else {
        throw "Wrong day";
    }
}
void Date2::setMonth(int m)
{
    if (m >= 1 && m <= 12) {
        month = m;
    }
    else {
        throw "Wrong month";
    }
}
void Date2::setYear(int y)
{
    year = y;
}

Date2& Date2::setAll(int d, int m, int y)
{
    try {
        setYear(y);
        setMonth(m);
        setDay(d);
        return *this;
    }
    catch (const char* e) {
        throw e;
    }

}

Date2& Date2::setDayPub(int d)
{
    try {
        setYear(year);
        setMonth(month);
        setDay(d);
        return *this;
    }
    catch (const char* e) 
    {
        throw e;
    }
}
Date2& Date2::setMonthPub(int m)
{
    try {
        setYear(year);
        setMonth(m);
        setDay(day);
        return *this;
    }
    catch (const char* e)
    {
        throw e;
    }
}
Date2& Date2::setYearPub(int y)
{
    try {
        setYear(y);
        setMonth(month);
        setDay(day);
        return *this;
    }
    catch (const char* e)
    {
        throw e;
    }
}
bool Date2::operator==(Date2 rhs)
{
    if (day == rhs.getDay() && month == rhs.getMonth() && year == rhs.getYear()) 
    {
        return true;
    }
    else {
        return false;
    }
}
bool Date2::operator!=(Date2 rhs) {
    return !(*this == rhs);
}
Date2& Date2::operator ++()//prefix ++
{
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    day++;
    if (day > daysInMonth[month - 1] + leapAdj)
    {
        month++;
        day = 1;
    }
    if (month > 12) 
    {
        day = 1;
        year++;
        month = 1;
    }
    return*this;
}
Date2& Date2::addYear(int y) {
    ++year;
    if (year % 4 == 0 && month == 2 && day == 29) {
        ++year;
        day = 1;
        month = 3;
    }
    else {
        ++year;
    }
    return *this;
}
Date2& Date2::addMonth(int m) {
    {
        if (month + m > 12) {
            if ((m / 12) >= 1) {
                year = year + (m / 12);
                month = month + (m % 12);
            }
            else {
                year++;
                month = (month + m) - 12;
            }
        }
        else
            month = month + m;
        //
        if (month == 2) {
            if (day >= 29 && year % 4 != 0) {
                day = day - 28;
                month++;
            }
            if (day >= 30 && year % 4 == 0)
                day = day - 29;
            month++;
        }
        if (day == 31) {
            if (month == 4 || month == 6 || month == 9 || month == 11)
                day = day - 30;
            month++;
        }

        return *this;
    }
}

Date2 Date2::operator++(int)//postfix ++
    {
    Date2 tmp = *this;
    ++(*this);
    return tmp;
}
Date2& Date2::operator--()//prefix --hw
{
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    if (month == 1 && day == 1) {
        day = 31;
        month = 12;
        year--;
    }
    else if (day <= 1) {
        month--;
        day = getDaysInMonth(); // created seperate getDaysInMonth function in class       
    }
    else {
        day--;
    }
    return *this;
}
Date2 Date2::operator --(int) //hw postfix
{
    Date2 temp = *this;
    --(*this);
    return temp;
}
int Date2::operator-(Date2 rhs)
{
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    int diffMonth;
    int diffYear;
    int diffDay;

    if (rhs.getDay() > day) {
        diffDay = rhs.getDay() - day;
        day = diffDay;
    }
    else {
        diffDay = day - rhs.getDay();
        day = diffDay;
    }
    if (rhs.getMonth() > month) {

    }
    return diffDay;
}

//Date2& Date2::printDate()
//{
    //cout << monthNames[month - 1] << " " << day << ", " << year << endl;
    //return *this;
//}

Date2& Date2::operator+(unsigned int addDays) // adding days to date
{
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
    day = day + addDays;
    
    if (day < daysInMonth[month - 1] + leapAdj) {
        return *this;
    }
    else {
        while (day > daysInMonth[month - 1] + leapAdj || month > 12) {
            if (month > 12) { 
                month = 1;
                year++;
            }
            else {
                day = day - daysInMonth[month - 1] + leapAdj;
                month++;
                leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
            }
        }
        return *this;
    }
}
Date2& Date2::operator-(unsigned int subDays) 
{ //feb 25, 2020 hw
    int leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
                         //day //sub  //difference
    day = day - subDays; //25 - 36 = -11

    if (day < daysInMonth[month - 1] + leapAdj && day > 0) {
        return *this;
    }
    else {
        while (day <= 0 || month < 1) {
            if (month < 1) {
                month = 12;
                year--;
            } 
            else {
                day = day + daysInMonth[month - 1] + leapAdj; 
                month--;
                leapAdj = (year % 4 == 0 && month == 2) ? 1 : 0;
            }
        }
    }
    return *this;
}
Date2& Date2::operator +=(unsigned int addDays)
{
    *this = *this + addDays;
    return *this;
}
