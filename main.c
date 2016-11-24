// yashodhan kulkarni // gurtaj atwell(partner)
// 15 may 2015 4:30 am
// homework 4 // connectn game code

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "connectn.h"

int main(int argc,char* argv[]){ // allows user to insert arguments included in the executable

    if(argc < 4){ // will not work if the user enters anything other than 3 arguments // '4' because name is considered as an argument
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    }
    
    else if(argc > 4){ // will not work if the user enters anything other than 3 arguments // '4' because name is considered as an argument
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");

    }

    else{ // if the user enters the correct number of arguments

        int numRows = atoi(argv[1]); // changes ASCII value of first argument (because 0th argument is the executable name)
        int numCols = atoi(argv[2]); // changes ASCII value of second argument 
        int numToWin = atoi(argv[3]); // changes ASCII value of third argument 
        char** board = NULL; // introduces board to the main function so that other functions called can use it

        create_board(&board,numRows,numCols); // creates
        print_board(board,numRows,numCols); // prints
        play_game(board,numRows,numCols,numToWin); // plays the game
        destroy_board(&board,numRows,numCols); // clears the board

    }

    return 0;
}



