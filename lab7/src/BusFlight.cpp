#include <iostream>
#include <fstream>
#include <string>

#include "BusFlight.hpp"
#include "Time.hpp"

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

	auto buses = new BusFlight[count];

	ifile.clear();
	ifile.seekg(0);

	for(int i = 0; i < count; i++){
		ifile >> buses[i];
	}

	ifile.close();

	return buses;
}

void BusFlight::saveAllFlights(const std::string &filename, const BusFlight *flights, int count){
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

BusFlight &BusFlight::operator=(const BusFlight &obj) = default;

BusFlight::BusFlight(const BusFlight &other)
	: flightNumber(other.flightNumber),
	busType(other.busType),
	destination(other.destination),
	departureTime(other.departureTime),
	arrivalTime(other.arrivalTime){
}

BusFlight::~BusFlight(){
	flightNumber = -1;
	busType = "-1";
	destination = "-1";
	departureTime = Time();
	arrivalTime = Time();
}