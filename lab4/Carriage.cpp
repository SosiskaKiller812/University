#include <iostream>

#include "Carriage.hpp"
#include "consts.hpp"


Carriage::Carriage() : Transport(carriagePricePh, carriageMaxPeoples, carriagePricePk, carriageMaxKilos, carriageSpeed, carriageName){}

double Carriage::getTime(double distance, int persons, double extraWeight) const{
	if(persons > maxPersons || extraWeight + persons * avgPeopleWeight > maxWeight){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	double fatiguePerKm = 0.05 * (extraWeight + persons * avgPeopleWeight) / maxWeight;
	double fatigueRate = 1.0 + (distance * fatiguePerKm);

	return distance / kmPh * fatigueRate;
}

double Carriage::getPrice(double distance, int persons, double extraWeight) const{
	if(persons > maxPersons || persons * avgPeopleWeight > maxWeight > maxWeight){
		std::cout << "Too much peoples or weight!!";
		return 0.0;
	}

	return pricePerHuman * persons + extraWeight * carriagePricePk + carriageFeePerKm * distance;
}

