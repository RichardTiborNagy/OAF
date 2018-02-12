#include "animal.h"

void Fish::change(char &mood) {
	if (!alive()) return;
	switch (mood) {
	case 'j': vim += 1; break;
	case 'a': vim -= 3; break;
	case 'r': vim -= 5; break;
	default: break;
	}
	if (vim > 100) vim = 100;
}

void Bird::change(char &mood) {
	if (!alive()) return;
	switch (mood) {
	case 'j': vim += 2; break;
	case 'a': vim -= 1; break;
	case 'r': vim -= 3; break;
	default: break;
	}
	if (vim > 100) vim = 100;
}

void Dog::change(char &mood) {
	if (!alive()) return;
	switch (mood) {
	case 'j': vim += 3; break;
	case 'a': vim += 3; break;
	case 'r': vim -= 10; break;
	default: break;
	}
	if (vim > 100) vim = 100;
}
