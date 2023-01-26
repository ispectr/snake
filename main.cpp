#include <ncurses.h>

#include "src/board.hpp"
#include "src/snake_game.hpp"
#include "src/particle.hpp"

#define ROWS 20
#define COLS 20 * 2

int main(int argc, char **argv) {
	initscr();
	refresh();
	noecho();
	curs_set(0);
	
	SnakeGame game(ROWS, COLS);
	chtype input;	
	timeout(500);
	while(! game.is_over()) {
		input = getch();
		game.process_input(input);
		game.update_state();
		game.redraw();
	}

	getch();
	endwin();

	return 0;
}
