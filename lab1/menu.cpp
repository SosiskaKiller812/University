#include <iostream>

#include "InputSystem.hpp"
#include "menu.hpp"

using namespace std;

void setMatrixValue(Matrix& M, int rows, int columns){
	cout << "Enter row, column and value to set" << endl;
	int row;
	int column;
	double value;
	inputInt(row, 0, rows - 1);
	inputInt(column, 0, columns - 1);
	inputDouble(value);
	M.setValue(row, column, value);
}

void subtractMatrixValue(Matrix& M, int rows, int columns){
	cout << "Enter row, column and value to subtract" << endl;
	int row;
	int column;
	double value;
	inputInt(row, 0, rows - 1);
	inputInt(column, 0, columns - 1);
	inputDouble(value);
	M.subtractFromElement(row, column, value);
}