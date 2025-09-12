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
		cout << i + 1 << endl;
		print(strings[i]);
	}
	int option;
	do{
		cin >> option;
	}while(option == 0 || option > stringsAmount);
	return strings[option-1];
}

bool operations(const String string1, const String string2){
	cout << "1 <" << endl << "2 >" << endl << "3 !=" << endl << "4 <=" << endl << "5 >=" << endl;
	char option;
	do{
		cin >> option;
	}
	while(option < 49 || option > 53);

	switch(option){
	case '1':
		return string1 < string2;
		break;
	case '2':
		return string1 > string2;
		break;
	case '3':
		return string1 != string2;
		break;
	case '4':
		return string1 <= string2;
		break;
	case '5':
		return string1 >= string2;
	}
}
