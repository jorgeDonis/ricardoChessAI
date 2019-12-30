#include "startup_chess.h"

square** init_board()
{
    square** board = (square**) malloc(sizeof(square) * 8);
    for (unsigned i = 0; i < 8; i++)
        board[i] = (square*) malloc(sizeof(square) * 8);
    for (unsigned i = 0; i < 8; i++)
    {
        for (unsigned j = 0; j < 8; j++)
        {
            board[i][j].x = 7 - i;
            board[i][j].y = j;
            board[i][j].piece_on_top = NULL;
        }
    }
    for (unsigned i = 0; i < 8; i++)
    {
        piece* blackpiece = (piece*) malloc(sizeof(piece));
        blackpiece->color = 0;
        blackpiece->type = initial_layout[i];
        board[0][i].piece_on_top = blackpiece;
        piece* whitepiece = (piece*) malloc(sizeof(piece));
        whitepiece->color = 1;
        whitepiece->type = initial_layout[i];
        board[7][i].piece_on_top = whitepiece;
        piece* blackpawn = (piece*) malloc(sizeof(piece));
        blackpawn->color = 0;
        blackpawn->type = pawn;
        board[1][i].piece_on_top = blackpawn;
        piece* whitepawn = (piece*) malloc(sizeof(piece));
        whitepawn->color = 1;
        whitepawn->type = pawn;
        board[6][i].piece_on_top = whitepawn;
    }
    return board;
}

game_state* init()
{
    game_state* state = (game_state*) malloc (sizeof(game_state));
    state->castle_black = false;
    state->castle_white = false;
    state->en_passant_pawn = NULL;
    state->board = init_board();
    return state;
}

