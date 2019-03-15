#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
void    initialise_board(char board[][10]);
void    print_board(char board[][10]);
void    rules();
int     validOrientation(char o);
int     validLocation(char loc);
void    modify(char board[][10], int j, int k, char c);
char    set_battleship(char board[][10]);
char    set_cruiser(char board[][10]);
char    set_submarine(char board[][10]);
char    set_aircraft_carrier(char board[][10]);
char    set_destroyer(char board[][10]);
#endif // FUNCTIONS_H_INCLUDED
