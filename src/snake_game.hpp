#pragma once 
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#include "board.hpp"
#include "particle.hpp"
#include "apple.hpp"
#include "empty.hpp"
#include "snake.hpp"

class SnakeGame {
public:
	SnakeGame(int height, int width) {
		board = Board(height, width);
		initialize();
	}

	~SnakeGame() {
		delete apple;
	}

	void initialize() {
		apple = NULL;

		board.initialize();
		game_over = false;
		snake.set_direction(DOWN);

		SnakePiece next = SnakePiece(1, 1);
		board.add(next);
		snake.add_piece(next);

		next = snake.next_head();
		board.add(next);
		snake.add_piece(next);

		next = snake.next_head();
		board.add(next);
		snake.add_piece(next);
	
	}

	void process_input(int input) {
		switch (input) {
		case KEY_UP:
		case 'w':
			snake.set_direction(UP);
			break;
		case KEY_DOWN:
		case 's':
			snake.set_direction(DOWN);
			break;
		case KEY_RIGHT:
		case 'd':
			snake.set_direction(RIGHT);
			break;
		case KEY_LEFT:
		case 'a':
			snake.set_direction(LEFT);
			break;
		default:
			break;
		}
	}

	void update_state() {
		if(apple == NULL) {
			int y, x;
			board.next_empty(y, x);
			apple = new Apple(y, x);
			board.add(*apple);
		}

		SnakePiece next = snake.next_head();
		if(apple->get_x() != next.get_x() || apple->get_y() != next.get_y()) {
			int empty_row = snake.tail().get_y();
			int empty_col = snake.tail().get_x();
			board.add(Empty(empty_row, empty_col));
			snake.remove_piece();
		}

		board.add(next);
		snake.add_piece(next);
	}

	void redraw() {
		board.refresh();
	}

	bool is_over() {
		return game_over;
	}

private:
	Apple *apple;
	Snake snake;
	Board board;
	bool game_over;
};
