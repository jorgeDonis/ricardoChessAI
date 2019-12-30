#ifndef __CHESS_TYPES__
#define __CHESS_TYPES__

enum piece_type {rook, knight, bishop, queen, king, pawn};

struct piece
{
    piece_type type;
    //0 = black    1 = white
    bool color;
};

struct square
{
    short unsigned x, y;
    piece* piece_on_top;
};

struct game_state
{
    square** board;
    bool castle_white, castle_black;
    square* en_passant_pawn;
};

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

#endif