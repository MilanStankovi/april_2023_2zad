#include "Complex.h"
Complex::Complex() {
	real = img = 0;
}
Complex::Complex(double r, double i) {
	real = r;
	img = i;
}
istream& operator>>(istream& ulaz, Complex& c) {
	ulaz >> c.real;
	ulaz >> c.img;
	return ulaz;
}
ostream& operator<<(ostream& izlaz, Complex& c) {
	izlaz << c.real << " " << c.img;
	return izlaz;
}
Complex& Complex::operator=(Complex& c) {
	if (this != &c) {
		real = c.real;
		img = c.img;
	}
	return *this;
}
Complex Complex::operator*(Complex& c) {
	Complex rez;
	rez.real = real * c.real + img * c.img;
	rez.img = real * c.img + c.real * img;
	return rez;
}
Complex Complex::operator+(Complex& c) {
	Complex rez;
	rez.real = real + c.real;
	rez.img = img + c.img;
	return rez;
}