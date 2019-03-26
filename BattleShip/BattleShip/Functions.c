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
void getValidCoordinates(int* ptrJ, int* ptrK, int* ptrL, int* ptrM){ //get coordinates with a valid format (int)
    int a, b;

    a = b = 0;
    while(a != 2 || b != 2){
        printf("Enter the coordinates of the first extremity of the boat: ");
        a = scanf(" %d %d", ptrJ, ptrK);
        printf("Enter the the coordinates of the second extremity: ");
        b = scanf(" %d %d", ptrL, ptrM);
        if(a != 2)
            printf("There is a format error in the coordinates of the first extremity. Please make sure to enter 2 integers and nothing else.\n");
        else if(b != 2)
            printf("There is a format error in the coordinates of the second extremity. Please make sure to enter 2 integers and nothing else.\n");
    }
}
int validLocation(char board[][10], int X, int Y){
    return(board[X][Y] == '*');
}
int validOrientation(int J, int K, int L, int M){
    return(J == L || K == M);
}
int     valideSize(int size, int J, int K, int L, int M){
    return(abs(L - J) == size - 1 || abs(M - K) == size - 1);
}
void modify(char board[][10], int* ptrX, int* ptrY, char c){
    board[*ptrX][*ptrY] = c;
}
void set_ship(char board[][10], int size, char c){
    int j, k, l, m;
    int *ptrJ, *ptrK, *ptrL, *ptrM;

    ptrJ = &j;
    ptrK = &k;
    ptrL = &l;
    ptrM = &m;
    do{
            getValidCoordinates(ptrJ, ptrK, ptrL, ptrM);
            if(!validLocation(board, *ptrJ, *ptrK) || !validLocation(board, *ptrL, *ptrM))
                printf("One of these location is already taken. Please try again.\n");
            if(!validOrientation(*ptrJ, *ptrK, *ptrL, *ptrM))
                printf("You can place your ship either vertically or horizontally. Please try again.\n");
            if(!valideSize(size, *ptrJ, *ptrK, *ptrL, *ptrM))
                printf("The size of this ship is %d. Please try again.\n", size);
    }while(validLocation(board, *ptrJ, *ptrK) != 1 || validLocation(board, *ptrL, *ptrM) != 1 || validOrientation(*ptrJ, *ptrK, *ptrL, *ptrM) != 1 || valideSize(size, *ptrJ, *ptrK, *ptrL, *ptrM) != 1);
    modify(board, ptrJ, ptrK, 'S');
    modify(board, ptrL, ptrM, 'S');
    print_board(board);
}
