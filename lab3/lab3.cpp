#include <iostream>

#include "CargoTransport.hpp"
#include "OtherTransport.hpp"
#include "InputSystem.hpp"
#include "Utilities.hpp"
#include "LinkedList.hpp"

using namespace std;

int main(){
	LinkedList cities;
	cities.pushBack("Brest", 344);
	cities.pushBack("Soligorsk", 155);
	cities.pushBack("Gomel", 311);
	cities.pushBack("Svetlogorsk", 217);
	cities.pushBack("Oshmyani", 129);
	cities.pushBack("Moscow", 715);


	Auto car;
	Plane plane;
	Train train;
	CargoTransport cars[3] = {car, plane, train};
	int currentTransport = 0;
	while(true){
		system("cls");
		cout << "Current transport ->";
		print(cars[currentTransport].getName());
		cout << endl << "1 Choose transport" << endl << "2 Time" << endl << "3 Price" << endl << "4 add City" << endl << "5 Show cities" << endl << "0 Exit" << endl;
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
			cout << cars[currentTransport].getTime(getDistance(cities)) << " minutes" << endl;
			system("pause");
			break;
		case '3':
			cout << "3 Price" << endl;
			cout << cars[currentTransport].getPrice(getDistance(cities)) << " $" << endl;
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
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}

}