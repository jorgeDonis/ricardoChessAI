#include "chess_types.h"

void free_state(game_state* state)
{
    if (state != NULL)
    {
        if (state->board != NULL)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                    free(state->board[i][j].piece_on_top);
                free(state->board[i]);
            }
            free(state->board);
        }
        if (state->en_passant_pawn != NULL)
            free(state->en_passant_pawn);
    }
}