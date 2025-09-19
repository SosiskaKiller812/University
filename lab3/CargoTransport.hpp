#pragma once

#include <string>

class CargoTransport{
protected:
	int pricePh;
	int kmPh;
	std::string name;
public:
	int getKmph() const;
	double getTime(double distance) const;
	double getPrice(double distance) const;
	std::string getName() const;
};

