#ifndef ANIMAL
#define ANIMAL

#include <string>

class Animal {
protected:
	std::string name;
	int vim;
	Animal(std::string n, int v) : name(n), vim(v) {}
public:
	std::string getName() const { return name; }
	int getVim() const { return vim; }
	bool alive() const { return vim > 0; }
	virtual void change(char &mood) = 0;
	virtual ~Animal() {}
};

class Fish : public Animal {
public:
	Fish(std::string n, int v) : Animal(n,v) {}
	void change(char &mood);
};

class Bird : public Animal {
public:
	Bird(std::string n, int v) : Animal(n, v) {}
	void change(char &mood);
};

class Dog : public Animal {
public:
	Dog(std::string n, int v) : Animal(n, v) {}
	void change(char &mood);
};

#endif
