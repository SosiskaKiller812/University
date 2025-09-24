#pragma once

#include "Transport.hpp"

class Car : public Transport{
public:
	Car();
	double getTime(double distance, int persons, double exraWeight) const override;
	double getPrice(double distance, int persons, double exraWeight) const override;
};