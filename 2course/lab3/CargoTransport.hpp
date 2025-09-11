#pragma once

#include <string>

class CargoTransport{
protected:
	int pricePh;
	int kmPh;
	std::string name;
public:
	int getKmph() const{
		return kmPh;
	}
	double getTime(double distance) const{
		if(distance > 0){
			return distance / kmPh;
		}
		return 0;
	}
	double getPrice(double distance) const{
		if(distance > 0){
			return getTime(distance) * pricePh;
		}
		return 0;
	}
	std::string getName() const{ return name; }
};

class Plane :public CargoTransport{
public:
	Plane(){
		pricePh = 70;
		kmPh = 1000;
		name = "Plane";
	}
};

class Train :public CargoTransport{
public:
	Train(){
		pricePh = 30;
		kmPh = 80;
		name = "Train";
	}

};

class Auto :public CargoTransport{
public:
	Auto(){
		pricePh = 60;
		kmPh = 100;
		name = "Auto";
	}

};