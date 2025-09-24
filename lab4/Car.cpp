#include <iostream>

#include "Car.hpp"
#include "consts.hpp"

Car::Car() : Transport(carPricePh, carMaxPeoples, carPricePk, carMaxKilos, carSpeed, carName){}

double Car::getTime(double distance, int persons, double extraWeight) const{
	if(persons > maxPersons || extraWeight + persons * avgPeopleWeight > maxWeight){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return distance / kmPh;
}

double Car::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > maxPersons || persons * avgPeopleWeight > maxWeight){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return pricePerHuman * persons + extraWeight * carPricePk + distance * carFuelCostPk;
}

