// class3.cpp : This file contains the 'main' function. Program execution begins and ends there..
//
#include "Date2.h"
#include "Time2.h"
#include <iostream>
using namespace std;
using std::string;
#include <string>

int main()
{
    try {
        Date2 myBD(28, 2, 2021);
        Date2 myDay(29, 2, 2020);
        myBD - myDay;
        //(--(--myBD));
        //cout << "day:" <<myBD.getDay() << endl;
        //cout << "month:"<<myBD.getMonth() << endl;
        //out << "year: "<< myBD.getYear() << endl;
        //(h,m,s) 
        cout << "Time Class Information:" << endl;
        cout << "________________________________" << endl;
        
        Time2 test(13, 13, 5);
        Time2 ans(1, 0, 45);
        ans.timeOfDay().printTime();

        

        //myBD.setAll(28, 2, 2021).setAll(30, 3, 2022);
        //myBD.setDayPub(52).setYearPub(2027).setMonthPub(13);
        //cout << myBD.getMonth() << "/"<< myBD.getDay() << "/" << myBD.getYear() << endl;

    }
    catch (const char* e) {
        cerr << e << endl;
    }



}


