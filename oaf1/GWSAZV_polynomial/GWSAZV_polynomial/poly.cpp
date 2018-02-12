#include <iostream>
#include "poly.h"

//Konstruktor
//Tevékenység: A konstruktor létrehoz egy adott fokú polinomot, azaz lefoglalja
//  annak együtthatóit tartalmazó k hosszú tömböt, és feltölti csupa nulla értékkel.
//Bemenõ adatok : együtthatók száma (k:int)
//Kimenõ adatok : új polinom (Poly)
Poly::Poly(int k){
	n = k;
	v = new double[n];
	for (int i = 0; i < n; ++i) v[i] = 0.0;
}

//Másoló konstruktor
//Tevékenység: A konstruktor létrehoz egy új polinomot ami megegyezik a paraméterként 
//  megadott polinommal, azaz automatikusan lefoglal egy megfelelõ (a paraméter polinom méretével megegyezõ)
//  méretû tömböt, és feltölti a másolandó polinom együtthatóival.
//Bemenõ adatok : egy polinom(cPoly : Poly)
//Kimenõ adatok : új polinom(Poly)
Poly::Poly(const Poly & cPoly){
	n = cPoly.n;
	v = new double[n];
	for (int i = 0; i <= n; ++i)
		v[i] = cPoly.v[i];
}

//Átméretezõ függvény
//Tevékenység: Egy polinomot n együtthatóssá alakít, azaz lefoglalja 
//  annak együtthatóit tartalmazó n hosszú tömböt, és feltölti csupa nulla értékkel.
//Bemenõ adatok : együtthatók száma(k : int)
//Kimenõ adatok : új méretû polinom(Poly)
void Poly::Size(int k) {
	if (v != NULL) delete[]	v;
	if (n != k && k > 0) v = new double[k];
	n = k;
	for (int i = 0; i < n; i++) v[i] = 0;
}

//Destruktor
//Tevékenység: Törli a polinomot és felszabadítja az általa lefoglalt memóriaterületet
Poly::~Poly(){
	delete[] v;
}

//Értékadás operátor
//Tevékenység: Az operátor értékül adja az értékadás jobboldalán adott polinomot a
//	baloldalán álló(az operátor által alapértelmezett) polinomnak. Elõször ellenõrzi, 
//  hogy a tömbök mérete megegyezik-e, majd átmásolja az együtthatókat.
//Bemenõ adatok : egy polinom(cPoly : Poly)
//Kimenõ adatok : polinom(Poly)
Poly Poly::operator=(const Poly & cPoly){
	if (n != cPoly.n) {
		std::cout << "Különbözõ méretû tömbök" << std::endl;
		return *this;
	}
	for (int i = 0; i <= n; ++i)
		v[i] = cPoly.v[i];
	return *this;
}

//Beolvasó függvény
//Tevékenység: A standard bemenetrõl bekéri az adott polinom együtthatóit.
//Be/kimenõ adat : standard iostream
//Bemenõ adatsor : polinom együtthatók
void Poly::read(){	
	for (int i = 0; i < n; ++i){
		std::cout << "Adja meg a polinom x^" << i << "-s együtthatóját: ";
		std::cin >> v[i];
	}
}

//Kiíró függvény
//Tevékenység: A standard kimenetre írja az adott polinomot hagyományos formában.
//Be/kimenõ adat : standard iostream
void Poly::write(){
	std::cout << v[0] << "x^" << 0;
	for (int i = 1; i < n; ++i){
		if (v[i] != 0)
		std::cout << " + " << v[i] << "x^" << i;
	}
	std::cout << std::endl;
}

//Együttható lekérõ függvény
//Tevékenység: Az operátor megadja a polinom egy adott indexû együtthatóját,
//	ha az index a tömbön kívülre esik, 0-t ad vissza.
//  (ez a mûveleteket teszi egyszerûbbé)
//Bemenõ adatok : egy index(i : int)
//Kimenõ adatok : együttható(double)
double Poly::get(int i) const {
	double c = 0;
	if (i >= 0 && i < n) c = v[i];
	return c;
}

//Polinom összeadás
//Tevékenység: Létrehoz egy polinomot, melynek foka megegyezik a paraméterként 
//  kapot polinomok közül a nagyobbikéval, majd az együtthatók tömbjét feltölti
//  a paraméter polinomok együtthatóinak páronkénti összeadásával
//Bemenõ adatok : két polinom(a,b : Poly)
//Kimenõ adatok : polinom (c : Poly)
Poly add(const Poly& a, const Poly& b) {
	Poly c = Poly(a.n < b.n ? b.n : a.n);
	for (int i = 0; i < c.n; i++){
		c.v[i] = a.get(i) + b.get(i);
	}
	return c;
}

//Polinom szorzás
//Tevékenység: Létrehoz egy polinomot, melynek foka megegyezik a paraméterként 
//  kapot polinomok fokának összegével, majd az együtthatók tömbjét feltölti
//  a polinomszorzás szabályai szerint
//Bemenõ adatok : két polinom(a,b : Poly)
//Kimenõ adatok : polinom (c : Poly)
Poly mult(const Poly& a, const Poly& b) {
	Poly c = Poly(a.n + b.n - 1);
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < b.n; j++){
			c.v[i+j] += a.get(i) * b.get(j);
		}
	}
	return c;
}