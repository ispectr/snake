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
	//keypad(stdscr, true);
	timeout(300);

	chtype input;	
	SnakeGame game(ROWS, COLS);

	while(! game.is_over()) {
		input = getch();
		game.process_input(input);
		game.update_state();
		game.redraw();
	}

	getch();
	endwin();

	printf("Game over! Your last score: %d points!\n", game.get_score());
	return 0;
}
