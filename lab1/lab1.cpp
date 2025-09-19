#include <iostream>

#include "Matrix.hpp"
#include "InputSystem.hpp"
#include "menu.hpp"

using namespace std;

int main(){
	cout << "Enter size of matrix:" << endl;
	int columns;
	int rows;
	inputInt(rows, 0);
	inputInt(columns, 0);
	Matrix M(rows, columns);

	while(true){
		system("cls");
		cout << "1 Show matrix" << endl << "2 Set value" << endl << "3 Set all values" << endl << "4 Subtract from element" << endl << "0 Exit" << endl;
		char option;
		cin >> option;
		switch(option){
		case '1':
			cout << "1 Show matrix" << endl;
			M.print();
			system("pause");
			break;
		case '2':
		{
			cout << "2 Set value" << endl;
			setMatrixValue(M, rows, columns);
			break;
		}
		case '3':
			cout << "3 Set all values" << endl;
			M.setValues();
			break;
		case '4':
		{
			cout << "4 subtract from element" << endl;
			subtractMatrixValue(M, rows, columns);
			break;
		}
		case '0':
			return 0;
		default:
			cout << "Incorrect input!" << endl;
			system("pause");
		}
	}
}

