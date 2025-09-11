class Matrix{
private:
	int rows;
	int columns;
	double **matrica;
public:
	Matrix();
	Matrix(int rows, int cols);
	~Matrix();
	void setValues();
	void setValue(int r, int c, double value);
	void print();
	void subtractFromElement(int r, int c, double value);
};