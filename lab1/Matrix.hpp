class Matrix{
private:
	int rows;
	int columns;
	double **matrica = nullptr;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& matrix);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	void setValues() const;
	void setValue(int r, int c, double value) const;
	void print() const;
	void subtractFromElement(int r, int c, double value) const;
};