#include "Bicycle.hpp"

const double BicycleSpeed = 22;
const double BicyclePricePk = 100;
const double BicyclePricePh = 100;

Bicycle::Bicycle() : Transport(BicyclePricePh, BicyclePricePk, BicycleSpeed, "Bicycle"){}