#pragma once
#include <ncurses.h>
#include "particle.hpp"

class Apple : public Particle{
public:
	Apple(int y, int x) {
		this->y = y;
		this->x = x;
		this->icon = 'A';
	}
};
