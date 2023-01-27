all: main

main: main.cpp src/*
	mkdir build
	g++ main.cpp -lncurses -o build/snake
