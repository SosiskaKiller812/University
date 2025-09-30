#include <iostream>
#include <fstream>
#include <string>

#include "consts.hpp"
#include "BusFlight.hpp"
#include "utilities.hpp"

using namespace std;

int main()
{
    int flightsAmount = 0;
    BusFlight* flights = BusFlight::loadAllFlights(kFileName, flightsAmount);


	while(true){
		system("cls");
		cout << "1 Show all flights" << endl << "2 Add flight" << endl << "3 Get all flights by departure time" << endl << "0 Exit" << endl;
		char option;
		cin >> option;
		switch(option){
		case '1':
			showAllFlights(flights, flightsAmount);
			system("pause");
			break;
		case '2':
			cout << "Add flight:" << endl;
			addFlight(flights, flightsAmount);
			break;
		case '3':
			cout << "All flights by departure time" << endl;
			showFlightsByDepartureTime(flights, flightsAmount);
			system("pause");
			break;
		case '0':
			BusFlight::saveAllFlights(kFileName, flights, flightsAmount);
			delete[] flights;
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}

}
