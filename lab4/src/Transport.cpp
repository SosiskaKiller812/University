#include "Transport.hpp"

#include "String.hpp"

Transport::Transport() : pricePerHuman(0), pricePerKilo(0), maxPersons(0), maxWeight(0), kmPh(0), name(String()){}


Transport::Transport(double pricePh, int maxPeoples, double pricePk, double maxKilos, double speed, String transportName) :
	pricePerHuman(pricePh), pricePerKilo(pricePk), maxPersons(maxPeoples), maxWeight(maxKilos), kmPh(speed), name(transportName){
}

Transport::~Transport(){
	pricePerHuman = 0;
	pricePerKilo = 0;
	maxPersons = 0;
	maxWeight = 0;
	kmPh = 0;
	name = String();
}

double Transport::getKmph() const{ return kmPh; }

String Transport::getName() const{ return name; }

int Transport::getMaxPersons() const{ return maxPersons; }

double Transport::getMaxWeight() const{ return maxWeight; }