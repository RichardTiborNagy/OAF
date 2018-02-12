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
			cout << "Adja meg a beszúrni kívánt elemet: " << endl;
			cin >> k;
			a.insert(k);
			break;
		case 2:
			cout << "Adja meg a beszúrni kívánt elemet: " << endl;
			cin >> k;
			b.insert(k);
			break;
		case 3:
			cout << "Adja meg a kivenni kívánt elemet: " << endl;
			cin >> k;
			a.remove(k);
			break;
		case 4:
			cout << "Adja meg a kivenni kívánt elemet: " << endl;
			cin >> k;
			b.remove(k);
			break;
		case 5:
			cout << "A két halmaz metszete: ";
			section(a, b);
			break;
		case 6:
			cout << "A két halmaz szimmetrikus differenciája: ";
			symDiff(a, b);
			break;
		case 7:
			cout << "Az elsõ halmaz: " << a;
			cout << "Az második halmaz: " << b;
			break;
		case 8:
			Set d;
			Set c = Set(a);
			d = b;
			cout << "Másoló konstruktor, elsõ halmaz: " << c;
			cout << "Értékadás operátor, második halmaz: " << d;
			break;
		}
	} while (c != 0);
}

void Menu::MenuWrite() {
	cout << endl << endl;
	cout << " 1. -Elem beszúrása az elsõ halmazba" << endl;
	cout << " 2. -Elem beszúrása a második halmazba" << endl;
	cout << " 3. -Elem kivétele az elsõ halmazból" << endl;
	cout << " 4. -Elem kivétele a második halmazból" << endl;
	cout << " 5. -A két halmaz metszete" << endl;
	cout << " 6. -A két halmaz szimmetrikus differenciája" << endl;
	cout << " 7. -Halmazok kiírása" << endl;
	cout << " 8. -Értékadás operátor és copy konstruktor tesztelése" << endl;
	cout << " 0. -Kilépés" << endl;
}
