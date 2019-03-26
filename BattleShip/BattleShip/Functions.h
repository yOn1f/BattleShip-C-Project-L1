#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void    initialise_board(char board[][10]);
void    print_board(char board[][10]);
void    rules();
void    getValidCoordinates(int* ptrJ, int* ptrK, int* ptrL, int* ptrM);
int     validOrientation(int j, int k, int l, int m);
int     validLocation(char board[][10], int X, int Y);
int     valideSize(int size, int ptrJ, int ptrK, int ptrL, int ptrM);
void    modify(char board[][10], int* ptrJ, int* ptrK, char c);
void    set_ship(char board[][10], int size, char c);
#endif // FUNCTIONS_H_INCLUDED
