#pragma once

#include "String.hpp"

class CargoTransport{
private:
	double PricaPk;
	double kmPh;
	String name;
public:
	CargoTransport(double price, double speed, String transportName);
	double getKmph() const;
	double getTime(double distance) const;
	double getPrice(double distance) const;
	String getName() const;
};

