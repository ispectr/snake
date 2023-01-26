#pragma once
#include <ncurses.h>
#include <queue>

#include "particle.hpp"

enum Direction {
	UP, DOWN, LEFT, RIGHT
};



class SnakePiece : public Particle {
public:
	SnakePiece() {
		this->x = this->y = 0;
		this->icon = '#';
	}

	SnakePiece(int y, int x) {
		this->x = x;
		this->y = y;
		this->icon = '#';
	}
};

class Snake {
public:
	Snake() {
		cur_direction = DOWN;
	}

	void add_piece(SnakePiece piece) {
		prev_pieces.push(piece);
	}

	void remove_piece() {
		prev_pieces.pop();
	}

	SnakePiece tail() {
		return prev_pieces.front();
	}

	SnakePiece head() {
		return prev_pieces.back();
	}

	Direction get_direction() {
		return cur_direction;
	}

	void set_direction(Direction new_direction) {
		cur_direction = new_direction;
	}

	SnakePiece next_head() {
		int row = head().get_y();
		int col = head().get_x();

		switch (cur_direction) {
		case DOWN:
			row++;
			break;
		case UP:
			row--;
			break;
		case LEFT:
			col--;
			break;
		case RIGHT:
			col++;
			break;
		}

		return SnakePiece(row, col);
	}

private:
	std::queue<SnakePiece> prev_pieces;
	Direction cur_direction;
};
