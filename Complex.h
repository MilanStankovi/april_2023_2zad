#pragma once
#include <iostream>
using namespace std;
class Complex
{
	double real;
	double img;
public:
	//ulaz, izlaz, jednako, puta, plus
	Complex();
	Complex(double r, double i);
	friend istream& operator>>(istream& ulaz, Complex& c);
	friend ostream& operator<<(ostream& izlaz, Complex& c);
	Complex& operator=(Complex& c);
	Complex operator*(Complex& c);
	Complex operator+(Complex& c);
};

