#include "Matrix.hpp"

#include "InputSystem.hpp"

using namespace std;

Matrix::Matrix() : rows(2), columns(2){
	matrica = new double *[rows];
	for(int i = 0; i < rows; i++){
		matrica[i] = new double[columns];
		for(int j = 0; j < columns; j++){
			matrica[i][j] = 0;
		}
	}
}
Matrix::Matrix(int r, int c) : rows(r), columns(c){
	matrica = new double *[rows];
	for(int i = 0; i < rows; i++){
		matrica[i] = new double[columns];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			matrica[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns){
	matrica = new double *[rows];
	for(int i = 0; i < other.rows; i++){
		matrica[i] = new double[columns];
		for(int j = 0; j < other.columns; j++){
			matrica[i][j] = other.matrica[i][j];
		}
	}
}
Matrix::~Matrix(){
	for(int i = 0; i < rows; i++){
		delete[] matrica[i];
	}
	delete[] matrica;
}
Matrix &Matrix::operator=(const Matrix &other){
	for(int i = 0; i < rows; i++){
		delete[] matrica[i];
	}
	delete[] matrica;
	rows = other.rows;
	columns = other.columns;
	matrica = new double *[rows];
	for(int i = 0; i < other.rows; i++){
		matrica[i] = new double[columns];
		for(int j = 0; j < other.columns; j++){
			matrica[i][j] = other.matrica[i][j];
		}
	}
	return *this;
}
void Matrix::setValues(){
	cout << "Enter values:" << endl;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			double value;
			inputDouble(value);
			matrica[i][j] = value;
		}
	}
}
void Matrix::setValue(int r, int c, double value){
	if(r >= rows || r < 0 || c >= columns || c < 0) return;
	if(r <= rows && c <= columns){
		matrica[r][c] = value;
	}
}
void Matrix::print() const{
	cout << endl;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			cout << matrica[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void Matrix::subtractFromElement(int r, int c, double value){
	if(r >= rows || r < 0 || c >= columns || c < 0) return;
	matrica[r][c] -= value;
}
