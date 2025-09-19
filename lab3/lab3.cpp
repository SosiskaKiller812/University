#include <iostream>
#include <string>
#include <unordered_map>

#include "CargoTransport.hpp"
#include "InputSystem.hpp"

using namespace std;

void addCity(unordered_map<string, int, hash<string>, equal_to<>> &map){
	string newCity;
	int cityDistance = 0;
	cout << "Enter city name" << endl;
	cin >> newCity;
	cout << "Enter distance to city" << endl;
	inputInt(cityDistance, 0);
	map[newCity] = cityDistance;
}
int getDistance(unordered_map<string, int, hash<string>, equal_to<>> &map){
	cout << "Enter city or distance" << endl;
	string city;
	cin >> city;
	if(isInt(city)){
		int distance = stoi(city);
		return distance;
	}
	auto it = map.find(city);
	if(it != map.end()){
		return it->second;
	}
	else{
		cout << "City '" << city << "' not found\n";
		return 0;
	}
}

int main(){
	unordered_map<string, int, hash<string>, equal_to<>> cities = {
		{"Brest",344},
		{"Soligorsk",155},
		{"Gomel",311},
		{"Svetlogorsk",217},
		{"Oshmyani",129},
		{"Moscow",715}
	};

	Auto car;
	Plane plane;
	Train train;
	CargoTransport cars[3] = {car, plane, train};
	int currentTransport = 0;
	while(true){
		system("cls");
		cout << "Current transport ->" << cars[currentTransport].getName() << endl;
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
			for(const auto &[city, distance] : cities){
				cout << city << "  -  " << distance << endl;
			}
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