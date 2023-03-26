# Matrix-Class-cpp

Implementation of Matrix Class – Your goal is to implement a generic “Matrix" class. You will need to write three
files (matrix.h, matrix.cpp and Q2.cpp). Your implemented class must fully provide the definitions of following class
(interface) functions. Please also write down the test code to drive your class implementation. Please note that we
will be running your code against our test code and any segmentation faults or incorrect result will result in loss of
marks.

class Matrix{
      // think about the private data members...
      // the matrix should store real numbers
      public:
      //include all the necessary checks before performing the operations in the
      functions
      Matrix();// a default constructor
      Matrix(int, int);// a parametrized constructor
      Matrix(const Matrix &);// copy constructor
      operator[]();//set and get value at (i,j)
      Matrix& operator=(const Matrix &); //assigns matrix on RHS to the one on LHS
      Matrix& operator+(const Matrix &); //add two matrices
      Matrix& operator-(const Matrix &); //subtracts two matrices
      Matrix& operator*(const Matrix &); //dot product of two matrices
      bool operator==(const Matrix &); //checks if two matrices are equal
      Matrix& operator+=(int);//adds an integer to all elements
      Matrix& operator-=(int);//subtracts an integer from all elements
      Matrix& operator*=(int);//multiples an integer to all elements
      Matrix& operator/=(int);//divides all elements by an integer

      Matrix& operator()(int A, int B);//returns a new matrix of size A x B
       ̃Matrix();
};

ostream& operator<<(ostream&, const Matrix &); //outputs the matrix
istream& operator>>(istream&, const Matrix &); //inputs the matrix
      
int main(){
      //write test code
      Matrix M1(3,3), M2(3,3), M3(3,3); //declare multiple 3X3 matrices
      Matrix M4 = M1 – M2 + M3; //should be able to write expressions of this form

      Matrix M5 = M1(1,2); //returns a matrix of size 1X2 starting from row-0 and col-0
}
