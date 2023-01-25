#pragma once //WTF?

class Particle {
public:
	Particle() {
		y = x = 0;
		icon = ' ';
	}

	Particle(int y, int x, chtype ch) {
		this->y = y;
		this->x = x;
		this->icon = ch;
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	chtype get_icon() {
		return icon;
	}

protected:
	int x, y;
	chtype icon;
};
