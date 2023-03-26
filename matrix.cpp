#include <iostream>
#include "matrix.h"

using namespace std;

Matrix::Matrix() {
	r = 0;
	c = 0;
	matrix = NULL;
}

Matrix::Matrix(int x, int y) {
	r = x;
	c = y;
	matrix = new double* [r];
	for (int i = 0; i < r; i++)
		matrix[i] = new double[c];
	//int n;
	/*cout << "Would you like to enter Matrix Data?\nPress '0' if yes!\n";
	cin >> n;
	if (n == 0) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				cout << "\nEnter " << i + 1 << j + 1 << ": ";
				cin >> matrix[i][j];
			}
	}*/
}

Matrix::Matrix(const Matrix& M) {
	r = M.r;
	c = M.c;
	matrix = new double* [r];
	for (int i = 0; i < r; i++)
		matrix[i] = new double[c];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			matrix[i][j] = M.matrix[i][j];

}

Matrix& Matrix:: operator=(const Matrix& M) {
	Matrix* ans = new Matrix(M.r, M.c);
	r = M.r;
	c = M.c;
	matrix = new double* [r];
	for (int i = 0; i < r; i++)
		matrix[i] = new double[c];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			matrix[i][j] = M.matrix[i][j];
			ans->matrix[i][j] = M.matrix[i][j];
		}
	return (*ans);
}

Matrix& Matrix :: operator+ (const Matrix& M) {
	Matrix* ans = new Matrix(M.r, M.c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < M.c; ++j)
		{
			ans->matrix[i][j] = matrix[i][j] + M.matrix[i][j];
			//Sleep(300);
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

Matrix& Matrix :: operator- (const Matrix& M) {
	Matrix* ans = new Matrix(M.r, M.c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < M.c; ++j)
		{
			ans->matrix[i][j] = matrix[i][j] - M.matrix[i][j];
			//Sleep(300);
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

Matrix& Matrix :: operator* (const Matrix& M) {
	Matrix* ans = new Matrix(M.r, M.c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < M.c; ++j)
		{
			for (int k = 0; k < M.r; ++k)
			{
				ans->matrix[i][j] = ans->matrix[i][j] + matrix[i][k] * M.matrix[k][j];
			}
			//Sleep(300);
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

bool Matrix:: operator== (const Matrix& M) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (matrix[i][j] != M.matrix[i][j])
				return false;
	return true;
}

Matrix& Matrix :: operator+= (int x) {
	Matrix* ans = new Matrix(r, c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			ans->matrix[i][j] = matrix[i][j] + x;
			//Sleep(300);
			matrix[i][j] = ans->matrix[i][j];
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

Matrix& Matrix :: operator-= (int x) {
	Matrix* ans = new Matrix(r, c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			ans->matrix[i][j] = matrix[i][j] - x;
			//Sleep(300);
			matrix[i][j] = ans->matrix[i][j];
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

Matrix& Matrix :: operator*= (int x) {
	Matrix* ans = new Matrix(r, c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			ans->matrix[i][j] = matrix[i][j] * x;
			//Sleep(300);
			matrix[i][j] = ans->matrix[i][j];
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

Matrix& Matrix :: operator/= (int x) {
	Matrix* ans = new Matrix(r, c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			ans->matrix[i][j] = matrix[i][j] / x;
			//Sleep(300);
			matrix[i][j] = ans->matrix[i][j];
			//cout << setw(5) << ans->matrix[i][j];
		}
		//cout << endl << endl;
	}
	return (*ans);
}

Matrix::~Matrix() {
	for (int i = 0; i < r; i++)
		delete[] matrix[i];
	delete[] matrix;
}

Matrix& Matrix :: operator()(int A, int B) {
	Matrix* ans = new Matrix(A, B);
	for (int i = 0; i < A; i++)
		for (int j = 0; j < B; j++)
			ans->matrix[i][j] = matrix[i][j];
	return (*ans);
}

ostream& operator<<(ostream& out, const Matrix& M) {
	cout << "------------------------------------------\n";
	for (int i = 0; i < M.r; ++i)
	{
		for (int j = 0; j < M.c; ++j)
		{
			//ans->matrix[i][j] = matrix[i][j] + M.matrix[i][j];
			//Sleep(300);
			cout << setw(5) << M.matrix[i][j];
		}
		cout << endl << endl;
	}
	cout << "------------------------------------------\n";
	return out;
}

istream& operator>>(istream& in, const Matrix& M) {
	//int n;
	//cout << "Would you like to enter Matrix Data?\nPress '0' if yes!\n";
	//cin >> n;
	//if (n == 0) {
	cout << "------------------------------------------\n";
		for (int i = 0; i < M.r; i++)
			for (int j = 0; j < M.c; j++) {
				cout << "\nEnter " << i + 1 << j + 1 << ": ";
				in >> M.matrix[i][j];
				cin.ignore();
				cin.clear();
			}
	cout << "------------------------------------------\n";

	//}
	return in;
}
