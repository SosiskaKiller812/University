#pragma once

#include <fstream>
#include <iostream>


class Time{
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time() : hours(0), minutes(0), seconds(0){};
	Time(int h, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s){};
	Time &operator=(const Time &obj);
	bool operator==(const Time &obj) const;
	friend std::istream &operator>>(std::istream &is, Time &obj);
	friend std::ostream &operator<<(std::ostream &os, const Time &obj);
	friend std::string createStringTime(const Time &obj);
	static Time fillTimeByConsole();
};
