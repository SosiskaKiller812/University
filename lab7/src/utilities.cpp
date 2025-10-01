#include "utilities.hpp"
#include "InputSystem.hpp"

#include <string>
#include <iomanip> 

void buildTableTop(){
	std::cout
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-') << "+" << std::endl;
	std::cout << std::left
		<< "|" << std::setw(15) << "Flight"
		<< "|" << std::setw(15) << "Bus"
		<< "|" << std::setw(15) << "Destination"
		<< "|" << std::setw(15) << "Departure"
		<< "|" << std::setw(15) << "Arrival" << "|"
		<< std::endl;
	std::cout << std::left
		<< "|" << std::setw(15) << "number"
		<< "|" << std::setw(15) << "type"
		<< "|" << std::setw(15) << ""
		<< "|" << std::setw(15) << "time"
		<< "|" << std::setw(15) << "time" << "|"
		<< std::endl;
	std::cout
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-') << "+" << std::endl;
}

void buildTableBottom(){
	std::cout
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-')
		<< "+" << std::string(15, '-') << "+" << std::endl;
}

void showAllFlights(const BusFlight *buses, const int busesCount){
	system("cls");
	std::cout << std::internal << std::setw(45) << "All flights" << std::endl;
	buildTableTop();

	for(int i = 0; i < busesCount; i++){
		std::cout << buses[i];
	}

	buildTableBottom();
}

BusFlight *createBusFlight(){
	int flightNumber;
	std::string busType;
	std::string destination;
	Time departureTime;
	Time arrivalTime;

	system("cls");
	std::cout << "Enter flight number:" << std::endl;
	inputInt(flightNumber);

	std::cout << "Enter bus type:" << std::endl;
	std::cin >> busType;

	std::cout << "Enter destination:" << std::endl;
	std::cin >> destination;

	std::cout << "Enter departure time:" << std::endl;
	departureTime = Time::fillTimeByConsole();

	std::cout << "Enter arrival time:" << std::endl;
	arrivalTime = Time::fillTimeByConsole();

	auto newFlight = new BusFlight(flightNumber, busType, destination, departureTime, arrivalTime);
	return newFlight;
}

void addFlight(BusFlight *&buses, int &count){
	auto newFlight = createBusFlight();

	BusFlight *newBuses = new BusFlight[count + 1];

	for(int i = 0; i < count; i++){
		newBuses[i] = buses[i];
	}

	newBuses[count] = *newFlight;
	delete newFlight;

	delete[] buses;
	buses = newBuses;
	count++;
}

BusFlight *getFlightsByDepartureTime(const BusFlight *buses, const int count, Time time, int &newSize){
	if(buses == nullptr || count <= 0)
		return nullptr;

	int resultSize = 0;
	for(int i = 0; i < count; i++){
		if(buses[i].getDepartureTime() == time){
			resultSize++;
		}
	}

	if(resultSize == 0)
		return nullptr;

	BusFlight *result = new BusFlight[resultSize];
	int index = 0;
	for(int i = 0; i < count; i++){
		if(buses[i].getDepartureTime() == time){
			result[index] = buses[i];
			index++;
		}
	}

	newSize = resultSize;
	return result;
}

void showFlightsByDepartureTime(const BusFlight *buses, const int count){
	Time time = Time::fillTimeByConsole();
	system("cls");
	int newSize = 0;
	BusFlight * flights = getFlightsByDepartureTime(buses, count, time, newSize);
	std::cout << std::internal << std::setw(45) << "All flights at " << time << std::endl;
	buildTableTop();

	for(int i = 0; i < newSize; i++){
		std::cout << flights[i];
	}

	buildTableBottom();
}