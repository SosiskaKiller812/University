#include <iostream>
#include <iomanip>
#include <string>

#include "consts.hpp" 
#include "Time.hpp"
#include <InputSystem.hpp>

std::string createStringTime(const Time &obj){
	std::string time;

	if(obj.hours < 10){
		time = '0';
	}
	time += std::to_string(obj.hours);

	time += kTimeDelimiter;

	if(obj.minutes < 10){
		time += '0';
	}
	time += std::to_string(obj.minutes);

	time += kTimeDelimiter;

	if(obj.seconds < 10){
		time += '0';
	}
	time += std::to_string(obj.seconds);

	return time;
}

bool Time::operator==(const Time &obj) const{
	if(hours == obj.hours && minutes == obj.minutes && seconds == obj.seconds) return true;
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
