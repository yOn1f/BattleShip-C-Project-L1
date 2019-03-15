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
int validOrientation(char o){
    return (o != 'V' && o != 'v' && o != 'H' && o != 'h');
}
int validLocation(char loc){
    return(loc != '*');
}
void modify(char board[][10], int j, int k, char c){
        board[j][k] = c;
}
char set_battleship(char board[][10]){
    int a, b, j, k, l, m, line1, line2, column1, column2, test1, test2;

    test1 = test2 = 0;
    printf("Next, you have one battleship.\n");
    do{
        if(!test1 || !test2)
            printf("You can't place your battleship here. Please try again.\n");
        printf("Enter the coordinates of the first extremity of the battleship: "); //putting the battleship on the game board
        a = scanf("%d %d", &j, &k);
        printf("Enter the the coordinates of the second extremity: ");
        b = scanf("%d %d", &l, &m);
        if(a != 2){ //checking first input is actually 2 int and nothing else
            printf("Format error for the coordinates of the first extremity. Please try again: ");
            a = scanf("%d %d", &j, &k);
        }
        else if(b != 2){ //checking second input is actually 2 int and nothing else
            printf("Format error for the coordinates of the second extremity. Please try again: ");
            b  = scanf("%d %d", &l, &m);
        }
        if(k == m){
            test1 = validLocation(board[j + 1][k]);
            test2 = validLocation(board[j + 2][k]);
        }
        else if(j == m){
            test1 = validLocation(board[j][k + 1]);
            test2 = validLocation(board[j][k + 2]);
        }
    }while((a != 2 || b != 2) && (!test1 || !test2));
    do{ //checking if the location chosen is empty and actually in the board
        if(!validLocation(board[j][k])){
            printf("The location chosen for the first extremity is not empty. Please try again: ");
            scanf("%d %d", &j, &k);
        }
        else if(!validLocation(board[l][m])){
            printf("The location chosen for the second extremity is not empty. Please try again: ");
            scanf("%d %d", &l, &m);
        }
    }while(!validLocation(board[j][k])||!validLocation(board[l][m]));
    modify(board, j, k, 'S');
    modify(board, l, m, 'S');
    if(k == m){ //placing the battleship on the game board, first if the user wants it vertical
        column1 = column2 = k;
        line1 = j + 1;
        line2 = j + 2;
    }
    else if(j == l){ //secondly if the user wants is horizontal
        line1 = line2 = j;
        column1 = k + 1;
        column2 = k + 2;
    }
    modify(board, line1, column1, 'S');
    modify(board, line2, column2, 'S');
    print_board(board);
    return (**board);
}
char set_cruiser(char board[][10]){
    int n, j, k, line1, line2, column1, column2;
    char o;

    printf("Next, you have one cruiser.\n");
    printf("Enter the coordinate of the center of the cruiser: "); //Putting the cruiser on the game board
    do{ //checking input is actually 2 int and nothing else
        n = scanf("%d %d", &j, &k);
        if(n != 2){
            printf("Format error. Please try again: ");
            n = scanf("%d %d", &j, &k);
        }
    }while(n != 2);
    printf("Now what is its orientation: type H for horizontal or V for vertical: ");
   do{ //checking orientation is valid
        scanf(" %c", &o);
        if(!validOrientation(o)){
            printf("Your cruiser can be placed either vertically or horizontally, nothing else. Please try again: ");
            scanf(" %c", &o);
        }
    }while(!validOrientation(o));
    modify(board, j, k, 'Y');
    if(o == 'V' || o == 'v'){ //placing the cruiser on the game board, first if the user wants it vertical
        column1 = column2 = k;
        line1 = j - 1;
        line2 = j + 1;
    }
    else{ //secondly if the user wants it horizontal
        line1 = line2 = j;
        column1 = k - 1;
        column2 = k + 1;
    }
    modify(board, line1, column1, 'Y');
    modify(board, line2, column2, 'Y');
    print_board(board);
    return (**board);
}
char set_submarine(char board[][10]){
    int n, j, k, line1, line2, column1, column2;
    char o;

    printf("Next, you have one submarine.\n");
    printf("Enter the coordinate of the center of the submarine: "); //Putting the submarine on the game board
    n = scanf("%d %d", &j, &k);
    while(n != 2 || board[j][k] != '*'){
        if(n != 2){ //checking input is actually 2 int and nothing else
            printf("Format error. Please try again: ");
            n = scanf("%d %d", &j, &k);
        }
        if(!validLocation(board[j][k])){ //checking the location chosen by the user is free
            printf("This place is already taken. Please try again: ");
            n = scanf("%d %d", &j, &k);
        }
    }
    printf("Now what is its orientation: type H for horizontal or V for vertical: ");
    do{ //checking input says vertical or horizontal and nothing else
        scanf(" %c", &o);
        if(!validOrientation(o)){
            printf("Your submarine can be placed either vertically or horizontally, nothing else. Please try again: ");
            scanf(" %c", &o);
        }
    }while(!validOrientation(o));
    modify(board, j, k, 'C'); // modifying the value of board[j][k]
    if(o == 'V' || o == 'v'){ //placing the submarine on the game board, first if the user wants it vertical
        column1 = column2 = k;
        line1 = j - 1;
        line2 = j + 1;
    }
    else{ //secondly if the user wants it horizontal
        line1 = line2 = j;
        column1 = k - 1;
        column2 = k + 1;
    }
    modify(board, line1, column1, 'C');//These 2 calls modify the value of the 2 extremities of the boat
    modify(board, line2, column2, 'C');
    print_board(board);
    return (**board);
}
char set_aircraft_carrier(char board[][10]){
    int n, j, k, line1, line2, line3, line4, column1, column2, column3, column4;
    char o;

    printf("Next you have one aircraft carrier. \n");
    printf("Enter the coordinate of the center of the aircraft carrier : "); //putting the aircraft carrier on the game board
    n = scanf("%d %d", &j, &k);
    while(n != 2 || board[j][k] != '*'){ //checking input is actually 2 int and nothing else
            if(n != 2){
                printf("Format error. Please try again: ");
                n = scanf("%d %d", &j, &k);
            }
            if(!validLocation(board[j][k])){ //checking the location chosen by the user is free
                printf("This place is already taken. Please try again: ");
                n = scanf("%d %d", &j, &k);
            }
    }
    printf("Now what is its orientation: type H for horizontal or V for vertical: ");
    do{
        scanf(" %c", &o);
        if(!validOrientation(o)){ //checking input says vertical or horizontal and nothing else
            printf("Your submarine can be placed either vertically or horizontally, nothing else. Please try again: ");
            scanf(" %c", &o);
        }
    }while(!validOrientation(o));
    modify(board, j, k, 'A');
    if(o == 'V' || o == 'v'){ //placing the aircraft carrier on the game board, first if the user wants it vertical
        column1 = column2 = column3 = column4 = k;
        line1 = j - 2;
        line2 = j - 1;
        line3 = j + 1;
        line4 = j + 2;
    }
    else{ //secondly if the user wants it horizontal
        line1 = line2 = line3 = line4 = j;
        column1 = k - 2;
        column2 = k - 1;
        column3 = k + 1;
        column4 = k + 2;
    }
    modify(board, line1, column1, 'A');
    modify(board, line2, column2, 'A');
    modify(board, line3, column3, 'A');
    modify(board, line4, column4, 'A');
    print_board(board);
    return (**board);
}
char set_destroyer(char board[][10]){
    int a, b, j, k, l, m;

    printf("Next, you have one destroyer.\n");
    do{
        printf("Enter the coordinates of one extremity of the destroyer: "); //putting the destroyer on the game board
        a = scanf("%d %d", &j, &k);
        printf("Enter the the coordinates of the second extremity: ");
        b = scanf("%d %d", &l, &m);
        if(a != 2){ //checking first input is actually 2 int and nothing else
            printf("Format error for the coordinates of the first extremity. Please try again: ");
            a = scanf("%d %d", &j, &k);
        }
        else if(b != 2){ //checking second input is actually 2 int and nothing else
            printf("Format error for the coordinates of the second extremity. Please try again: ");
            b  = scanf("%d %d", &l, &m);
        }
    }while(a != 2 || b != 2);
    do{ //checking if the location chosen is empty and actually in the board
        if(!validLocation(board[j][k])){
            printf("The location chosen for the first extremity is not empty. Please try again: ");
            scanf("%d %d", &j, &k);
        }
        else if(!validLocation(board[l][m])){
            printf("The location chosen for the second extremity is not empty. Please try again: ");
            scanf("%d %d", &l, &m);
        }
    }while(!validLocation(board[j][k])||!validLocation(board[l][m]));
    modify(board, j, k, 'D');
    modify(board, l, m, 'D');
    print_board(board);
    return (**board);
}
