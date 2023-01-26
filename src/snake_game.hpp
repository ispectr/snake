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

		handle_next_piece(SnakePiece(1, 1));
		handle_next_piece(snake.next_head());
		handle_next_piece(snake.next_head());
		snake.set_direction(RIGHT);
		handle_next_piece(snake.next_head());

		if(apple == NULL) {
			create_apple();
		}	
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
		handle_next_piece(snake.next_head());
		if (apple == NULL) {
			create_apple();
		}
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

	void create_apple() {
		int y, x;
		board.next_empty(y, x);
		apple = new Apple(y, x);
		board.add(*apple);
	}
	
	void handle_next_piece(SnakePiece next) {
		if(apple != NULL) {
			switch(board.get_char_at(next.get_y(), next.get_x())) {
			case 'A':
				destroy_apple();
				break;

			case ' ': {
				int empty_row = snake.tail().get_y();
				int empty_col = snake.tail().get_x();
				board.add(Empty(empty_row, empty_col));
				snake.remove_piece();
				break;
			}

			default:
				game_over = true;
				break;

			}
		}

		board.add(next);
		snake.add_piece(next);
	}
	
	void destroy_apple() {
		delete apple;
		apple = NULL;
	}
};
