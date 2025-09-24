#pragma once

#include "String.hpp"

class Transport{
private:
	double pricePerHuman;
	double pricePerKilo;
	int maxPersons;
	double maxWeight;
	double kmPh;
	String name;
protected:
	Transport();
	explicit Transport(double pricePh, int maxPeoples, double pricePk, double maxKilos, double speed, String transportName);
public:
	virtual ~Transport();
	Transport(const Transport &other);
	Transport(Transport &&other);
	Transport& operator=(const Transport &other);
	double getKmph() const;
	int getMaxPersons() const;
	double getMaxWeight() const;
	String getName() const;
	virtual double getTime(double distance, int persons, double exraWeight) const = 0;
	virtual double getPrice(double distance, int persons, double exraWeight) const = 0;
};