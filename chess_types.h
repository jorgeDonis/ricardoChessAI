#ifndef __CHESS_TYPES__
#define __CHESS_TYPES__


enum piece_type {rook, knight, bishop, queen, king, pawn};

struct piece
{
    piece_type type;
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

#endif