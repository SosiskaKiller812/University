#pragma once

#include <string>
#include <string_view>

class CargoTransport{
private:
	int pricePh;
	int kmPh;
	std::string name;
public:
	CargoTransport(int price, int speed, std::string_view transportName);
	int getKmph() const;
	double getTime(double distance) const;
	double getPrice(double distance) const;
	std::string getName() const;
};

