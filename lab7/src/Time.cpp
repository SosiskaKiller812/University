#include <iostream>
#include <iomanip>
#include <string>

#include "consts.hpp" 
#include "Time.hpp"
#include <InputSystem.hpp>

std::string createStringTime(const Time &obj){
	std::string time(kTimeStringSize, ' ');

	if(obj.hours < 10){
		time[0] = '0';
		time[1] = obj.hours + '0';
	}
	else{
		time[0] = (obj.hours / 10) + '0';
		time[1] = (obj.hours % 10) + '0';
	}

	time[2] = kTimeDelimiter;

	if(obj.minutes < 10){
		time[3] = '0';
		time[4] = obj.minutes + '0';
	}
	else{
		time[3] = (obj.minutes / 10) + '0';
		time[4] = (obj.minutes % 10) + '0';
	}

	time[5] = kTimeDelimiter;

	if(obj.seconds < 10){
		time[6] = '0';
		time[7] = obj.seconds + '0';
	}
	else{
		time[6] = (obj.seconds / 10) + '0';
		time[7] = (obj.seconds % 10) + '0';
	}

	return time;
}

std::ostream &operator<<(std::ostream &os, const Time &obj){
	os << createStringTime(obj);
	return os;
}

std::istream &operator>>(std::istream &is, Time &time){
	char colon;
	is >> time.hours >> colon >> time.minutes >> colon >> time.seconds;
	return is;
}

Time &Time::operator=(const Time &obj){
	hours = obj.hours;
	minutes = obj.minutes;
	seconds = obj.seconds;
	return *this;
}

bool Time::operator==(const Time &obj) const{
	if(hours == obj.hours){
		if(minutes == obj.minutes){
			if(seconds == obj.seconds) return true;
		}
	}
	return false;
}

Time Time::fillTimeByConsole(){
	std::cout << "Enter hours" << std::endl;
	int hours;
	inputInt(hours, 0, kMaxHours);
	std::cout << "Enter minutes" << std::endl;
	int minutes;
	inputInt(minutes, 0, kMaxMinutes);
	std::cout << "Enter seconds" << std::endl;
	int seconds;
	inputInt(seconds, 0, kMaxSeconds);

	return Time(hours, minutes, seconds);
}

Time::~Time(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}