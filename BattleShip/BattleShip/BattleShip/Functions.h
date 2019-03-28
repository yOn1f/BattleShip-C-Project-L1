#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void    initialise_board(char board[][10]);
void    print_board(char board[][10]);
void    rules();
void    getValidCoordinates(int* x1, int* y1, int* x2, int* y2);
int     validOrientation(int X1, int Y1, int X2, int Y2);
int     validLocation(char board[][10], int X, int Y);
int     valideSize(int size, int X1, int Y1, int X2, int Y2);
int     validCompleteShip(char board[][10], int X1, int Y1, int X2, int Y2, char c);
void    modify(char board[][10], int X, int Y, char c);
void    set_ship(char board[][10], int size, char c);
void    set_computer_gameboard(char board[][10]);
#endif // FUNCTIONS_H_INCLUDED
