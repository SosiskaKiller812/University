#pragma once

#include "String.hpp"

int myStrlen(const char *str);
String chooseString(const String *strings, int stringsAmount);
void operations(const String string1, const String string2);
void addString(String *&array, int &strAmount, int &capacity);