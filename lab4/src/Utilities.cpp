#include <iostream>

#include "Utilities.hpp"
#include "InputSystem.hpp"
#include "String.hpp"
#include "Transport.hpp"
#include "Car.hpp"
#include "Bicycle.hpp"
#include "Carriage.hpp"

using namespace std;

void showCurrentTransport(const String name){
	cout << "Current transport ->";
	print(name);
	cout << endl;
}

void getTransportTime(const Transport *transport){
	double distance = getDistance();
	int persons = getPersonsAmount(transport);
	double extraWeight = getExtraWeight(transport);
	cout << transport->getTime(distance, persons, extraWeight) << " minutes" << endl;
}

void getTransportCost(const Transport *transport){
	double distance = getDistance();
	int persons = getPersonsAmount(transport);
	double extraWeight = getExtraWeight(transport);
	cout << transport->getPrice(distance, persons, extraWeight) << " $" << endl;
}

double getDistance(){
	cout << "Enter distance:" << endl;
	double distance;
	inputDouble(distance, 0);
	return distance;
}

int getPersonsAmount(const Transport *transport){
	cout << "Enter persons amount(max " << transport->getMaxPersons() << "):" << endl;
	int persons;
	inputInt(persons, 1, transport->getMaxPersons());
	return persons;
}

double getExtraWeight(const Transport *transport){
	cout << "Enter extra weight(" << transport->getMaxWeight() << " kg include persons):" << endl;
	double weight;
	inputDouble(weight, 1, transport->getMaxWeight());
	return weight;
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

void freeTransport(Transport *transport[], int size){
	for(int i = 0; i < size; i++){
		delete transport[i];
		transport[i] = nullptr;
	}
}