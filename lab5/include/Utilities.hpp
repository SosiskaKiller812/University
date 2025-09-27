#pragma once

#include <iostream>

#include "Stack.hpp"

template <class T>
T getValue(){
	if(std::cin.fail()){
		std::cin.clear();
	}

	if(std::cin.rdbuf()->in_avail() > 0){
		std::cin.ignore(10000, '\n');
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
		std::cout << "\nError, invalid input. Please try again: " << std::endl;
	}
}

template <class T>
void popIfPossible(Stack<T> &stack){
	if(stack.empty()){
		std::cout << "Stack already empty" << std::endl;
		return;
	}
	std::cout << stack.pop() << std::endl;
}

template <class T>
void popAllElements(Stack<T> &stack){
	if(stack.empty()){
		std::cout << "Stack already empty" << std::endl;
		return;
	}
	std::cout << "All elements from stack:" << std::endl;
	while(!stack.empty()){
		std::cout << stack.pop() << std::endl;
	}
}