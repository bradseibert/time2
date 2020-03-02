#pragma once
class Time2
{
public:
	Time2(int, int, int);
	~Time2();
	int getHour();
	int getMin();
	int getSec();
	Time2& setAll(int, int, int);  //changing variables by reffrence identical to constructor
	Time2& addHour(int);
	Time2& addMin(int);
	Time2& addSec(int);
	Time2& subHour(int);
	Time2& subMin(int);
	bool operator == (Time2);
	bool operator != (Time2);
	Time2& operator ++(); //pre-fix ++ (hour)
	Time2& operator --(); //prefix -- (hour)
	Time2 operator --(int);
	Time2& diff(Time2); //difference between the 2 times
	Time2& printTime();
	Time2& timeOfDay();
	Time2& estTime();
	Time2& pstTime();
	Time2& MNTime();
	
	
	

protected:

private:

	int hour;
	int minute;
	int second;
	void setHour(int);
	void setMin(int);
	void setSec(int);
	

};
