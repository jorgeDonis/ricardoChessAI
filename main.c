#include <stdlib.h>
#include "chess_types.h"
#include "startup_chess.h"
#include "chess_gui.h"
#include "curses.h"

int main()
{
    game_state* initial_state = init();
    init_screen();
    print_state(initial_state);
    free_state(initial_state);
    getch();
    endwin();
    exit(0);
}