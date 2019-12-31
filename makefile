COMPILER = g++ -Wall -g -std=gnu++17 -lncurses

main: main.c chess_types.o chess_gui.o startup_chess.o chess_logic.o
	$(COMPILER) startup_chess.o chess_gui.o chess_types.o chess_logic.o main.c -o main

startup_chess.o: startup_chess.h startup_chess.c
	$(COMPILER) -c startup_chess.c

chess_gui.o: chess_gui.h chess_gui.c chess_types.o
	$(COMPILER) -c chess_gui.c

chess_types.o: chess_types.h chess_types.c
	$(COMPILER) -c chess_types.c

chess_logic.o: chess_logic.h chess_logic.c chess_types.o
	$(COMPILER) -c chess_logic.c

clean:
	rm *.o

