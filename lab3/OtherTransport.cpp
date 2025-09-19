#include "OtherTransport.hpp"

Plane::Plane() : CargoTransport(70, 1000, "Plane"){}

Train::Train() : CargoTransport(30, 80, "Train"){}

Auto::Auto() : CargoTransport(60, 100, "Auto"){}