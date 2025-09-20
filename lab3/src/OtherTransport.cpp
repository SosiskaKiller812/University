#include "OtherTransport.hpp"
#include "String.hpp"

const int PlaneSpeed = 1000;
const int PlanePrice = 70;

const int TrainSpeed = 80;
const int TrainPrice = 30;

const int AutoSpeed = 100;
const int AutoPrice = 60;

Plane::Plane() : CargoTransport(PlanePrice, PlaneSpeed, String("Plane")){}

Train::Train() : CargoTransport(TrainPrice, TrainSpeed, String("Train")){}

Auto::Auto() : CargoTransport(AutoPrice, AutoSpeed, String("Auto")){}