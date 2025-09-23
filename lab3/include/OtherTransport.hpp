#pragma once

#include "CargoTransport.hpp"

class Plane :public CargoTransport{
public:
	Plane();
};

class Train :public CargoTransport{
public:
	Train();
};

class Auto :public CargoTransport{
public:
	Auto();
};