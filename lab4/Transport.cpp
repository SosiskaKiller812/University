#include <string>
#include <string_view>

#include "Transport.hpp"


Transport::Transport(double pricePh, double pricePk, double speed, std::string_view transportName) :
	pricePerHuman(pricePh), pricePerKilo(pricePk), kmPh(speed), name(transportName){}

int Transport::getKmph() const{ return kmPh; }

std::string Transport::getName() const{ return name; }