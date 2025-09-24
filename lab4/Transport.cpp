#include "Transport.hpp"

#include "String.hpp"

Transport::Transport(double pricePh, int maxPeoples, double pricePk, double maxKilos, double speed, String transportName) :
	pricePerHuman(pricePh), pricePerKilo(pricePk), maxPersons(maxPeoples), maxWeight(maxKilos), kmPh(speed), name(transportName){
}

int Transport::getKmph() const{ return kmPh; }

String Transport::getName() const{ return name; }

int Transport::getMaxPersons() const{ return maxPersons; }

int Transport::getMaxWeight() const{ return maxWeight; }