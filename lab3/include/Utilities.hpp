#pragma once

#include <iostream>

#include "String.hpp"
#include "LinkedList.hpp"
#include "CargoTransport.hpp"


double getDistance(LinkedList &cities);

void addCity(LinkedList &cities);

int myStoi(const String &str);

double myStod(const String &str);

int myStrlen(const char *str);

int myStrcmp(const char *str1, const char *str2);

void freeCargoArray(CargoTransport *transport[], int size);