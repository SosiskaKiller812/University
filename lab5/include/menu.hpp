#pragma once

#include <iostream>
#include <string>

#include "Stack.hpp"
#include "Utilities.hpp"
#include "menuText.hpp"


template<typename T>
void mainMenu(){
	Stack<T> stack;

	while(true){
		system("cls");
		showMenuChoice();

		char option;
		std::cin >> option;

		switch(option){
		case '1':
		{
			T value = getValue<T>();
			stack.push(value);
			break;
		}
		case '2':
			popIfPossible(stack);
			system("pause");
			break;
		case '3':
			popAllElements(stack);
			system("pause");
			break;
		case '0':
			return;
		default:
			std::cout << "Invalid input!" << std::endl;
		}
	}
}

void startWorkWithStack(){
	showTypeChoice();

	char option;
	do{
		std::cin >> option;
	}
	while(option < '1' || option > '4');

	if(option == '1'){
		mainMenu<int>();
	}
	else if(option == '2'){
		mainMenu<double>();
	}
	else if(option == '3'){
		mainMenu<char>();
	}
	else if(option == '4'){
		mainMenu<std::string>();
	}
	else{
		std::cout << "Invalid value, try again" << std::endl;
	}
}
