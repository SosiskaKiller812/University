#include "CargoTransport.hpp"
#include "String.hpp"

CargoTransport::CargoTransport(double price, double speed, String transportName) : PricaPk(price), kmPh(speed), name(transportName){}

double CargoTransport::getKmph() const{
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
		return getTime(distance) * PricaPk;
	}
	return 0;
}

String CargoTransport::getName() const{ return name; }