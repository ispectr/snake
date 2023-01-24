#pragma once //WTF?

class Board {
public:
	Board(int height, int width) {
		int x_max, y_max;
		getmaxyx(stdscr, y_max, x_max);

		WINDOW *board_win = 
			newwin(height, width,
					y_max/2 - height/2,
					x_max/2 - width/2);

		box(board_win, 0, 0);
		wrefresh(board_win);
	}

private:
	WINDOW *board_win;
	int height, width;
};
