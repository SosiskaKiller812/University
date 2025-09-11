#include "InputSystem.hpp"

bool isNumber(const string &str){
	if(str.empty()) return false;

	int start = 0;
	if(str[0] == '-'){
		if(str.length() == 1) return false;
		start = 1;
	}

	for(int i = start; i < str.length(); i++){
		if(!isdigit(str[i])){
			return false;
		}
	}
	return true;
}

void inputInt(int &value, int min, int max){
	string inputInt;
	while(1){
		cin >> inputInt;
		if(isNumber(inputInt)){
			int temp = stoi(inputInt);
			if(temp >= min && temp <= max){
				(value) = temp;
				return;
			}
		}
		cout << "Incorrect input!" << endl << "Try again:" << endl;
	}
}