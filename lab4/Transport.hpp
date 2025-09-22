#pragma once

#include <string>
#include <string_view>

class Transport{
private:
	double pricePerHuman;
	double pricePerKilo;
	double kmPh;
	std::string name;
public:
	Transport(double pricePh, double pricePk, double speed, std::string_view transportName);
	int getKmph() const;
	virtual double getTime(double distance) const = 0;
	virtual double getPrice(double distance) const = 0;
	std::string getName() const;
};