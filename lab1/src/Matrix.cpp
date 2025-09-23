#include "Matrix.hpp"
#include "InputSystem.hpp"

const int startSize = 2;

using namespace std;

Matrix::Matrix() : rows(startSize), columns(startSize){
	matrix = new double *[rows];
	for(int i = 0; i < rows; i++){
		matrix[i] = new double[columns];
		for(int j = 0; j < columns; j++){
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int r, int c) : rows(r), columns(c){
	matrix = new double *[rows];
	for(int i = 0; i < rows; i++){
		matrix[i] = new double[columns];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns){
	matrix = new double *[rows];
	for(int i = 0; i < other.rows; i++){
		matrix[i] = new double[columns];
		for(int j = 0; j < other.columns; j++){
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

Matrix::~Matrix(){
	for(int i = 0; i < rows; i++){
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix &Matrix::operator=(const Matrix &other){
	for(int i = 0; i < rows; i++){
		delete[] matrix[i];
	}
	delete[] matrix;
	rows = other.rows;
	columns = other.columns;
	matrix = new double *[rows];
	for(int i = 0; i < other.rows; i++){
		matrix[i] = new double[columns];
		for(int j = 0; j < other.columns; j++){
			matrix[i][j] = other.matrix[i][j];
		}
	}
	return *this;
}

void Matrix::setValues() const{
	cout << "Enter values:" << endl;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			double value;
			inputDouble(value);
			matrix[i][j] = value;
		}
	}
}
void Matrix::setValue(int r, int c, double value) const{
	if(r >= rows || r < 0 || c >= columns || c < 0) return;
	matrix[r][c] = value;
}

void Matrix::print() const{
	cout << endl;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::subtractFromElement(int r, int c, double value) const{
	if(r >= rows || r < 0 || c >= columns || c < 0) return;
	matrix[r][c] -= value;
}
