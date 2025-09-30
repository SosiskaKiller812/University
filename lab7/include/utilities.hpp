#pragma once

#include <iostream>

#include "BusFlight.hpp"

void buildTableTop();
void buildTableBottom();

BusFlight *getFlightsByDepartureTime(const BusFlight *buses, const int count, Time time);

void showFlightsByDepartureTime(const BusFlight *buses, const int count);

void showAllFlights(const BusFlight *buses, const int busesCount);

BusFlight *createBusFlight();

void addFlight(BusFlight *&buses, int &count);