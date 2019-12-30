#ifndef __STARTUP_CHESS__
#define __STARTUP_CHESS__

#include "chess_types.h"
#include <stdlib.h>

static const piece_type initial_layout[8] = {rook, knight, bishop, queen, king, bishop, knight, rook};

square** init_board();
game_state* init();

#endif