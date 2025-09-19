#include <string>

#include "CargoTransport.hpp"


int CargoTransport::getKmph() const{
	return kmPh;
}

double CargoTransport::getTime(double distance) const{
	if(distance > 0){
		return distance / kmPh;
	}
	return 0;
}

double CargoTransport::getPrice(double distance) const{
	if(distance > 0){
		return getTime(distance) * pricePh;
	}
	return 0;
}

std::string CargoTransport::getName() const{ return name; }