#pragma once 
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#include "board.hpp"
#include "particle.hpp"
#include "apple.hpp"
#include "empty.hpp"

class SnakeGame {
public:
	SnakeGame(int height, int width) {
		board = Board(height, width);
		board.initialize();
		game_over = false;
		srand(time(NULL));
	}

	void process_input() {
		chtype input = board.get_input();
	}

	void update_state() {
		int x, y;
		board.next_empty(y, x);

		if(apple != NULL) 
			board.add(Empty(apple->get_y(), apple->get_x()));

		apple = new Apple(y, x);
		board.add(*apple);
		board.add(Particle(3, 5, '@'));
		board.refresh();
	}

	void redraw() {
		board.refresh();
	}

	bool is_over() {
		return game_over;
	}

private:
	Apple *apple;
	Board board;
	bool game_over;
};
