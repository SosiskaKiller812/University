#include <iostream>

#include "Car.hpp"
#include "consts.hpp"

Car::Car() : Transport(kCarPricePh, kCarMaxPeoples, kCarPricePk, kCarMaxKilos, kCarSpeed, kCarName){}

double Car::getTime(double distance, int persons, double extraWeight) const{
	if(persons > kCarMaxPeoples || extraWeight + persons * kAvgPeopleWeight > kCarMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return distance / kCarSpeed;
}

double Car::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > kCarMaxPeoples || persons * kAvgPeopleWeight > kCarMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return kCarPricePh * persons + extraWeight * kCarPricePk + distance * kCarFuelCostPk;
}

