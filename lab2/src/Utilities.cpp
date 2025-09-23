#include <iostream>

#include "Utilities.hpp"

using namespace std;

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

String chooseString(const String *strings, int stringsAmount){
	for(int i = 0; i < stringsAmount; i++){
		cout << i + 1 << " ";
		print(strings[i]);
		cout << endl;
	}
	int option;
	do{
		cin >> option;
	}while(option == 0 || option > stringsAmount);
	return strings[option-1];
}

void operations(const String string1, const String string2){
	cout << "1 <" << endl << "2 >" << endl << "3 !=" << endl << "4 <=" << endl << "5 >=" << endl;
	char option;
	do{
		cin >> option;
	}
	while(option < 49 || option > 53);

	print(string1);
	
	bool result{};
	switch(option){
	case '1':
		cout << " < ";
		result = string1 < string2;
		break;
	case '2':
		cout << " > ";
		result = string1 > string2;
		break;
	case '3':
		cout << " != ";
		result = string1 != string2;
		break;
	case '4':
		cout << " <= ";
		result = string1 <= string2;
		break;
	case '5':
		cout << " >= ";
		result = string1 >= string2;
		break;
	default:
		cout << "Something get wrong" << endl;
		return;
	}
	
	print(string2);
	cout << endl << boolalpha << result << endl;
}

void addString(String *&array, int &strAmount, int &capacity){
	String newString;
	input(newString);

	if(strAmount >= capacity){
		capacity += 10;
		auto *newArray = new String[capacity];
		for(int i = 0; i < strAmount; i++){
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}

	array[strAmount] = newString;
	strAmount++;
}
