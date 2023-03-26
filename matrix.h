#pragma once
#include <iostream>
#include <iomanip>

using namespace std;


class Matrix {
	// think about the private data members...
	// the matrix should store real numbers
private:
	int r;
	int c;
	double **matrix;
public:
	//include all the necessary checks before performing the operations in the functions
	Matrix();// a default constructor
	Matrix(int, int);// a parametrized constructor
	Matrix(const Matrix&);// copy constructor
	//int operator[]();//set and get value at (i,j)
	Matrix& operator=(const Matrix&); //assigns matrix on RHS to the one on LHS
	Matrix& operator+(const Matrix&); //add two matrices
	Matrix& operator-(const Matrix&); //subtracts two matrices
	Matrix& operator*(const Matrix&); //dot product of two matrices
	bool operator==(const Matrix&); //checks if two matrices are equal
	Matrix& operator+=(int);//adds an integer to all elements
	Matrix& operator-=(int);//subtracts an integer from all elements
	Matrix& operator*=(int);//multiples an integer to all elements
	Matrix& operator/=(int);//divides all elements by an integer

	Matrix& operator()(int A, int B);//returns a new matrix of size A x B
	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, const Matrix&); //inputs the matrix
	~Matrix();
};



