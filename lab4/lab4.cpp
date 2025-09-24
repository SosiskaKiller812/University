#include <iostream>

#include "Transport.hpp"

#include "Car.hpp"
#include "Bicycle.hpp"
#include "Carriage.hpp"

#include "Utilities.hpp"
#include "InputSystem.hpp"

using namespace std;

int main(){
	Transport* transport[3] = {new Car, new Bicycle, new Carriage};
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
			for(int i = 0; i < 2; i++){
				delete transport[i];
			}
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}
}