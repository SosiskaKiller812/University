#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "String.hpp"
#include "Utilities.hpp"

using namespace std;

int main(){
	int stringsAmount = 0;
	int stringsCapacity = 7;
	auto *strings = new String[stringsCapacity];
	strings[stringsAmount++] = String("Hello");
	strings[stringsAmount++] = String("Hello");
	strings[stringsAmount++] = String("world");

	while(true){
		system("cls");
		cout << "1 Show all strings" << endl << "2 Add string" << endl << "3 Choose operation with strings" << endl << "0 Exit" << endl;
		char option;
		cin >> option;
		switch(option){
		case '1':
			system("cls");
			cout << "1 Show all strings" << endl;
			for(int i = 0; i < stringsAmount; i++){
				print(strings[i]);
				cout << endl;
			}
			system("pause");
			break;
		case '2':
		{
			system("cls");
			cout << "2 Add string" << endl;
			addString(strings, stringsAmount, stringsCapacity);
			break;
		}
		case '3':
		{
			system("cls");
			cout << "Choose first string:" << endl;
			String first = chooseString(strings, stringsAmount);
			system("cls");
			cout << "Choose second string:" << endl;
			String second = chooseString(strings, stringsAmount);
			system("cls");
			operations(first, second);
			system("pause");
			break;
		}
		case '0':
			delete[] strings;
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}
}

