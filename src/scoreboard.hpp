#pragma once

class Scoreboard {
public:
	Scoreboard() {
	}

	Scoreboard(int width, int y, int x) {
		score_win = newwin(1, width, y, x);
	}

	void initialize(int initial_score) {
		clear();
		update_score(initial_score);
		mvwprintw(score_win, 0, 0, "Score:");
		refresh();
	}

	void update_score(int score) {
		mvwprintw(score_win, 0, score_win->_maxx - 10, "%11llu", score);
	}

	void clear() {
		wclear(score_win);
	}

	void refresh() {
		wrefresh(score_win);
	}

private:
	WINDOW *score_win;
};

