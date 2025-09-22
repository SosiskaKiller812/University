#include "Car.hpp"

const double AutoSpeed = 100;
const double AutoPricePk = 25;
const double AutoPricePh = 40;

Car::Car() : Transport(AutoPricePh, AutoPricePk, AutoSpeed, "Car"){}