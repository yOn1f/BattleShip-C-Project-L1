#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

void initialise_board(char board[][10]){
    int i, j;

    for(i = 0 ; i < 10 ; i++){
        for(j = 0 ; j < 10 ; j++){
            board[i][j] = '*';
        }
    }
}
void print_board(char board[][10]){
    int i, j;

    printf("  ");
    for(i = 0 ; i < 10 ; i++)
        printf("%d ", i);
    printf("\n");
    for(i = 0 ; i < 10 ; i++){//printing the board
        printf("%d ", i);
        for(j = 0 ; j < 10 ; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void rules(){
    printf("\n=========================\n");
    printf("   Here are the rules.");
    printf("\n=========================\n");
}
void getValidCoordinates(int* x1, int* y1, int* x2, int* y2){ //get coordinates with a valid format (int)
    int a, b;

    while(a != 2 || b != 2){
        printf("Enter the coordinates of the first extremity of the boat: ");
        a = scanf(" %d %d", x1, y1);
        printf("Enter the the coordinates of the second extremity: ");
        b = scanf(" %d %d", x2, y2);
        if(a != 2)
            printf("There is a format error in the coordinates of the first extremity. Please make sure to enter 2 integers and nothing else.\n");
        else if(b != 2)
            printf("There is a format error in the coordinates of the second extremity. Please make sure to enter 2 integers and nothing else.\n");
    }
}
int validLocation(char board[][10], int X, int Y){
    return(board[X][Y] == '*');
}
int validOrientation(int X1, int Y1, int X2, int Y2){
    return(X1 == X2 || Y1 == Y2);
}
int valideSize(int size, int X1, int Y1, int X2, int Y2){
    /*printf("size = %d\n", size);
    printf("abs(Y2 - Y1) = %d\n", abs(Y2 - Y1));
    printf("abs(X2 - X1) = %d\n", abs(X2 - X1));*/
    if(X1 == X2)
        return(abs(Y2 - Y1) == size - 1);
    else if(Y2 == Y1)
        return(abs(X2 - X1) == size - 1);
    return 0;
}
int validCompleteShip(char board[][10], int X1, int Y1, int X2, int Y2, char c){
    int i, remaining; //remaining is the nbr of location between the two extremities --> nbr of locations left to modify = remaining

    remaining = 0;
    if(X1 == X2){
        remaining = abs(Y2 - Y1);
        for(i = Y1 ; i < remaining ; i++)
            if(!validLocation(board, X1, Y1 +i))
                return 0;
    }
    else if(Y1 == Y2){
        remaining = abs(X2 - X1);
        for(i = X1 ; i < remaining ; i++)
            if(!validLocation(board, X1 + i, Y1))
                return 0;
            modify(board, X1 + i, Y1, c);
    }
    return 1;
}
void modify(char board[][10], int X, int Y, char c){
    board[X][Y] = c;
}
void set_ship(char board[][10], int size, char c){
    int x1, y1, x2, y2, i, remaining; //coordinates of extremities 1 and 2

    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    do{
            getValidCoordinates(&x1, &y1, &x2, &y2);
            if(!validLocation(board, x1, y1) || !validLocation(board, x2, y2))
                printf("One of these location is already taken. Please try again.\n");
            if(!validOrientation(x1, y1, x2, y2))
                printf("You can place your ship either vertically or horizontally. Please try again.\n");
            if(!valideSize(size, x1, y1, x2, y2))
                printf("The size of this ship is %d. Please try again.\n", size);
            if(!validCompleteShip(board, x1, y1, x2, y2, c))
                printf("You can't place your boat here. Please try again.\n");
    }while(validLocation(board, x1, y1) != 1 || validLocation(board, x2, y2) != 1 || validOrientation(x1, y1, x2, y2) != 1 || valideSize(size, x1, y1, x2, y2) != 1 || validCompleteShip(board, x1, y1, x2, y2, c) != 1);
    if(x1 == x2){
        remaining = abs(y2 - y1); //absolute value of y2 - y1
        for(i = 0 ; i < remaining ; i++)
            modify(board, x1, y1 + i, c);
    }
    else if(y1 == y2){
        remaining = abs(x2 - x1); //absolute value of x2 - x1
        for(i = 0 ; i < remaining ; i++)
            modify(board, x1 + i, y1, c);
    }
    print_board(board);
}
