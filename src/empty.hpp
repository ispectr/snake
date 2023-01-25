#pragma once
#include <ncurses.h>
#include "particle.hpp"

class Empty : public Particle {
public:
	Empty(int y, int x) {
		this->x = x;
		this->y = y;
		this->icon = ' ';
	}
};

