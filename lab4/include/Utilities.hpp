#pragma once

#include "String.hpp"
#include "Transport.hpp"

void getTransportTime(const Transport *transport);
void getTransportCost(const Transport *transport);

double getDistance();
int getPersonsAmount(const Transport *transport);
double getExtraWeight(const Transport *transport);

int myStoi(const String &str);

double myStod(const String &str);

int myStrlen(const char *str);

int myStrcmp(const char *str1, const char *str2);