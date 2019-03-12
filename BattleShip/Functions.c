#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

void initialise_board(char board[][10]){
    int i, j;

    for(i = 0 ; i < 10 ; i++){
        for(j = 0 ; j < 10 ; j++){
            board[i][j] = '0';
        }
    }
}
void print_board(char board[][10]){
    int i, j;

    for(i = 0 ; i < 10 ; i++){ //printing the board
        for(j = 0 ; j < 10 ; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void rules(){
    printf("Printing the rules.\n");
}

char set_board(char board[][10]){
    printf("We are going to set your game board.\n");

    int i, j, k, n;

    for(i = 1 ; i < 5 ; i++){
        printf("Enter coordinates for ship number %d: ", i);
        n = scanf("%d %d", &j, &k);
        if(n != 2){ // tout le if suivant sert à sécuriser l'input (s'assurer qu'on a bien 2 int) mais ca fonctionne pas ca fait une boucle infinie
           do{
                printf("Format error. Please try again: ");
                n = scanf("%d %d", &j, &k);
            }while(n != 2);
        }
        board[j][k] = 'S'; //S = ship, mais on voit pas très bien on changera plus tard
    }
    return (**board);
}
