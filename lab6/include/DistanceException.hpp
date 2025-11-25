#pragma once
#include <iostream>
#include <exception>
#include <string>


using namespace std;

class DistanceException : public exception{
private:
	string message;
public:
	explicit DistanceException(const string& msg) : message(msg){}

	const char *what() const noexcept override{
		return message.c_str();
	}
};