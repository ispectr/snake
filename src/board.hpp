#pragma once //WTF?
#include <ncurses.h>
#include "particle.hpp"

class Board {
public:
	Board() {
		construct(0, 0);
	}
	
	Board(int height, int width) {
		construct(height, width);
	}

	void initialize() {
		clear();
		refresh();
	}

	void add(Particle particle) {
		add_at(particle.get_y(), particle.get_x(), particle.get_icon());
	}

	void add_at(int y, int x, chtype ch) {
		mvwaddch(board_win, y, x, ch);
	}

	chtype get_input() {
		return wgetch(board_win);
	}

	void add_border() {
		box(board_win, 0, 0);
	}

	void clear() {
		wclear(board_win);
		add_border();
	}

	void refresh() {
		wrefresh(board_win);
	}


private:
	WINDOW *board_win;

	void construct(int height, int width) {
		int x_max, y_max;
		getmaxyx(stdscr, y_max, x_max);

		board_win = 
			newwin(height, width,
					y_max/2 - height/2,
					x_max/2 - width/2);
	}
};
