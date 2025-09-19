#include "Utilities.hpp"
#include "InputSystem.hpp"

#include <unordered_map>
#include <string>
#include <iostream>
#include <string_view>

using namespace std;


size_t StringHash::operator()(const string &s) const{
	return hash<string>{}(s);
}

size_t StringHash::operator()(const char *s) const{
	return hash<string_view>{}(s);
}

int getDistance(unordered_map<string, int, StringHash, equal_to<>> &map){
	cout << "Enter city or distance" << endl;
	string city;
	cin >> city;
	if(isInt(city)){
		int distance = stoi(city);
		return distance;
	}
	auto it = map.find(city);
	if(it != map.end()){
		return it->second;
	}
	else{
		cout << "City '" << city << "' not found\n";
		return 0;
	}
}

void addCity(unordered_map<string, int, StringHash, equal_to<>> &map){
	string newCity;
	int cityDistance = 0;
	cout << "Enter city name" << endl;
	cin >> newCity;
	cout << "Enter distance to city" << endl;
	inputInt(cityDistance, 0);
	map[newCity] = cityDistance;
}
