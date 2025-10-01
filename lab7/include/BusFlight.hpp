#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "Time.hpp"

class BusFlight{
private:
	int flightNumber;
	std::string busType;
	std::string destination;
	Time departureTime;
	Time arrivalTime;
public:
	BusFlight(int flightNum, const std::string &busT, const std::string &dest, const Time &departureT, const Time &arrivalT)
		: flightNumber(flightNum), busType(busT), destination(dest), departureTime(departureT), arrivalTime(arrivalT){
	};
	BusFlight() : flightNumber(0){};

	friend std::istream &operator>>(std::istream &is, BusFlight &obj){
		char delimiter;
		is >> delimiter;
		is >> obj.flightNumber;
		is >> delimiter;
		is >> obj.busType;
		is >> delimiter;
		is >> obj.destination;
		is >> delimiter;
		is >> obj.departureTime;
		is >> delimiter;
		is >> obj.arrivalTime;
		is >> delimiter;
		return is;
	}
	friend std::ostream &operator<<(std::ostream &os, const BusFlight &obj){
		os << std::left
			<< "|" << std::setw(15) << obj.flightNumber
			<< "|" << std::setw(15) << obj.busType
			<< "|" << std::setw(15) << obj.destination
			<< "|" << std::setw(15) << obj.departureTime
			<< "|" << std::setw(15) << obj.arrivalTime << "|" << std::endl;
		return os;
	}

	BusFlight &operator=(const BusFlight &obj) = default;
	BusFlight(const BusFlight &other) = default;
	~BusFlight() = default;


	static BusFlight *loadAllFlights(const std::string &filename, int &count);
	static void saveAllFlights(const std::string &filename, const BusFlight *flights, int count);

	Time getDepartureTime() const{ return departureTime; };
};

