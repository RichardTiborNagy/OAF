#include "set.h"

//Konstruktor
//Tev�kenys�g: A konstruktor egy �res halmazt, azaz egy nulla hossz�s�g� l�ncolt
//	list�t hoz l�tre �gy, hogy a fejelem mutat�j�t NULL - ra �ll�tja.
//Bemen� adatok : -
//Kimen� adatok : �j �res halmaz(Set)
Set::Set() {
	head = new Node(0, NULL);
}

//Destruktor
Set::~Set() {
	Node *p, *q;
	q = head->next;
	while (q != NULL) {
		p = q;
		q = q->next;
		delete p;
	}
}

//copy konstruktor
Set::Set(const Set& s) {
	head = new Node(0, NULL);
	if (s.head->next == NULL) {
		return;
	} else {
		try {
			Node *q = new Node(s.head->next->val, NULL);
			head->next = q;
			for (Node *p = s.head->next->next; p != NULL; p = p->next) {
				q->next = new Node(p->val, NULL);
				q = q->next;
			}
		} catch (std::bad_alloc o) {
			Node *p, *q;
			q = head->next;
			while (q != NULL) {
				p = q;
				q = q->next;
				delete p;
			}
			throw FULLMEM;
		}
	}
}

//�rt�kad�s oper�tor
Set& Set::operator=(const Set & s) {
	if (&s == this) return *this;
	//destruktor
	Node *p, *q;
	q = head->next;
	while (q != NULL) {
		p = q;
		q = q->next;
		delete p;
	}
	//copy
	if (s.head->next == NULL) {
		head->next = NULL;
	}
	else {
		try {
			Node *q = new Node(s.head->next->val, NULL);
			head->next = q;
			for (Node *p = s.head->next->next; p != NULL; p = p->next) {
				q->next = new Node(p->val, NULL);
				q = q->next;
			}
		}
		catch (std::bad_alloc o) {
			Node *p, *q;
			q = head->next;
			while (q != NULL) {
				p = q;
				q = q->next;
				delete p;
			}
			throw FULLMEM;
		}
	}
	return *this;
}

//elem bet�tele
void Set::insert(int value) {
	Node *s = new Node(value, NULL);

	try {
		Node *q, *p;
		q = head;
		p = head->next;

		while (p != NULL && p->val < value) {
			q = p;
			p = p->next;
		}
		if (p != NULL && value == p->val) throw ALREADYELEMENT;
		else {
			s->next = p;
			q->next = s;
		}
	} catch (...) {
		std::cout << std::endl << "Already an element";
	}
}

//elem kiv�tele
void Set::remove(int value) {
	Node *pre, *del;

	pre = head;
	del = head->next;

	while (del != NULL && del->val <= value) {
		if (del->val == value) {
			pre->next = del->next;
			delete del;
			break;
		}
		pre = del;
		del = del->next;
	}
}

//linker
bool Set::isElement(int value) {
	bool l = false;
	Node *q;
	q = head->next;
	while (!l && q != NULL && value >= q->val) {
		l = q->val == value;
		q = q->next;
		std::cout << l;
	}
	return l;
}

//�res-e
bool Set::empty() {
	return head->next==NULL;
}

//metszet
void section(const Set& a, const Set& b) {
	Set::Node *p, *q;
	q = a.head->next;
	p = b.head->next;
	while (p != NULL && q != NULL) {
		if (p->val > q->val) {
			q = q->next;
		}
		else if (p->val < q->val) {
			p = p->next;
		}
		else if(p->val == q->val) {
			std::cout << q->val << " ";
			p = p->next;
			q = q->next;
		}
	}
	std::cout << std::endl;
}

//szimmetrikus differencia
void symDiff(const Set& a, const Set& b) {
	Set::Node *p, *q;
	q = a.head->next;
	p = b.head->next;
	while (p != NULL && q != NULL) {
		if (p->val > q->val) {
			std::cout << q->val << " ";
			q = q->next;
		}
		else if (p->val < q->val) {
			std::cout << p->val << " ";
			p = p->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	if (p == NULL) {
		while (q != NULL) {
			std::cout << q->val << " ";
			q = q->next;
		}
	}
	else if (q == NULL) {
		while (p != NULL) {
			std::cout << p->val << " ";
			p = p->next;
		}
	}
	std::cout << std::endl;
}

//ki�r�s
std::ostream& operator<< (std::ostream& s, const Set& a) {
	if (a.head->next == NULL) {
		s << "�res halmaz" << std::endl;
		return s;
	}
	Set::Node *q;
	q = a.head->next;
	while (q != NULL) {
		s << q->val << " ";
		q = q->next;
	}
	s << std::endl;
	return s;
}
