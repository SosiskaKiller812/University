#include <cmath>
#include <iostream>

#include "Bicycle.hpp"
#include "consts.hpp"


Bicycle::Bicycle() : Transport(kBicyclePricePh, kBicycleMaxPeoples, kBicyclePricePk, kBicycleMaxKilos, kBicycleSpeed, kBicycleName){}

double Bicycle::getTime(double distance, int persons, double extraWeight) const{
	if(persons > kBicycleMaxPeoples || persons * kAvgPeopleWeight > kBicycleMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	double kWeight = sqrt(persons * kAvgPeopleWeight / (persons * kAvgPeopleWeight + extraWeight));
	return distance / (kBicycleSpeed * kWeight);
}

double Bicycle::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > kBicycleMaxPeoples || persons * kAvgPeopleWeight > kBicycleMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}
	return kBicyclePricePh * persons + extraWeight * kBicyclePricePk;
}

