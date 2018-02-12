//Készítette:   Nagy Richárd Tibor
//Neptun kód:   GWSAZV
//e-mail:       ricso1996@gmail.com
//csoport:      3.csoport
//Feladat:      1.beadandó/4.feladat

#include <iostream>
#include "poly.h"

using namespace std;

class Menu {
public:
	void Run();
	Poly a = Poly(1);
private:
	void MenuWrite();
	void GetPoly();
	void WritePoly();
	void Sum();
	void Mul();
};

int main(){
	setlocale(LC_ALL, "hun");

	// = operátor és copy constructor teszt
	/*
	Poly a = Poly(3);
	a.read();
	Poly b = Poly(3);
	b = a;
	Poly c = Poly(a);
	c.write();
	b.write();
	*/

	Menu m;
	m.Run();

    return 0;
}

void Menu::Run(){
	int c = 0;
	do {
		MenuWrite();
		cin >> c;
		switch (c) {
		case 1: GetPoly(); break;
		case 2: WritePoly(); break;
		case 3: Sum(); break;
		case 4: Mul(); break;
		}
	} while (c != 0);
}

void Menu::MenuWrite(){
	cout << endl << endl;
	cout << " 1. -Polinom feltöltése" << endl;
	cout << " 2. -Polinom kiírása" << endl;
	cout << " 3. -Polinomhoz egy másik polinom hozzáadása" << endl;
	cout << " 4. -Polinom szorzása egy másik polinommal" << endl;
	cout << " 0. -Kilépés" << endl;
}

void Menu::GetPoly() {
	int k;
	cout << endl << "Adja meg a polinom együtthatóinak számát: ";
	cin >> k;
	if (k < 0) {
		cout << "Nem lehet negatív";
		return;
	}
	a.Size(k);
	a.read();
}

void Menu::WritePoly() {
	cout << endl << "A feltöltött polinom: " << endl;
	a.write();
}

void Menu::Sum() {
	cout << endl << "Második polinom együtthatóinak száma:" << endl;
	int k;
	cin >> k;
	if (k < 0) {
		cout << "Nem lehet negatív";
		return;
	}
	Poly b = Poly(k);
	b.read();
	cout << "A második polinom: " << endl;
	b.write();
	cout << endl << "Az összeadás eredménye: " << endl;
	add(a, b).write();
}
void Menu::Mul() {
	cout << endl << "Második polinom együtthatóinak száma:" << endl;
	int k;
	cin >> k;
	if (k < 0) {
		cout << "Nem lehet negatív";
		return;
	}
	Poly b = Poly(k);
	b.read();
	cout << "A második polinom: " << endl;
	b.write();
	cout << endl << "Az szorzás eredménye: " << endl;
	mult(a, b).write();
}

