#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Functions.c"

int main()
{
    char board1[10][10]; //declaring and initializing a first 10x10 board with zeros
    //char board2[10][10] = {0}; //declaring and initializing a second 10x10 board with zeros

    initialise_board(board1);
    print_board(board1);
    rules();
    set_board(board1);
    print_board(board1);
    return 0;
}
