#include <iostream>

#include "Utilities.hpp"
#include "InputSystem.hpp"
#include "String.hpp"
#include "LinkedList.hpp"

using namespace std;


int getDistance(LinkedList &cities){
	cout << "Enter city or distance" << endl;
	String city;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	input(city);
	if(isInt(city)){
		int distance = myStoi(city);
		return distance;
	}
	auto node = cities.find(city);
	if(node != nullptr){
		return node->data;
	}
	else{
		cout << "City '";
		print(city);
		cout << "' not found\n";
		return 0;
	}
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

