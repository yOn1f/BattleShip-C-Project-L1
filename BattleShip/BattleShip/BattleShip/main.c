#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int main()
{
    char board1[10][10]; //board1 is the player game board
    char board2[10][10]; //board2 is the computer game board

    initialise_board(board1);
    print_board(board1);
    initialise_board(board2);
    rules();
    set_player_gameboard(board1);
    set_computer_gameboard(board2);
    return 0;
}
