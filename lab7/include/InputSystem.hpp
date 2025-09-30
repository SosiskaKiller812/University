#pragma once

#include <iostream>
#include <cfloat>   
#include <climits>   

#include <string>

bool isInt(const std::string &str);
void inputInt(int &value, int min = INT_MIN, int max = INT_MAX);

void inputDouble(double &value, double min = DBL_MIN, double max = DBL_MAX);
bool isDouble(const std::string &str);
