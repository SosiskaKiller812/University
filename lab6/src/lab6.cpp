#include <iostream>

#include "CargoTransport.hpp"
#include "Plane.hpp"
#include "Train.hpp"
#include "Auto.hpp"
#include "InputSystem.hpp"
#include "Utilities.hpp"
#include "LinkedList.hpp"
#include "consts.hpp"

using namespace std;

int main(){
	LinkedList cities;
	addStartedCities(cities);

	auto car = new Auto;
	auto plane = new Plane;
	auto train = new Train;
	CargoTransport* transports[kArraySize] = {car, plane, train};
	int currentTransport = 0;
	while(true){
		system("cls");
		showCurrentTransport(transports[currentTransport]->getName());
		cout << "1 Choose transport" << endl << "2 Time" << endl << "3 Price" << endl << "4 add City" << endl << "5 Show cities" << endl << "0 Exit" << endl;
		char option;
		cin >> option;
		switch(option){
		case '1':
			cout << "Choose transport:" << endl << "1 Car" << endl << "2 Plane" << endl << "3 Train" << endl;
			inputInt(currentTransport, 1, 3);
			currentTransport--;
			break;
		case '2':
			cout << "2 Time" << endl;
			cout << transports[currentTransport]->getTime(getDistance(cities)) << " minutes" << endl;
			system("pause");
			break;
		case '3':
			cout << "3 Price" << endl;
			cout << transports[currentTransport]->getPrice(getDistance(cities)) << " $" << endl;
			system("pause");
			break;
		case '4':
			cout << "4 add City" << endl;
			addCity(cities);
			break;
		case '5':
			cout << "City\t" << "Distance" << endl;
			cities.print();
			system("pause");
			break;
		case '0':
			freeCargoArray(transports, kArraySize);
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}
}