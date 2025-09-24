#include <iostream>

#include "Transport.hpp"

#include "Car.hpp"
#include "Bicycle.hpp"
#include "Carriage.hpp"

#include "Utilities.hpp"
#include "InputSystem.hpp"
#include "consts.hpp"

using namespace std;

int main(){
	auto car = new Car;
	auto bicycle = new Bicycle;
	auto carriage = new Carriage;
	Transport* transport[arraysize] = {car, bicycle, carriage};
	int currentTransport = 0;
	while(true){
		system("cls");
		cout << "Current transport ->";
		print(transport[currentTransport]->getName());
		cout << endl;
		cout << "1 Choose transport" << endl << "2 Time" << endl << "3 Price" << endl << "0 Exit" << endl;
		char option;
		cin >> option;
		switch(option){
		case '1':
			cout << "Choose transport:" << endl << "1 Car" << endl << "2 Bicycle" << endl << "3 Carriage" << endl;
			inputInt(currentTransport, 1, 3);
			currentTransport--;
			break;
		case '2':
			cout << "2 Time" << endl;
			getTransportTime(transport[currentTransport]);
			system("pause");
			break;
		case '3':
			cout << "3 Price" << endl;
			getTransportCost(transport[currentTransport]);
			system("pause");
			break;
		case '0':
			for(int i = 0; i < arraysize; i++){
				delete transport[i];
			}
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}
}