#pragma once //WTF?
#include <ncurses.h>
#include "board.hpp"
#include "particle.hpp"

class SnakeGame {
public:
	SnakeGame(int height, int width) {
		board = Board(height, width);
		board.initialize();
		game_over = false;
	}

	void process_input() {
		chtype input = board.get_input();
	}

	void update_state() {
	}

	void redraw() {
		board.refresh();
	}

	bool is_over() {
		return game_over;
	}

private:
	Board board;
	bool game_over;
};
