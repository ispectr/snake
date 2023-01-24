#include <ncurses.h>
#include "src/board.hpp"
#define ROWS 20
#define COLS 20 * 2

int main(int argc, char **argv) {
	initscr();
	refresh();
	noecho();

	Board board(ROWS, COLS);
	board.initialize();

	board.add_at(5, 5, '%');
	board.refresh();

	getch();
	endwin();

	return 0;
}
