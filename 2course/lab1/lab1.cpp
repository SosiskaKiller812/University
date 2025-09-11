#include <iostream>
#include "Matrix.hpp"
#include "InputSystem.hpp"

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
			cout << "Enter row, column and value to set" << endl;
			int row;
			int column;
			double value;
			inputInt(row, 0, rows-1);
			inputInt(column, 0, columns-1);
			inputDouble(value);
			M.setValue(rows, columns, value);
			break;
		}
		case '3':
			cout << "3 Set all values" << endl;
			M.setValues();
			break;
		case '4':
		{
			cout << "4 subtract from element" << endl;
			cout << "Enter row, column and value to subtract" << endl;
			int row;
			int column;
			double value;
			inputInt(row, 0, rows - 1);
			inputInt(column, 0, columns - 1);
			inputDouble(value);
			M.subtractFromElement(row, column, value);
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

