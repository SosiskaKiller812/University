#pragma once

#include "Transport.hpp"

class Carriage : public Transport{
public:
	Carriage();
	double getTime(double distance, int persons, double exraWeight) const override;
	double getPrice(double distance, int persons, double exraWeight) const override;
};