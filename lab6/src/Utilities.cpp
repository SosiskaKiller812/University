#include <iostream>

#include "Utilities.hpp"
#include "InputSystem.hpp"
#include "String.hpp"
#include "LinkedList.hpp"
#include "CargoTransport.hpp"
#include <DistanceException.hpp>

using namespace std;

void addStartedCities(LinkedList &cities){
	cities.pushBack("Brest", 344);
	cities.pushBack("Soligorsk", 155);
	cities.pushBack("Gomel", 311);
	cities.pushBack("Svetlogorsk", 217);
	cities.pushBack("Oshmyani", 129);
	cities.pushBack("Moscow", 715);
}

void showCurrentTransport(const String name){
	cout << "Current transport ->";
	print(name);
	cout << endl;
}

double getDistance(LinkedList &cities){
	cout << "Enter city or distance" << endl;
	String city;
	try{
		input(city);

		if(isDouble(city)){
			double distance = myStod(city);
			return distance;
		}

		if(auto node = cities.find(city); node != nullptr){
			return node->data;
		}

		throw DistanceException("Expected city or distance");
	}
	catch(DistanceException &exc){
		cout << exc.what() << endl;
		cout << "City '";
		print(city);
		cout << "' not found\n";
	}
	return 0.0;
}

void addCity(LinkedList &cities){
	cout << "Enter city" << endl;
	String city;

	input(city);

	cout << "Enter distance" << endl;
	double distance;

	inputDouble(distance, 0);

	auto node = cities.find(city);
	if(node == nullptr){
		cities.pushBack(city, distance);
	}
	else{
		cout << "This city already exist!" << endl;
	}

}

int myStoi(const String &str){
	int result = 0;
	bool isNegative = false;
	int i = 0;
	int length = str.size();

	if(length == 0) return false;

	if(str[i] == '-'){
		isNegative = true;
		i++;
	}


	for(; i < length; i++){
		char c = str[i];

		if(c < '0' || c > '9') return false;

		int digit = c - '0';

		result = result * 10 + digit;
	}

	return isNegative ? result * (-1) : result;
}

double myStod(const String &str){
	double result = 0.0;
	bool isNegative = false;
	int i = 0;
	int length = str.size();


	if(i < length && str[i] == '-'){
		isNegative = true;
		i++;
	}

	bool alreadyDot = false;
	double decimalPlace = 0.1;

	for(; i < length; i++){
		char c = str[i];

		if(c == '.'){
			if(alreadyDot){
				return 0.0;
			}
			alreadyDot = true;
			continue;
		}

		if(c < '0' || c > '9'){
			break;
		}

		int digit = c - '0';

		if(alreadyDot){
			result += digit * decimalPlace;
			decimalPlace *= 0.1;
		}
		else{
			result = result * 10 + digit;
		}
	}

	return isNegative ? -result : result;
}

int myStrlen(const char *str){
	if(str == nullptr){
		return 0;
	}
	int len = 0;

	for(int ind = 0; str[ind] != '\0'; ind++){
		len++;
	}

	return len;
}

int myStrcmp(const char *str1, const char *str2){
	int i = 0;

	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] != str2[i]){
			return str1[i] - str2[i];
		}
		i++;
	}

	return str1[i] - str2[i];
}

void freeCargoArray(CargoTransport *transport[], int size){
	for(int i = 0; i < size; i++){
		delete transport[i];
		transport[i] = nullptr;
	}
}