#include "chess_gui.h"
#include <curses.h>

#define WHITE_OVER_WHITE 1
#define WHITE_OVER_BLACK 2
#define BLACK_OVER_BLACK 3
#define BLACK_OVER_WHITE 4

static const char PIECE_CHARACTERS[6] = {'r','n','b','Q','K','p'};

static unsigned CONSOLE_WIDTH, CONSOLE_HEIGHT;

void print_state(game_state* state)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            bool white_square = (((i + j) % 2) == 0);
            char piece_char;
            piece* piece = state->board[i][j].piece_on_top;
            if (piece == NULL)
            {
                piece_char = ' ';
                if (white_square)
                    attron(COLOR_PAIR(WHITE_OVER_WHITE));
                else
                    attron(COLOR_PAIR(BLACK_OVER_BLACK));
            }
            else 
            {
                piece_char = PIECE_CHARACTERS[piece->type];
                if (white_square)
                {
                    if (piece->color) //piece is white
                        attron(COLOR_PAIR(WHITE_OVER_WHITE));
                    else
                        attron(COLOR_PAIR(BLACK_OVER_WHITE));
                }
                else
                {
                    if (piece->color) //piece is white
                        attron(COLOR_PAIR(WHITE_OVER_BLACK));
                    else
                        attron(COLOR_PAIR(BLACK_OVER_BLACK));
                }
            }
            mvaddch(i + (CONSOLE_HEIGHT * 0.3), j + (CONSOLE_WIDTH * 0.45), piece_char);
        }
    }
    refresh();
}

void init_screen()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_YELLOW);
    init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(3, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    box(stdscr, ACS_VLINE, ACS_HLINE );
    getmaxyx(stdscr, CONSOLE_HEIGHT, CONSOLE_WIDTH);
    mvwprintw( stdscr, CONSOLE_HEIGHT / 10, CONSOLE_WIDTH * 0.35, "Ricardo: a simple chess engine");
}
