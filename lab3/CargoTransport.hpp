#pragma once

#include <string>

class CargoTransport{
private:
	int pricePh;
	int kmPh;
	std::string name;
public:
	CargoTransport(int price, int speed, const std::string &transportName);
	int getKmph() const;
	double getTime(double distance) const;
	double getPrice(double distance) const;
	std::string getName() const;
};

