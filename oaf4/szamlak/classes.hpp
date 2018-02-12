#ifndef CLASSES_HPP
#define CLASSES_HPP

#include "summation.hpp"
#include "seqinfileenumerator.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Pair {
	int accoutNumber;
	int balance;
	friend ifstream& operator>> (ifstream&, Pair&);
	friend ofstream& operator<< (ifstream&, const Pair&);
};

ifstream& operator>> (ifstream& f, Pair& pair){
	f >> pair.accoutNumber >> pair.balance;
	return f;
}

ofstream& operator<< (ofstream& f, const Pair& pair) {
	f << pair.accoutNumber << ' ' << pair.balance << endl;
	return f;
}

class InnerSummation : public Summation<Pair, int> {
private:
	int currAccount;
	void init() { *_result = 0; }
	void first() {}
	bool whileCond(const Pair& pair) const { return currAccount == pair.accoutNumber; }
	void add(const Pair& pair) { *_result += pair.balance; }
public:
	InnerSummation(int accountNumber) : Summation<Pair, int>(), currAccount(accountNumber) {}
};

class MyEnumerator : public Enumerator<Pair> {
private:
	SeqInFileEnumerator<Pair> *fenor;
	Pair curr;
	bool End;
public:
	MyEnumerator(string input) {
		try	{
			fenor = new SeqInFileEnumerator<Pair>(input);
		}
		catch (SeqInFileEnumerator<Pair>::Exceptions){
			cerr << "Nem letezo file!";
			exit(1);
		}
	}
	~MyEnumerator() {
		delete fenor;
	}
	void first() {
		fenor->first();
		next();
	}
	void next();
	bool end() const {
		return End;
	}
	Pair current() const { return curr; }
};

void MyEnumerator::next() {
	End = fenor->end();
	if (!End) {
		curr.accoutNumber = fenor->current().accoutNumber;
		InnerSummation is(fenor->current().accoutNumber);
		is.addEnumerator(fenor);
		is.run();
		curr.balance = is.result();
	}
}

class OutputSummation : public Summation<Pair, ofstream> {
private:
	void add(const Pair &pair) { *_result << pair; }
public:
	OutputSummation(ofstream *output) : Summation<Pair, ofstream>(output) { }
};

#endif // CLASSES_HPP_INCLUDED
