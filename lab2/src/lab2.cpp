#include <iostream>

#include "String.hpp"
#include "Utilities.hpp"
#include "menu.hpp"

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
			showAllStrings(strings, stringsAmount);
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
			operationsWithStrings(strings, stringsAmount);
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

