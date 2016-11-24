// yashodhan kulkarni // gurtaj atwell(partner)
// 15 may 2015 4:30 am
// homework 4 // connectn game code


#include "connectn.h"

void create_board(char*** board,int numRows,int numCols){ // Dynamically allocates the elements in the array and initializes them to blank('*')

    const char blank = '*'; // default symbol of every element on the game board
    int i,j; // for loop indices

    *board = (char**)malloc(numRows *sizeof(char*)); // dynamically allocates every row of the board

    for(i = 0; i < numRows; ++i){//for each row
        (*board)[i] = (char*) malloc(numCols * sizeof(char)); // dynamically allocates every element in a row
    }

    for(i = 0; i < numRows; ++i){ // for each row
        for(j = 0; j < numCols; ++j){ // for each element
            (*board)[i][j] = blank; // initializes each element with a blank
        }
    }
    return;
} 

void destroy_board(char*** board,int numRows,int numCols){ // deallocates memory assigned to the board

    int i; // for loop index

    for(i = 0; i < numRows; ++i){ //for each row
        free((*board)[i]); // deallocates each row
    }
    free(*board); // deallocates the whole board
    *board = NULL; // makes sure that the board isn't valid anymore and is equal to NULL
    return;
}


void print_board(char** board,int numRows,int numCols){ //prints the board, including changes.
    
    int i,j; // for loop indices

    for(i = 0; i < numRows; ++i){
            
        printf("%d ",numRows - (i+1)); // prints the row numbers
        for(j = 0; j < numCols; ++j){ // prints the symbol assigned to each element in the row
            printf("%c ",board[i][j]);
        }
            
        printf("\n"); // prints new line after each row
    }
        
    printf("  "); // gives a space so that the column numbers are properly assigned
        
    for(j = 0; j < numCols; ++j){ // prints the column numbers
        printf("%d ",j);
    }
    printf("\n"); // prints new line after each board
    
} 



void play_game(char** board,int numRows,int numCols,int numToWin){ // asks user input // changes character // plays the next move // checks if game is over
    
    int turn = 0; // variable that helps differentiate between player 1 and player 2                                                 
    int userCol = 0; // the column that the player decides to play in
    int i = 0; // for loop index
    int j = 0; // for loop index
    int numStars = 0; // number of blanks remaining on the board
    const char blank = '*'; // blank


    int* heightCols = NULL; // an array that keeps record of the heights of each column
    heightCols = (int*)malloc(numCols*sizeof(int)); // dynamically allocates memory to the array
    for(i = 0; i < numCols; ++i){
        heightCols[i] = 0; // initializes height of each column to 0
    }


    const char userX = 'X'; // the symbol X for player 1
    const char userO = 'O'; // the symbol O for player 2

    while(turn < numRows * numCols){ // indicates that there are still blank spaces left

            
        do{ // executes these statements while the conditions are true
            printf("Enter a column between 0 and %d to play in: ",numCols - 1); // asks the user for the column they would like to play in
            scanf("%d",&userCol); // scans into userCols
        } while(userCol >= numCols || userCol < 0 || heightCols[userCol] >= numRows); // conditions that would make the move invalid



        

        if(turn % 2 == 0){ // indicates that player 1 is playing
            if(board[numRows-1][userCol] == blank){ // if the bottom of the column is blank
                board[numRows-1][userCol] = userX; // changes the board with X at the bottom of the board
                ++heightCols[userCol]; // increases the height of said column
            }
            else{ // if the bottom of the column is not blank
                board[(numRows - heightCols[userCol])-1][userCol] = userX; // plays move above the character
                ++heightCols[userCol]; // and also increases the height of said column
            }
        }

        
        else{  // indicates that player 2 is playing    
            if(board[numRows-1][userCol] == blank){ // if the bottom of the column is blank
                board[numRows-1][userCol] = userO; // changes the board with O at the bottom of the board
                ++heightCols[userCol]; // increases the height of said column
            }
            else{ // if the bottom of the column is not blank
                board[(numRows - heightCols[userCol])-1][userCol] = userO; // plays move above the character
                ++heightCols[userCol]; // and also increases the height of said column
            }

        }

            
        print_board(board,numRows,numCols); // prints board after the move

        
        for(i = 0; i < numRows; ++i){ // used to count the blank characters(stars) on the board
            for(j = 0; j < numCols; ++j){
                if(board[i][j] == blank){
                    ++numStars;
                }

            }
        }
        
        
        if(game_win(board,numRows,numCols,numToWin)){ // if the game is over
            if(turn % 2 == 0){ // if player 1 played last, then he won
                printf("Player 1 Won!\n");
                break;
            }
            else{ // if not, then player 2 won
                printf("Player 2 Won!\n");
                break;
            }
            
        }
        
        

        if(numStars == 0){ // if the number of stars remaining is 0, then the game is a tie
            printf("Tie game!\n");
        }
    
        numStars = 0; // resets the number of stars to 0
           
        ++turn; // increments turn
        ++i; // increments i //  ignore this statement // only for testing purposes

    }
}


bool game_win(char** board,int numRows,int numCols,int numToWin){ // function that indicates whether the game is over and has been won
    
    if(row_win(board,numRows,numCols,numToWin)){ // if row win is true                 
        return true; 
    }
    else if(col_win(board,numRows,numCols,numToWin)){ // if col win is true
        return true;
    }
    else if(ldiag_win(board,numRows,numCols,numToWin)){ // if ldiag win is true
        return true;
    }
    else if(rdiag_win(board,numRows,numCols,numToWin)){ // if rdiag win is true
        return true;
    }
    else{ // else returns false
        return false;
    }
}

bool row_win(char** board,int numRows,int numCols,int numToWin){ // tells whether the game has been won because of a horizontal pattern
    
    int count = 0; // helps count the consecutive pieces
    int i,j,k; // for loop indices
    const char blank = '*';

    if(numToWin == 1){ // returns true if the number of pieces to win is 1 
        for(i = 0; i < numRows; ++i){
            for(j = 0; j < numCols; ++j){
                if(board[i][j] != blank){
                    return true;
                }
            }
        }

    }
    
    for(i = 0;i < numRows;++i){ // for each row
        for(j=0;j < numCols-(numToWin - 1); ++j){ // for each column with calculated dimensions 
            if(board[i][j] != blank){ // if piece is not blank
                for(k = 0;k < numToWin;++k){ // checks the next consecutive horizontal pieces according to the number of required pieces to win
                    if(board[i][j] == board[i][j+k]){ // if the consecutive pieces are same
                        ++count; // increments count
                    }
                }
                if (count == numToWin){ // if the count is equal the the number of pieces to win
                    return true; // returns true
                    break; // breaks if returned true
                }
                count = 0; // resets count to 0
            }       
        }
    }
   
    return false; // if nothing is true, then automatically returns false
}


bool col_win(char** board,int numRows,int numCols,int numToWin){ // tells us whether the game has been won because of a vertical pattern

    int count = 0; 
    int i,j,k;
    const char blank = '*';

    if(numToWin == 1){ // returns true if number of pieces to win is 1
        for(i = 0; i < numRows; ++i){
            for(j = 0; j < numCols; ++j){
                if(board[i][j] != blank){
                    return true;
                }
            }
        }

    }

    for(j = 0; j < numCols; ++j){
        for(i = 0; i < numRows - (numToWin-1); ++i){
            if(board[i][j] != blank){
                for(k=0;k<numToWin;++k){ // checks consecutive elements in board given that they are not blank
                    
                    if(board[i][j] == board[i+k][j]){
                        ++count; // increments count if vertical consecutive elements are same
                    }
                }
                if(count == numToWin){
                    return true; // returns true if the count is equal to the number of pieces required in a column to win
                    break;
                }
                    

                count = 0;
                
            }
        }
    }

    return false;
}

bool ldiag_win(char** board,int numRows,int numCols,int numToWin){ // tells us whether the game has been won because of a left diagonal pattern

    int count = 0;
    int i,j,k;
    const char blank = '*';

    if(numToWin == 1){ // returns true if number of pieces to win is 1
        for(i = 0; i < numRows; ++i){
            for(j = 0; j < numCols; ++j){
                if(board[i][j] != blank){
                    return true;
                }
            }
        }

    }


    for(i = 0; i < numRows - numToWin + 1; ++i){
        for(j = 0; j < numCols - numToWin + 1; ++j){
            if(board[i][j] != blank){
                for(k = 0; k < numToWin - 1; ++k){ // checks consecutive elements in board given that they are not blank
                    if(board[i][j] == board[i + k + 1][j + k + 1]){
                        ++count; // increments count if left diagonal consecutive elements are same
                    }
                    if(count == numToWin-1){
                        return true; // returns true if the count is equal to the number of pieces required in a left diagonal to win
                        break;
                    }
                }
            }
            count = 0;
        }
    }

    return false;
}

bool rdiag_win(char** board,int numRows,int numCols,int numToWin){ // tells us whether the game has been won because of a right diagonal pattern
    
    int count = 0;
    int i,j,k;
    const char blank = '*';

    if(numToWin == 1){ // returns true if number of pieces to win is 1
        for(i = 0; i < numRows; ++i){
            for(j = 0; j < numCols; ++j){
                if(board[i][j] != blank){
                    return true;
                }
            }
        }

    }

    for(i = numRows - numToWin + 2; i < numRows ; ++i){
        for(j = 0; j < numCols - numToWin + 1; ++j){
            if(board[i][j] != blank){
                for(k = 0; k < numToWin -1; ++k){ // checks consecutive elements in board given that they are not blank
                    if(board[i][j] == board[i-k-1][j+k+1]){
                        ++count; // increments count if left diagonal consecutive elements are same
                    }
                    if(count == numToWin-1){
                        return true; // returns true if the count is equal to the number of pieces required in a left diagonal to win
                        break;
                    }
                }
            }
            count = 0;

        }
    }
    return false;
}