#pragma once
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

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
		mvwaddch(board_win, y, x+1, ch); 
	}

	chtype get_input() {
		return wgetch(board_win);
	}

	void add_border() {
		box(board_win, 0, 0);
	}

	void next_empty(int &y, int &x) {
		while(mvwinch(board_win, y = rand() % height, x = 1 + 2 * (rand() % (width / 2))) != ' ');
	}

	chtype get_char_at(int y, int x) {
		return mvwinch(board_win, y, x);
	}

	void clear() {
		wclear(board_win);
		add_border();
	}

	void refresh() {
		wrefresh(board_win);
	}


private:
	int height, width;
	WINDOW *board_win;

	void construct(int height, int width) {
		this->height = height;
		this->width = width;
		int x_max, y_max;
		getmaxyx(stdscr, y_max, x_max);
		srand(time(NULL));

		board_win = 
			newwin(height, width,
					y_max/2 - height/2,
					x_max/2 - width/2);
	}
};
