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
	
	SnakeGame game(ROWS, COLS);
	
	while(! game.is_over()) {
		game.process_input();
		game.update_state();
		game.redraw();
	}

	getch();
	endwin();

	return 0;
}
