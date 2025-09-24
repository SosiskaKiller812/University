#include <cmath>
#include <iostream>

#include "Bicycle.hpp"
#include "consts.hpp"


Bicycle::Bicycle() : Transport(bicyclePricePh, bicycleMaxPeoples, bicyclePricePk, bicycleMaxKilos, bicycleSpeed, bicycleName){}

double Bicycle::getTime(double distance, int persons, double extraWeight) const{
	if(persons > bicycleMaxPeoples || persons * avgPeopleWeight > bicycleMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	double kWeight = sqrt(persons * avgPeopleWeight / (persons * avgPeopleWeight + extraWeight));
	return distance / (bicycleSpeed * kWeight);
}

double Bicycle::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > bicycleMaxPeoples || persons * avgPeopleWeight > bicycleMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}
	return bicyclePricePh * persons + extraWeight * bicyclePricePk;
}

