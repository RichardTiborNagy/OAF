#include "set.cpp"

using namespace std;

class Menu {
public:
	void Run();
	Set a;
	Set b;
private:
	void MenuWrite();
	void insertToSet();

};

int main() {
	setlocale(LC_ALL, "hun");

	Menu m;
	m.Run();

	//Set asd;
	//Set bsd;
	//asd.insert(1);
	//asd.insert(2);
	//asd.insert(3);
	//std::cout << asd.isElement(5);
	//bsd = asd;
	//section(asd, bsd);
	//symDiff(asd, bsd);
	//std::cout << asd;
	//std::cout << bsd;
	//int k;
	//std::cin >>k;

	return 0;
}

void Menu::Run() {
	int c = 0;
	do {
		MenuWrite();
		cin >> c;
		int k;
		switch (c) {
		case 1:
			cout << "Adja meg a besz�rni k�v�nt elemet: " << endl;
			cin >> k;
			a.insert(k);
			break;
		case 2:
			cout << "Adja meg a besz�rni k�v�nt elemet: " << endl;
			cin >> k;
			b.insert(k);
			break;
		case 3:
			cout << "Adja meg a kivenni k�v�nt elemet: " << endl;
			cin >> k;
			a.remove(k);
			break;
		case 4:
			cout << "Adja meg a kivenni k�v�nt elemet: " << endl;
			cin >> k;
			b.remove(k);
			break;
		case 5:
			cout << "A k�t halmaz metszete: ";
			section(a, b);
			break;
		case 6:
			cout << "A k�t halmaz szimmetrikus differenci�ja: ";
			symDiff(a, b);
			break;
		case 7:
			cout << "Az els� halmaz: " << a;
			cout << "Az m�sodik halmaz: " << b;
			break;
		case 8:
			Set d;
			Set c = Set(a);
			d = b;
			cout << "M�sol� konstruktor, els� halmaz: " << c;
			cout << "�rt�kad�s oper�tor, m�sodik halmaz: " << d;
			break;
		}
	} while (c != 0);
}

void Menu::MenuWrite() {
	cout << endl << endl;
	cout << " 1. -Elem besz�r�sa az els� halmazba" << endl;
	cout << " 2. -Elem besz�r�sa a m�sodik halmazba" << endl;
	cout << " 3. -Elem kiv�tele az els� halmazb�l" << endl;
	cout << " 4. -Elem kiv�tele a m�sodik halmazb�l" << endl;
	cout << " 5. -A k�t halmaz metszete" << endl;
	cout << " 6. -A k�t halmaz szimmetrikus differenci�ja" << endl;
	cout << " 7. -Halmazok ki�r�sa" << endl;
	cout << " 8. -�rt�kad�s oper�tor �s copy konstruktor tesztel�se" << endl;
	cout << " 0. -Kil�p�s" << endl;
}
