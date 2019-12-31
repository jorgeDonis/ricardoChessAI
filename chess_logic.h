#ifndef __CHESS_LOGIC__
#define __CHESS_LOGIC__

#include "chess_types.h"

//This file handles the logic of the chess game. What moves can be made and so forth.
//We suppose ricardo always plays as black

#define AN_STR_LEN 6
#define MAX_NODES_MEM 100


struct Movement
{
    short unsigned x0, y0, x1, y1;
    char* algebraic_notation;
};

Movement get_movement(game_state* origin, game_state* ending);

game_state** expand_state(game_state* origin);


#endif