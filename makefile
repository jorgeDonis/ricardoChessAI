COMPILER = g++ -Wall -g

main: main.c chess_types.h
	$(COMPILER) main.c -o main