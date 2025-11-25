#include <iostream>

#include "Carriage.hpp"
#include "consts.hpp"


Carriage::Carriage() : Transport(kCarriagePricePh, kCarriageMaxPeoples, kCarriagePricePk, kCarriageMaxKilos, kCarriageSpeed, kCarriageName){}

double Carriage::getTime(double distance, int persons, double extraWeight) const{
	if(persons > kCarriageMaxPeoples || extraWeight + persons * kAvgPeopleWeight > kCarriageMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	double fatiguePerKm = 0.015 * (extraWeight + persons * kAvgPeopleWeight) / kCarriageMaxKilos;
	double fatigueRate = 1.0 + (distance * fatiguePerKm);

	return distance / kCarriageSpeed * fatigueRate;
}

double Carriage::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > kCarriageMaxPeoples || persons * kAvgPeopleWeight > kCarriageMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return kCarriagePricePh * persons + extraWeight * kCarriagePricePk + kCarriageFeePerKm * distance;
}

