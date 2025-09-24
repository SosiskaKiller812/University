#pragma once

#include "String.hpp"

class Transport{
protected:
	double pricePerHuman;
	double pricePerKilo;
	int maxPersons;
	double maxWeight;
	double kmPh;
	String name;
public:
	Transport(double pricePh, int maxPeoples, double pricePk, double maxKilos, double speed, String transportName);
	int getKmph() const;
	int getMaxPersons() const;
	int getMaxWeight() const;
	String getName() const;
	virtual double getTime(double distance, int persons, double exraWeight) const = 0;
	virtual double getPrice(double distance, int persons, double exraWeight) const = 0;
};