#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#include "BusFlight.hpp"


std::ostream &operator<<(std::ostream &os, const BusFlight &obj){
	os << std::left
		<< "|" << std::setw(15) << obj.flightNumber
		<< "|" << std::setw(15) << obj.busType
		<< "|" << std::setw(15) << obj.destination
		<< "|" << std::setw(15) << obj.departureTime
		<< "|" << std::setw(15) << obj.arrivalTime << "|" << std::endl;
	return os;
}

std::istream &operator>>(std::istream &is, BusFlight &obj){
	char delimiter;
	is >> delimiter;  // Читаем первый '|'
	is >> obj.flightNumber;
	is >> delimiter;  // Читаем '|'
	is >> obj.busType;
	is >> delimiter;  // Читаем '|'
	is >> obj.destination;
	is >> delimiter;  // Читаем '|'
	is >> obj.departureTime;
	is >> delimiter;  // Читаем '|'
	is >> obj.arrivalTime;
	is >> delimiter;  // Читаем последний '|'
	return is;
}

BusFlight *BusFlight::loadAllFlights(const std::string &filename, int &count){
	std::ifstream ifile(filename);
	if(!ifile.is_open()){
		std::cout << "Error with opening file!" << std::endl;
		return nullptr;
	}

	count = 0;
	std::string line;
	while(std::getline(ifile, line)){
		count++;
	}

	if(count == 0){
		ifile.close();
		return nullptr;
	}

	BusFlight *buses = new BusFlight[count];

	ifile.clear();
	ifile.seekg(0);

	for(int i = 0; i < count; i++){
		ifile >> buses[i];
	}

	ifile.close();

	return buses;
}

void BusFlight::saveAllFlights(const std::string &filename, BusFlight* flights, const int count){
	std::ofstream ofile(filename);
	if(!ofile.is_open()){
		std::cout << "Error with opening file!" << std::endl;
		return;
	}

	for(int i = 0; i < count; i++){
		ofile << flights[i];
	}

	ofile.close();
}

BusFlight &BusFlight::operator=(const BusFlight &obj){
	flightNumber = obj.flightNumber;
	busType = obj.busType;
	destination = obj.destination;
	departureTime = obj.departureTime;
	arrivalTime = obj.arrivalTime;
	return *this;
}