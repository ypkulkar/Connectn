#ifndef CONNECTN_H
	#define CONNECTN_H
	void create_board(char*** board,int numRows,int numCols); 
	void print_board(char** board,int numRows,int numCols); 
	void destroy_board(char*** board,int numRows,int numCols);
	void play_game(char** board,int numRows,int numCols,int numToWin); 
	bool game_over(char** board,int numRows,int numCols,int numToWin);
	bool game_win(char** board,int numRows,int numCols,int numToWin); 
	bool row_win(char** board,int numRows,int numCols,int numToWin);
	bool col_win(char** board,int numRows,int numCols,int numToWin);
	bool ldiag_win(char** board,int numRows,int numCols,int numToWin);
	bool rdiag_win(char** board,int numRows,int numCols,int numToWin);

#endif