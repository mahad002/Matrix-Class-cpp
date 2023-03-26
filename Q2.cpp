#include <iostream>
#include "matrix.h"

using namespace std;


int main() {
	//write test code
	Matrix M1(3, 3), M2(3, 3), M3(3, 3); //declare multiple 3X3 matrices
	cin >> M1;
	cin >> M2;
	cin >> M3;
	Matrix M4 = M1 - M2 + M3; //should be able to write expressions of this form
	cout << M4;

	Matrix M5 = M1(1, 2); //returns a matrix of size 1X2 starting from row-0 and col-0
	//cin >> M5;
	cout << M5;
	return 0;
}