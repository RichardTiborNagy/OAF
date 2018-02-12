#include <iostream>
#include "poly.h"

//Konstruktor
//Tev�kenys�g: A konstruktor l�trehoz egy adott fok� polinomot, azaz lefoglalja
//  annak egy�tthat�it tartalmaz� k hossz� t�mb�t, �s felt�lti csupa nulla �rt�kkel.
//Bemen� adatok : egy�tthat�k sz�ma (k:int)
//Kimen� adatok : �j polinom (Poly)
Poly::Poly(int k){
	n = k;
	v = new double[n];
	for (int i = 0; i < n; ++i) v[i] = 0.0;
}

//M�sol� konstruktor
//Tev�kenys�g: A konstruktor l�trehoz egy �j polinomot ami megegyezik a param�terk�nt 
//  megadott polinommal, azaz automatikusan lefoglal egy megfelel� (a param�ter polinom m�ret�vel megegyez�)
//  m�ret� t�mb�t, �s felt�lti a m�soland� polinom egy�tthat�ival.
//Bemen� adatok : egy polinom(cPoly : Poly)
//Kimen� adatok : �j polinom(Poly)
Poly::Poly(const Poly & cPoly){
	n = cPoly.n;
	v = new double[n];
	for (int i = 0; i <= n; ++i)
		v[i] = cPoly.v[i];
}

//�tm�retez� f�ggv�ny
//Tev�kenys�g: Egy polinomot n egy�tthat�ss� alak�t, azaz lefoglalja 
//  annak egy�tthat�it tartalmaz� n hossz� t�mb�t, �s felt�lti csupa nulla �rt�kkel.
//Bemen� adatok : egy�tthat�k sz�ma(k : int)
//Kimen� adatok : �j m�ret� polinom(Poly)
void Poly::Size(int k) {
	if (v != NULL) delete[]	v;
	if (n != k && k > 0) v = new double[k];
	n = k;
	for (int i = 0; i < n; i++) v[i] = 0;
}

//Destruktor
//Tev�kenys�g: T�rli a polinomot �s felszabad�tja az �ltala lefoglalt mem�riater�letet
Poly::~Poly(){
	delete[] v;
}

//�rt�kad�s oper�tor
//Tev�kenys�g: Az oper�tor �rt�k�l adja az �rt�kad�s jobboldal�n adott polinomot a
//	baloldal�n �ll�(az oper�tor �ltal alap�rtelmezett) polinomnak. El�sz�r ellen�rzi, 
//  hogy a t�mb�k m�rete megegyezik-e, majd �tm�solja az egy�tthat�kat.
//Bemen� adatok : egy polinom(cPoly : Poly)
//Kimen� adatok : polinom(Poly)
Poly Poly::operator=(const Poly & cPoly){
	if (n != cPoly.n) {
		std::cout << "K�l�nb�z� m�ret� t�mb�k" << std::endl;
		return *this;
	}
	for (int i = 0; i <= n; ++i)
		v[i] = cPoly.v[i];
	return *this;
}

//Beolvas� f�ggv�ny
//Tev�kenys�g: A standard bemenetr�l bek�ri az adott polinom egy�tthat�it.
//Be/kimen� adat : standard iostream
//Bemen� adatsor : polinom egy�tthat�k
void Poly::read(){	
	for (int i = 0; i < n; ++i){
		std::cout << "Adja meg a polinom x^" << i << "-s egy�tthat�j�t: ";
		std::cin >> v[i];
	}
}

//Ki�r� f�ggv�ny
//Tev�kenys�g: A standard kimenetre �rja az adott polinomot hagyom�nyos form�ban.
//Be/kimen� adat : standard iostream
void Poly::write(){
	std::cout << v[0] << "x^" << 0;
	for (int i = 1; i < n; ++i){
		if (v[i] != 0)
		std::cout << " + " << v[i] << "x^" << i;
	}
	std::cout << std::endl;
}

//Egy�tthat� lek�r� f�ggv�ny
//Tev�kenys�g: Az oper�tor megadja a polinom egy adott index� egy�tthat�j�t,
//	ha az index a t�mb�n k�v�lre esik, 0-t ad vissza.
//  (ez a m�veleteket teszi egyszer�bb�)
//Bemen� adatok : egy index(i : int)
//Kimen� adatok : egy�tthat�(double)
double Poly::get(int i) const {
	double c = 0;
	if (i >= 0 && i < n) c = v[i];
	return c;
}

//Polinom �sszead�s
//Tev�kenys�g: L�trehoz egy polinomot, melynek foka megegyezik a param�terk�nt 
//  kapot polinomok k�z�l a nagyobbik�val, majd az egy�tthat�k t�mbj�t felt�lti
//  a param�ter polinomok egy�tthat�inak p�ronk�nti �sszead�s�val
//Bemen� adatok : k�t polinom(a,b : Poly)
//Kimen� adatok : polinom (c : Poly)
Poly add(const Poly& a, const Poly& b) {
	Poly c = Poly(a.n < b.n ? b.n : a.n);
	for (int i = 0; i < c.n; i++){
		c.v[i] = a.get(i) + b.get(i);
	}
	return c;
}

//Polinom szorz�s
//Tev�kenys�g: L�trehoz egy polinomot, melynek foka megegyezik a param�terk�nt 
//  kapot polinomok fok�nak �sszeg�vel, majd az egy�tthat�k t�mbj�t felt�lti
//  a polinomszorz�s szab�lyai szerint
//Bemen� adatok : k�t polinom(a,b : Poly)
//Kimen� adatok : polinom (c : Poly)
Poly mult(const Poly& a, const Poly& b) {
	Poly c = Poly(a.n + b.n - 1);
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < b.n; j++){
			c.v[i+j] += a.get(i) * b.get(j);
		}
	}
	return c;
}