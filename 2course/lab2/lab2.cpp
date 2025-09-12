#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "String.hpp"
#include "Utilities.hpp"

using namespace std;

void addString(String*& array, int& strAmount, int& capacity){
	String newString;
	input(newString);

	if(strAmount >= capacity){
		capacity += 10;
		String *newArray = new String[capacity];
		for(int i = 0; i < strAmount; i++){
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}

	array[strAmount] = newString;
	strAmount++;
}


int main(){
	int stringsAmount = 0;
	int stringsCapacity = 10;
	String* strings = new String[stringsCapacity];

	while(true){
		system("cls");
		cout << "1 Show all strings" << endl << "2 Add string" << endl << "3 Choose operation with strings" << endl << "0 Exit" << endl;
		char option;
		cin >> option;
		switch(option){
		case '1':
			cout << "1 Show all strings" << endl;
			for(int i = 0; i < stringsAmount; i++){
				print(strings[i]);
			}
			system("pause");
			break;
		case '2':
		{
			cout << "2 Add string" << endl;
			addString(strings, stringsAmount, stringsCapacity);
			break;
		}
		case '3':
			cout << "3 Choose operation with strings" << endl;
			operations(chooseString(strings, stringsAmount), chooseString(strings, stringsAmount));
			break;
		case '0':
			delete[] strings;
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}
}

