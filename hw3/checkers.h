#ifndef CHECKERS_H
#define CHECKERS_H
#define NUM_ROWS 8
#define NUM_COLS 8

void print_board( char board[NUM_ROWS][NUM_COLS] );
void init_board(char board[NUM_ROWS][NUM_COLS]);
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], 
	char player, unsigned int row, unsigned int col);
int player_won(char board[NUM_ROWS][NUM_COLS], char player);
unsigned int do_move(char player, unsigned int startrow, unsigned int startcol, 
	unsigned int endrow, unsigned int endcol, char board[8][8]);
void test_checkers();
int computer_move(char board[NUM_ROWS][NUM_COLS], char player, 
	unsigned int *row, unsigned int *col);

#endif