#pragma once

#include <iostream>

#include "Stack.hpp"

using namespace std;

template <class T>
T getValue(){
	if(cin.fail()){
		cin.clear();
	}

	if(cin.rdbuf()->in_avail() > 0){
		cin.ignore(10000, '\n');
	}

	T value;
	int sym = 0;

	while(true){
		if(std::cin.peek() != '\n' && std::cin.peek() != ' ' && (std::cin >> value).good()){
			sym = std::cin.peek();
			if((char) sym == '\n' || (char) sym == EOF){
				std::cin.get();
				return value;
			}
		}

		std::cin.clear();
		while(std::cin.get() != '\n' && !std::cin.eof());
		std::cout << "\nError, invalid input. Please try again: " << endl;
	}
}

template <class T>
void popIfPossible(Stack<T> &stack){
	if(stack.empty()){
		cout << "Stack already empty" << endl;
		return;
	}
	cout << stack.pop() << endl;
}

template <class T>
void popAllElements(Stack<T> &stack){
	if(stack.empty()){
		cout << "Stack already empty" << endl;
		return;
	}
	cout << "All elements from stack:" << endl;
	while(!stack.empty()){
		cout << stack.pop() << endl;
	}
}