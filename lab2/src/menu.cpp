#include "String.hpp"
#include "menu.hpp"
#include "Utilities.hpp"

#include "iostream"

using namespace std;

void showAllStrings(String*& strings, int stringsAmount){
	for(int i = 0; i < stringsAmount; i++){
		print(strings[i]);
		std::cout << endl;
	}
}

void operationsWithStrings(String *&strings, int stringsAmount){
	std::cout << "Choose first string:" << endl;
	String first = chooseString(strings, stringsAmount);
	std::system("cls");
	std::cout << "Choose second string:" << endl;
	String second = chooseString(strings, stringsAmount);
	std::system("cls");
	operations(first, second);
}
