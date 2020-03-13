/*
 * main.cpp
 *
 *  Created on: Feb 24, 2020
 *      Author: tlegenkamidollayev
 */



#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix
class Matrix {
public:
	Matrix() {
		num_rows_ = 0;
		num_cols_ = 0;
	}
	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}
	void Reset(int num_rows, int num_cols) {
		if (num_rows < 0 || num_cols < 0) {
			throw out_of_range("numbers should be >= 0");
		}
		if (num_rows ==0 || num_cols == 0) {
			num_rows=num_cols=0;
		}

		num_rows_ = num_rows;
		num_cols_ = num_cols;
		matrix_.assign(num_rows, vector<int>(num_cols));
	}
	int& At(int row, int col) {
		return matrix_.at(row).at(col);
	}
	int At(int row, int col) const {
		return matrix_.at(row).at(col);
	}
	int GetNumRows() const {
		return num_rows_;
	}
	int GetNumColumns() const {
		return num_cols_;
	}
private:
	int num_rows_;
	int num_cols_;
	vector<vector<int>> matrix_;
};

bool operator==(const Matrix& first, const Matrix& second) {
	if (first.GetNumRows() != second.GetNumRows()) {
		return false;
	}
	if (first.GetNumColumns() != second.GetNumColumns()) {
		return false;
	}

	for (int row=0; row < first.GetNumRows(); ++row) {
		for (int col=0; col < first.GetNumColumns(); ++col) {
			if (first.At(row, col) != second.At(row, col)) {
				return false;
			}
		}
	}

	return true;
}

Matrix operator+(const Matrix& first, const Matrix& second) {
	if (first.GetNumRows() != second.GetNumRows()) {
		throw invalid_argument("Number of rows is not equal");
	}
	if (first.GetNumColumns() != second.GetNumColumns()) {
		throw invalid_argument("Number of columns is not equal");
	}
	Matrix result(first.GetNumRows(), second.GetNumColumns());
	for (int row=0; row < result.GetNumRows(); ++row) {
		for (int col=0; col < result.GetNumColumns(); ++col) {
			result.At(row, col) = first.At(row, col) + second.At(row, col);
		}
	}
	return result;
}
istream& operator>>(istream& in, Matrix& matrix) {
	int num_rows;
	int num_cols;
	in >> num_rows >> num_cols;
	matrix.Reset(num_rows, num_cols);
	for (int row=0; row < num_rows; ++row) {
		for (int col=0; col < num_cols; ++col) {
			in >> matrix.At(row, col);
		}
	}
	return in;
}
ostream& operator<<(ostream& out, const Matrix& matrix) {
	out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int row=0; row < matrix.GetNumRows(); ++row) {
		for (int col=0; col < matrix.GetNumColumns(); ++col) {
			if (col > 0) {
				out << " ";
			}
			out << matrix.At(row, col);
		}
		out << endl;
	}
	return out;
}
int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
