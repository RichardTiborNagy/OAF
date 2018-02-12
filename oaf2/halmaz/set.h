#ifndef SET_H
#define SET_H
#include <iostream>

class Set {
	private:
		//listaelem-típus
		struct Node {
			int val;
			Node* next;
			Node(int a, Node* n) : val(a), next(n) {};
		};
		//fejelem
		Node* head;

	public:
		enum Exceptions { FULLMEM, EMPTYSET, ALREADYELEMENT };

		//konstruktor
		Set();

		//másoló konstruktor
		Set(const Set&);

		//értékadás operátor
		Set& operator= (const Set&);

		//destruktor
		~Set();

		//elem betétele a halmazba
		void insert(int);

		//elem kivétele a halmazból
		void remove(int);

		//benne van-e egy adott elem a halmazban
		bool isElement(int);

		//üres-e a halmaz
		bool empty();

		//kiíró operátor
		friend std::ostream& operator<<	(std::ostream& s, const Set& a);

		//két halmaz metszete
		friend void section(const Set&, const Set&);

		//két halmaz szimmetrikus differenciája
		friend void symDiff(const Set&, const Set&);
};

#endif SET_H
