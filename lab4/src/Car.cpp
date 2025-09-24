#include <iostream>

#include "Car.hpp"
#include "consts.hpp"

Car::Car() : Transport(carPricePh, carMaxPeoples, carPricePk, carMaxKilos, carSpeed, carName){}

double Car::getTime(double distance, int persons, double extraWeight) const{
	if(persons > carMaxPeoples || extraWeight + persons * avgPeopleWeight > carMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return distance / carSpeed;
}

double Car::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > carMaxPeoples || persons * avgPeopleWeight > carMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return carPricePh * persons + extraWeight * carPricePk + distance * carFuelCostPk;
}

