#pragma once 
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#include "board.hpp"
#include "particle.hpp"
#include "apple.hpp"
#include "empty.hpp"
#include "snake.hpp"
#include "scoreboard.hpp"

class SnakeGame {
public:
	SnakeGame(int height, int width) {
		board = Board(height, width);
		int sb_row = board.get_start_row() + height;
		int sb_col = board.get_start_col();
		scoreboard = Scoreboard(width, sb_row, sb_col);
		initialize();
	}

	~SnakeGame() {
		delete apple;
	}

	void initialize() {
		apple = NULL;
		score = 0;
		game_over = false;

		board.initialize();
		scoreboard.initialize(score);
		snake.set_direction(DOWN);
		
		// spawn snake
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
		case KEY_UP: case 'w': 
		case 'k':
			snake.set_direction(UP);
			break;

		case KEY_DOWN: case 's': 
		case 'j':
			snake.set_direction(DOWN);
			break;

		case KEY_RIGHT: case 'd': 
		case 'l':
			snake.set_direction(RIGHT);
			break;

		case KEY_LEFT: case 'a': 
		case 'h':
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
		scoreboard.refresh();
	}

	bool is_over() {
		return game_over;
	}

	int get_score() {
		return score;
	}

private:
	Apple *apple;
	Snake snake;
	Board board;
	Scoreboard scoreboard;
	int score;
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
		score += 100;
		scoreboard.update_score(score);
		delete apple;
		apple = NULL;
	}
};
