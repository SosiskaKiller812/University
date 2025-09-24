#pragma once

#include "Transport.hpp"

class Bicycle : public Transport{
public:
	Bicycle();
	double getTime(double distance, int persons, double exraWeight) const;
	double getPrice(double distance, int persons, double exraWeight) const;
};