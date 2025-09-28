#include "InputSystem.hpp"
#include "String.hpp"
#include "Utilities.hpp"

using namespace std;

bool isInt(const String &str){
	if(str.size() <= 0) return false;

	int start = 0;
	if(str[0] == '-'){
		if(str.size() == 1) return false;
		start = 1;
	}

	for(int i = start; i < str.size(); i++){
		if(!isdigit(str[i])){
			return false;
		}
	}
	return true;
}

void inputInt(int &value, int min, int max){
	String inputInt;
	while(true){
		try{
			input(inputInt);
			if(isInt(inputInt)){
				int temp = myStoi(inputInt);
				if(temp >= min && temp <= max){
					value = temp;
					return;
				}
				else{
					throw out_of_range("Value out of range!");
				}
			}
			throw invalid_argument("Expected int");
		}
		catch(const out_of_range &exc){
			cout << exc.what() << endl;
			cout << "Expected value between (min:" << min << ", max:" << max << ")" << endl;
		}
		catch(const invalid_argument &e){
			cout << "Error: " << e.what() << endl;
			cout << "Try again:" << endl;
		}

	}
}

bool isDouble(const String &str){
	if(str.size() <= 0) return false;
	bool haveDot = false;

	int start = 0;
	if(str[0] == '-'){
		if(str.size() == 1) return false;
		start = 1;
	}

	for(int i = start; i < str.size(); i++){
		if(!isdigit(str[i]) && str[i] != '.'){
			return false;
		}
		if(str[i] == '.'){
			if(haveDot) return false;
			else haveDot = true;
		}
	}
	return true;
}

void inputDouble(double &value, double min, double max){
	String inputDouble;
	while(true){
		input(inputDouble);
		if(isDouble(inputDouble)){
			double temp = myStod(inputDouble);
			if(temp >= min && temp <= max){
				value = temp;
				return;
			}
		}
		cout << "Incorrect input!" << endl << "Try again:" << endl;
	}
}