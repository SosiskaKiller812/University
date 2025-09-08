#include <iostream>

using namespace std;

class Matrix {
private:
	int rows;
	int columns;
	double** matrica;
public:
	Matrix() {
		rows = 2;
		columns = 2;
		matrica = new double* [rows];
		for (int i = 0; i < rows; i++) {
			matrica[i] = new double[columns];
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrica[i][j] = 0;
			}
		}
	}
	Matrix(int rows, int cols) {
		this->rows = rows;
		columns = cols;
		matrica = new double* [rows];
		for (int i = 0; i < rows; i++) {
			matrica[i] = new double[columns];
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				matrica[i][j] = 0;
			}
		}
	}
	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	void setValues() {
		cout << "Enter values:" << endl;
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < columns;j++) {
				double value;
				cin >> value;
				matrica[i][j] = value;
			}
		}
	}
	void setValue(int r, int c, double value) {
		if (r <= rows && c <= columns) {
			matrica[r][c] = value;
		}
	}
	void print() {
		cout << endl;
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < columns;j++) {
				cout << matrica[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	void subtractFromElement(int r, int c, double value) {
		if (r <= rows && c <= columns) {
			matrica[r][c] -= value;
		}
	}
};



int main()
{
	Matrix M(3, 3);
	M.setValues();
	M.print();
	M.subtractFromElement(2, 1, 0.5);
	M.print();
	return 0;
}

