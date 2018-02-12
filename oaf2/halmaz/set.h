#ifndef SET_H
#define SET_H
#include <iostream>

class Set {
	private:
		//listaelem-t�pus
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

		//m�sol� konstruktor
		Set(const Set&);

		//�rt�kad�s oper�tor
		Set& operator= (const Set&);

		//destruktor
		~Set();

		//elem bet�tele a halmazba
		void insert(int);

		//elem kiv�tele a halmazb�l
		void remove(int);

		//benne van-e egy adott elem a halmazban
		bool isElement(int);

		//�res-e a halmaz
		bool empty();

		//ki�r� oper�tor
		friend std::ostream& operator<<	(std::ostream& s, const Set& a);

		//k�t halmaz metszete
		friend void section(const Set&, const Set&);

		//k�t halmaz szimmetrikus differenci�ja
		friend void symDiff(const Set&, const Set&);
};

#endif SET_H
