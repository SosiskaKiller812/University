#include <iostream>

#include "Carriage.hpp"
#include "consts.hpp"


Carriage::Carriage() : Transport(carriagePricePh, carriageMaxPeoples, carriagePricePk, carriageMaxKilos, carriageSpeed, carriageName){}

double Carriage::getTime(double distance, int persons, double extraWeight) const{
	if(persons > carriageMaxPeoples || extraWeight + persons * avgPeopleWeight > carriageMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	double fatiguePerKm = 0.05 * (extraWeight + persons * avgPeopleWeight) / carriageMaxKilos;
	double fatigueRate = 1.0 + (distance * fatiguePerKm);

	return distance / carriageSpeed * fatigueRate;
}

double Carriage::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > carriageMaxPeoples || persons * avgPeopleWeight > carriageMaxKilos){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return carriagePricePh * persons + extraWeight * carriagePricePk + carriageFeePerKm * distance;
}

