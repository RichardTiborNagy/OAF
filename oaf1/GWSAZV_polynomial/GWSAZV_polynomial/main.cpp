//K�sz�tette:   Nagy Rich�rd Tibor
//Neptun k�d:   GWSAZV
//e-mail:       ricso1996@gmail.com
//csoport:      3.csoport
//Feladat:      1.beadand�/4.feladat

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

	// = oper�tor �s copy constructor teszt
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
	cout << " 1. -Polinom felt�lt�se" << endl;
	cout << " 2. -Polinom ki�r�sa" << endl;
	cout << " 3. -Polinomhoz egy m�sik polinom hozz�ad�sa" << endl;
	cout << " 4. -Polinom szorz�sa egy m�sik polinommal" << endl;
	cout << " 0. -Kil�p�s" << endl;
}

void Menu::GetPoly() {
	int k;
	cout << endl << "Adja meg a polinom egy�tthat�inak sz�m�t: ";
	cin >> k;
	if (k < 0) {
		cout << "Nem lehet negat�v";
		return;
	}
	a.Size(k);
	a.read();
}

void Menu::WritePoly() {
	cout << endl << "A felt�lt�tt polinom: " << endl;
	a.write();
}

void Menu::Sum() {
	cout << endl << "M�sodik polinom egy�tthat�inak sz�ma:" << endl;
	int k;
	cin >> k;
	if (k < 0) {
		cout << "Nem lehet negat�v";
		return;
	}
	Poly b = Poly(k);
	b.read();
	cout << "A m�sodik polinom: " << endl;
	b.write();
	cout << endl << "Az �sszead�s eredm�nye: " << endl;
	add(a, b).write();
}
void Menu::Mul() {
	cout << endl << "M�sodik polinom egy�tthat�inak sz�ma:" << endl;
	int k;
	cin >> k;
	if (k < 0) {
		cout << "Nem lehet negat�v";
		return;
	}
	Poly b = Poly(k);
	b.read();
	cout << "A m�sodik polinom: " << endl;
	b.write();
	cout << endl << "Az szorz�s eredm�nye: " << endl;
	mult(a, b).write();
}

