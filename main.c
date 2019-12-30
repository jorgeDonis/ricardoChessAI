#include <stdlib.h>
#include "chess_types.h"
#include "startup_chess.h"

int main()
{
    game_state* initial_state = init();
    free_state(initial_state);
    exit(0);
}