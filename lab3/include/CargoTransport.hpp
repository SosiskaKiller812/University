#pragma once

#include "String.hpp"

class CargoTransport{
private:
	int pricePh;
	int kmPh;
	String name;
public:
	CargoTransport(int price, int speed, String transportName);
	int getKmph() const;
	double getTime(double distance) const;
	double getPrice(double distance) const;
	String getName() const;
};

