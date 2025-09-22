#include <iostream>

#include "Utilities.hpp"
#include "String.hpp"

using namespace std;

String::String() : length(0), string(new char[1]{'\0'}){}
String::String(const String &other) : length(other.length), string(new char[length + 1]){
	for(int i = 0; i < length; i++){
		string[i] = other.string[i];
	}
	string[length] = '\0';
}
String::String(const char *s) : length(myStrlen(s)), string(new char[length + 1]){
	for(int i = 0; i < length; i++){
		string[i] = s[i];
	}
	string[length] = '\0';
}

int String::size() const{
	return length;
}

bool String::operator!=(const String &other) const{
	if(length != other.length) return true;
	for(int i = 0; i < length; i++){
		if(string[i] != other.string[i]) return true;
	}
	return false;
}

std::strong_ordering String::operator<=>(const String &other) const{
	return strcmp(string, other.string) <=> 0;
}

String &String::operator=(const String &other){
	if(this == &other){
		return *this;
	}
	delete[] string;

	length = other.length;
	string = new char[length + 1];

	for(int i = 0; i < length; i++){
		string[i] = other.string[i];
	}
	string[length] = '\0';

	return *this;
}

bool String::operator==(const String &other) const{
	return strcmp(string, other.string) == 0;
}

const char &String::operator[](int index) const{
	return string[index];
}

String::~String(){
	delete[] string;
}

void print(const String &string){
	cout << string.string;
}
void input(String &string){
	if(cin.fail()){
		cin.clear();
	}

	if(cin.rdbuf()->in_avail() > 0){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	char ch;
	int length = 0;
	int capacity = 10;
	auto result = new char[capacity];

	while(cin.get(ch) && ch != '\n'){
		if(length + 1 >= capacity){
			capacity *= 2;
			auto newBuffer = new char[capacity];
			for(int i = 0; i < length; i++){
				newBuffer[i] = result[i];
			}
			delete[] result;
			result = newBuffer;
		}
		result[length++] = ch;
	}
	result[length] = '\0';

	delete[] string.string;
	string.length = length;
	string.string = new char[length + 1];
	for(int i = 0; i < length; i++){
		string.string[i] = result[i];
	}
	string.string[length] = '\0';

	delete[] result;
}

