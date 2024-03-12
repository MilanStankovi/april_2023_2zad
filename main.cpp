#include "Complex.h"
#include "KvadratnaMatrica.h"

void main() {
	KvadratnaMatrica<int>* k1 = new KvadratnaMatrica<int>(3);
	KvadratnaMatrica<int>* k2 = new KvadratnaMatrica<int>(3);
	KvadratnaMatrica<int>* z1 = new KvadratnaMatrica<int>(3);
	KvadratnaMatrica<Complex>* k3 = new KvadratnaMatrica<Complex>;
	KvadratnaMatrica<Complex>* k4 = new KvadratnaMatrica<Complex>;
	cin >> *k1;
	cin >> *k2;
	*z1 = *k1 + *k2;
}