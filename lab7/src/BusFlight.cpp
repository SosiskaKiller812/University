#include <iostream>
#include <fstream>
#include <iomanip>
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

void BusFlight::saveAllFlights(const std::string &filename, BusFlight *flights, const int count){
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

BusFlight::~BusFlight(){
	flightNumber = -1;
	busType = "-1";
	destination = "-1";
	departureTime = Time();
	arrivalTime = Time();
}