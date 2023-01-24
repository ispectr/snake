#include <ncurses.h>
#include "src/board.hpp"
#define ROWS 20
#define COLS 20 * 2

int main(int argc, char **argv) {
	initscr();
	refresh();
	noecho();
/*
	int x_max, y_max;
	getmaxyx(stdscr, y_max, x_max);

	
	WINDOW *board_win = newwin(ROWS, COLS,
			y_max/2 - ROWS/2,
			x_max/2 - COLS/2);
	box(board_win, 0, 0);
	wrefresh(board_win);
*/
	Board board(ROWS, COLS);

	getch();
	endwin();

	return 0;
}
