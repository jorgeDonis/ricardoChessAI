COMPILER = g++ -Wall -g -std=gnu++17

main: main.c chess_types.h startup_chess.h
	$(COMPILER) main.c -o main