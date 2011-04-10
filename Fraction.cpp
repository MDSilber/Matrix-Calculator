/*
 * Fraction.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: MasonSilber
 */

#include "Fraction.h"
#include <iostream>
using std::cin;
using std::cout;

	Fraction::Fraction()
	{
		
	}

	Fraction::Fraction(int num, int denom)
	{
		numerator = num;
		denominator = denom;
	}
	
	Fraction::Fraction(const Fraction& rhs)
	{
		numerator = rhs.numerator;
		denominator = rhs.denominator;
	}

	Fraction& Fraction::operator = (const Fraction& rhs)
	{
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		return *this;
	}
	
	Fraction& Fraction::operator = (int rhs)
	{
		numerator = rhs;
		denominator = 1;
		return *this;
	}	

	Fraction::~Fraction(){}
	
	void Fraction::setNumerator(int num)
	{
		numerator = num;
	}
	
	void Fraction::setDenominator(int denom)
	{
		denominator = denom;
	}
	
	int Fraction::getNumerator() const
	{
		return numerator;
	}

	int Fraction::getDenominator() const
	{
		return denominator;
	}

	Fraction Fraction::add(Fraction otherFraction)
	{
		numerator = numerator*otherFraction.getDenominator();
		otherFraction.setNumerator(otherFraction.getNumerator()*denominator);
		denominator = denominator*otherFraction.getDenominator();
		otherFraction.setDenominator(denominator);

		numerator = numerator + otherFraction.getNumerator();
		return *this;
	}

	Fraction Fraction::subtract(Fraction otherFraction)
	{
		numerator = numerator*otherFraction.getDenominator();
		otherFraction.setNumerator(otherFraction.getNumerator()*denominator);
		denominator = denominator*otherFraction.getDenominator();
		otherFraction.setDenominator(denominator);

		numerator = numerator - otherFraction.getNumerator();
		return *this;
	}

	Fraction Fraction::multiply(Fraction otherFraction)
	{
		numerator = numerator*otherFraction.getNumerator();
		denominator = denominator*otherFraction.getDenominator();
		return *this;
	}

	Fraction Fraction::divide(Fraction otherFraction)
	{
		numerator = numerator*otherFraction.getDenominator();
		denominator = denominator*otherFraction.getNumerator();
		return *this;
	}

	void Fraction::reduce()
	{
		for(int i = 2; i<=denominator; i++)
		{
			if(numerator%i == 0 && denominator%i == 0)
			{
				numerator = numerator/i;
				denominator = denominator/i;
				i = 1;
			}
		}
	}

	Fraction operator+(const Fraction& a, const Fraction& b)
	{
		int numerator, denominator;
		
		numerator = a.getNumerator()*b.getDenominator() + a.getDenominator()*b.getNumerator();
		denominator = a.getDenominator()*b.getDenominator();
		
		Fraction solution(numerator, denominator);
		solution.reduce();
		return solution;
	}
	
	Fraction operator-(const Fraction& a, const Fraction& b)
	{
		int numerator, denominator;
		
		numerator = a.getNumerator()*b.getDenominator() - a.getDenominator()*b.getNumerator();
		denominator = a.getDenominator()*b.getDenominator();
		
		Fraction solution(numerator, denominator);
		solution.reduce();
		return solution;
	}
	
	Fraction operator*(const Fraction& a, const Fraction& b)
	{
		int numerator,denominator;
		
		numerator = a.getNumerator()*b.getNumerator();
		denominator = a.getDenominator()*b.getDenominator();
		
		Fraction solution(numerator, denominator);
		solution.reduce();
		return solution;
	}
	
	Fraction operator/(const Fraction& a, const Fraction& b)
	{
		int numerator,denominator;
		
		numerator = a.getNumerator()*b.getDenominator();
		denominator = a.getDenominator()*b.getNumerator();
		
		Fraction solution(numerator, denominator);
		solution.reduce();
		return solution;
	}	
	
	std::ostream& operator<<(std::ostream& output, Fraction& a)
	{
		output<<a.getNumerator()<<"/"<<a.getDenominator();
		return output;
	}
	
	std::istream& operator>>(std::istream& input, Fraction& a)
	{
		input >> a.numerator >> a.denominator;
		return input;
	}
		