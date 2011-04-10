/*
 * Fraction.h
 *
 *  Created on: Feb 1, 2011
 *      Author: MasonSilber
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
//using namespace std;

class Fraction {

  // a + b
  friend Fraction operator+(const Fraction& a, const Fraction& b);
  // a - b
  friend Fraction operator-(const Fraction& a, const Fraction& b);
  // a*b
  friend Fraction operator*(const Fraction& a, const Fraction& b);
  //a/b
  friend Fraction operator/(const Fraction& a, const Fraction& b);

  // Overload the stream operator so we can use cout with our Fraction class
  friend std::ostream& operator<<(std::ostream& output, Fraction& a);
  
  friend std::istream& operator>>(std::istream& input, Fraction& a);

public:
	Fraction();

	Fraction(int num, int denom);

	Fraction(const Fraction& rhs);
	Fraction& operator=(const Fraction& rhs);
	Fraction& operator = (int rhs);


	~Fraction();

	void setNumerator(int num);

	void setDenominator(int denom);

	int getNumerator() const;

	int getDenominator() const;

	Fraction add(Fraction otherFraction);

	Fraction subtract(Fraction otherFraction);

	Fraction multiply(Fraction otherFraction);

	Fraction divide(Fraction otherFraction);

	void reduce();

private:
	int numerator, denominator;
};

#endif /* FRACTION_H_ */
