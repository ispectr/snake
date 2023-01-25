all: main

main: main.cpp src/board.hpp src/snake_game.hpp
	g++ main.cpp -lncurses -o main
