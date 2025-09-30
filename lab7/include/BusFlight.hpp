#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Time.hpp"

class BusFlight{
private:
	int flightNumber;
	std::string busType;
	std::string destination;
	Time departureTime;
	Time arrivalTime;
public:
	BusFlight(int flightNum, std::string busT, std::string dest, Time departureT, Time arrivalT)
		: flightNumber(flightNum), busType(busT), destination(dest), departureTime(departureT), arrivalTime(arrivalT){};
	BusFlight() : flightNumber(0), departureTime(Time()), arrivalTime(Time()){};

	friend std::istream &operator>>(std::istream &is, BusFlight &obj);
	friend std::ostream &operator<<(std::ostream &os, const BusFlight &obj);
	BusFlight& operator=(const BusFlight &obj);

	static BusFlight *loadAllFlights(const std::string &filename, int &count);
	static BusFlight *saveAllFlights(const std::string &filename, BusFlight* flights, const int count);

	Time getDepartureTime() const{ return departureTime; };
};

//сделать оператор присваивания