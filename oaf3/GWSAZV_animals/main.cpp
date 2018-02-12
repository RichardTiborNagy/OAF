#include "animal.h"

#include <iostream>
#include <fstream>
#include <vector>

int main() {
    //beolvasás
	std::ifstream f("input4.txt");
	int n;
	f >> n;
	std::vector<Animal*> animals(n);
	for (int i = 0; i<n; ++i) {
		char t;
		std::string x;
		int v;
		f >> t >> x >> v;
		switch (t) {
			case 'H': animals[i] = new Fish(x, v); break;
			case 'M': animals[i] = new Bird(x, v); break;
			case 'K': animals[i] = new Dog(x, v); break;
		}
	}

    //napok szimulációja
	std::string moods;
	f >> moods;
	for (int i = 0; i < moods.length(); ++i) {
		char c = moods[i];
		for (int j = 0; j < n; ++j) {
			animals[j]->change(c);
		}
	}

    //feltételes minimumkiválasztás
	bool l = false;
	int ind;
	for (int i = 0; i < n; ++i) {
		if (!animals[i]->alive()) continue;
		if (animals[i]->alive() && !l) {
			ind = i;
			l = true;
		} else {
			if (animals[i]->getVim() < animals[ind]->getVim()) ind = i;
		}
	}

    //legszomorúbb élő állat(ok) kiírása
	if (!l) std::cout << "Nincs elo allat";
	else {
		int min = animals[ind]->getVim();
		std::cout << "A legszomorubb elo allat(ok): ";
		for (int i = 0; i < n; ++i) {
			if (min == animals[i]->getVim()) std::cout << animals[i]->getName() << ", ";
		}
	}

    //a lefoglalt memória felszabadítása
	for (int i = 0; i < n; ++i) delete animals[i];

	return 0;
}
