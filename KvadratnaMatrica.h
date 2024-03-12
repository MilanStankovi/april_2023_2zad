#pragma once
#include <iostream>
#include <fstream>
using namespace std;
template <class T>
class KvadratnaMatrica
{
	int n;
	T** mat;
public:
	KvadratnaMatrica(KvadratnaMatrica<T>& k);
	KvadratnaMatrica();
	KvadratnaMatrica(int x);
	~KvadratnaMatrica();
	friend istream& operator>>(istream& ulaz, KvadratnaMatrica<T>& m);
	friend ostream& operator<<(ostream& izlaz, KvadratnaMatrica<T>& m);
	KvadratnaMatrica<T> operator+(KvadratnaMatrica<T>& m1);
	KvadratnaMatrica<T> operator* (KvadratnaMatrica<T>& m1);
	KvadratnaMatrica<T>& operator=(KvadratnaMatrica<T>& m1);
	void ucitaj(const char* c);
	void stampaj(const char* c);
};
template <class T>
KvadratnaMatrica<T>::KvadratnaMatrica() {
	n = 0;
	mat = nullptr;
}
template <class T>
KvadratnaMatrica<T>::KvadratnaMatrica(int x) {
	n = x;
	mat = new T * [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new T[n];
	}
}
template <class T>
KvadratnaMatrica<T>::~KvadratnaMatrica() {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}
template <class T>
istream& operator>>(istream& ulaz, KvadratnaMatrica<T>& m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			ulaz >> m.mat[i][j];
		}
	}
	return ulaz;
}
template <class T>
ostream& operator<<(ostream& izlaz, KvadratnaMatrica<T>& m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			izlaz << m.mat[i][j];
		}
	}
	return izlaz;
}
template <class T>
KvadratnaMatrica<T> KvadratnaMatrica<T>::operator+(KvadratnaMatrica<T>& m1) {
	KvadratnaMatrica<T> rez(n);
	if (n != m1.n) {
		throw "Matrice nisu istih dimenzija";
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rez.mat[i][j] = mat[i][j] + m1.mat[i][j];
		}
	}
	return rez;
}
template <class T>
KvadratnaMatrica<T> KvadratnaMatrica<T>::operator* (KvadratnaMatrica<T>& m1) {
	if (n != m1.n) {
		throw "Matrice nisu istih dimenzija";
	}
	KvadratnaMatrica<T> rez(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rez.mat[i][j] = 0;
			for (int k = 0; k < n; k++) {
				rez.mat[i][j] = mat[i][k] * mat[k][j];
			}
		}
	}
	return rez;
}
template <class T>
KvadratnaMatrica<T>& KvadratnaMatrica<T>::operator=(KvadratnaMatrica<T>& m1) {
	if (this != &m1) {
		if (n != m1.n) {
			for (int i = 0; i < n; i++) {
				delete[] mat[i];
			}
			delete[] mat;
			n = m1.n;
			mat = new T * [n];
			for (int i = 0; i < n; i++) {
				mat[i] = new T[n];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					mat[i][j] = m1.mat[i][j];
				}
			}
		}
	}
	return *this;
}
template<class T>
void KvadratnaMatrica<T>::ucitaj(const char* c) {
	ifstream ulaz(c);
	if (ulaz.good()) {
		ulaz >> n;
		this->KvadratnaMatrica(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ulaz >> mat[i][j];
			}
		}
	}
	else {
		throw "Greska kod fajla";
	}
	ulaz.close();
}
template <class T>
void KvadratnaMatrica<T>::stampaj(const char* c) {
	ofstream izlaz(c);
	izlaz << n << endl;
	if (izlaz.good()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				izlaz << mat[i][j];
			}
		}
	}
	else {
		throw "Greska iz fajla";
	}
	izlaz.close();
}
template <class T>
KvadratnaMatrica<T>::KvadratnaMatrica(KvadratnaMatrica<T>& k) {
	n = k.n;
	mat = new T * [n];
	for (int i = 0; i < n; i++) {
		mat[i] = new T[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = k.mat[i][j];
		}
	}
}