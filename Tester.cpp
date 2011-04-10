#include <iostream>
#include "Matrix.h"
#include "Fraction.h"
using std::cout;
using std::cin;

int main(int argc, char* argv)
{
	cout<<"\nWelcome to the Matrix Template Tester.\n";
	cout<<"Let's demonstrate that the Matrix tester works.";
	cout<<"Please enter the elements of two 2x2 matrices. Let's start with two integer matrices.\n";
	cout<<"First the first matrix: ";
	Matrix<int> a(2,2,true);
	cout<<"Then the second matrix: ";
	Matrix<int> b(2,2,true);
	cout<<"\nThe sum between the two is\n"<< a + b<<"\n";
	cout<<"\nThe difference between the two is\n"<< a - b<<"\n";
	cout<<"\nThe product of the two is\n"<< a * b<<"\n";
	
	cout<<"Now try entering doubles.\n";
	cout<<"Please enter the elements of two 2x2 matrices. Let's start with two integer matrices.\n";
	cout<<"First the first matrix: ";
	Matrix<double> c(2,2,true);
	cout<<"Then the second matrix: ";
	Matrix<double> d(2,2,true);
	cout<<"\nThe sum between the two is\n"<< c + d<<"\n";
	cout<<"\nThe difference between the two is\n"<< c - d<<"\n";
	cout<<"\nThe product of the two is\n"<< c * d<<"\n";

	cout<<"Now try entering fractions.\n";
	cout<<"Please fill in the first matrix, separating numerators and denominators with spaces: \n";
	Matrix<Fraction> e(2,2,true);
	cout<<"Please fill in the second matrix: \n";
	Matrix<Fraction> f(2,2,true);
	cout<<"\nThe sum between the two is\n"<< e + f<<"\n";
	cout<<"\nThe difference between the two is\n"<< e - f<<"\n";
	cout<<"\nThe product of the two is\n"<< e * f<<"\n";
	
	cout<<"This will work for any object type that has overloaded the arithmetic operators\n";
	cout<<"because the Matrix is no longer an object but a template.\n";
	
}
