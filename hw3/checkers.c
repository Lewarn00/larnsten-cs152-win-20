#include <stdlib.h>
#include <stdio.h>
#include "checkers.h"

/* init_board
 * initializes the contents of the checkerboard.
 * The blue pieces occupy rows 0 to (NUM_ROWS/2 - 2), and
 * the white pieces occupy rows (NUM_ROWS / 2 + 1) to NUM_ROWS-1
 * An 8x8 board looks like this:
   * b * b * b * b
   b * b * b * b *
   * b * b * b * b
   * * * * * * * *
   * * * * * * * *
   w * w * w * w *
   * w * w * w * w
   w * w * w * w *
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void init_board(char board[NUM_ROWS][NUM_COLS]){
	int blue = (NUM_ROWS/2 - 2);
	int white = (NUM_ROWS / 2 + 1);

	for(int i = 0; i < NUM_ROWS; i++){
		for(int j = 0; j < NUM_COLS; j++){
			if(i <= blue && i % 2 == 0){
				if(j % 2 != 0){
					board[i][j] = 'b';
				}
				else{
					board[i][j] = '*';
				}
			}
			else if(i <= blue && i % 2 != 0){
				if(j % 2 != 0){
					board[i][j] = '*';
				}
				else{
					board[i][j] = 'b';
				}
			}
			else if(i >= white && i % 2 == 0){
				if(j % 2 != 0){
					board[i][j] = 'w';
				}
				else{
					board[i][j] = '*';
				}
			}
			else if(i >= white && i % 2 != 0){
				if(j % 2 != 0){
					board[i][j] = '*';
				}
				else{
					board[i][j] = 'w';
				}
			}
			else{
				board[i][j] = '*';
			}
		}
	}
}

//A function to place a piece of specified color in a given location.
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], char player, unsigned int row, unsigned int col){
	
	if(row < NUM_ROWS-1 && col < NUM_COLS-1 && board[row][col] == '*'){
		if(player == 'B'){
			board[row][col] = 'b';
		}
		if(player == 'W'){
			board[row][col] = 'w';
		}
		return 1;
	}
	else{
		return 0;
	}
}

/* print_board
 * prints the contents of the checkerboard.
 * The pieces are 'b', 'w', the kinged ones
 * are 'B'and 'W', and empty spaces are '*'
 * inputs:
 *    char board[NUM_ROWS][NUM_COLS] - an NUM_ROWSxNUM_COLS board
 * outputs:
 *    none. prints the results.
 */
void print_board( char board[NUM_ROWS][NUM_COLS] )
{
        unsigned int i, j;
        printf("   ");
        for(j=0;j<NUM_COLS;j++)
        {
                printf("%u ",j);
        }
        printf("\n");
        for(i=0;i<NUM_ROWS;i++)
        {
                printf("%u: ",i);
                for(j=0;j<NUM_COLS;j++)
                {
                        printf("%c ",board[i][j]);
                }
                printf("\n");
        }
}

//A function to decide if a player has one.
int player_won(char board[NUM_ROWS][NUM_COLS], char player){

	int no_move = 0;
	int num_pieces = 0;
	char pieces_loc[12][2];
	int index = 0;
	char loserC;
	char loserL;

	if(player == 'B'){
		loserC = 'W';
		loserL = 'w';
	}else{
		loserC = 'B';
		loserL = 'b';
	}

	//Locating all the pieces the opponent has on the board,
	//if they have any.
	for(int i = 0; i < NUM_ROWS; i++){
		for(int j = 0; j < NUM_COLS; j++){
			if(board[i][j] == loserL){
				num_pieces++;
				pieces_loc[index][0] = i;
				pieces_loc[index][1] = j;
				index++;
			}
		}
	}

	//Determining if those pieces are able to move.
	for(int n = 0; n <= 12; n++){
		for(int i = 0; i < NUM_ROWS; i++){
			for(int j = 0; j < NUM_COLS; j++){
				if(do_move(loserC,pieces_loc[n][0],pieces_loc[n][1],i,j,board) != 0){
					no_move++;
				}
			}
		}
	}

	if(num_pieces == 0 || no_move == 0){
		return 1;
	}else{
		return 0;
	}
}

//A function to move a piece from one square to another
//abiding by the rules of checkers. 
unsigned int do_move(char player, unsigned int startrow, unsigned int startcol, 
	unsigned int endrow, unsigned int endcol, char board[8][8]){

	if(startrow < 8 && startcol < 8 && endrow < 8 && endcol < 8){
		if(player == 'B' && board[startrow][startcol] == 'b'){ 
			if(board[endrow][endcol] == '*' && (endrow - startrow) == 1 
				&& abs((int)endcol - (int)startcol) == 1 && endrow > startrow){
				//First, it checks if a single diagonal movements is being attempted.
				board[startrow][startcol] = '*';

				if(endrow == 7){
					board[endrow][endcol] = 'B';
				}else{
					board[endrow][endcol] = 'b';
				}
				return 1;				
			}else if(board[endrow][endcol] == '*' && (endrow - startrow) == 2 
				&& abs((int)endcol - (int)startcol) == 2 && endcol > startcol
				&& (board[startrow + 1][startcol + 1] == 'w' || 
				board[startrow + 1][startcol + 1] == 'W')){
				//Then, it checks if a piece is attempting to jump another piece.
				board[startrow][startcol] = '*';
				board[startrow + 1][startcol + 1] = '*';

				if(endrow == 7){
					board[endrow][endcol] = 'B';
				}else{
					board[endrow][endcol] = 'b';
				}					
				return 2;
			}else if(board[endrow][endcol] == '*' && (endrow - startrow) == 2 
				&& abs((int)endcol - (int)startcol) == 2 && endcol < startcol
				&& (board[startrow + 1][startcol - 1] == 'w' ||
					board[startrow + 1][startcol - 1] == 'W')){
				//This must be checked on both the left and right sides.
				board[startrow][startcol] = '*';
				board[startrow + 1][startcol - 1] = '*';

				if(endrow == 7){
					board[endrow][endcol] = 'B';
				}else{
					board[endrow][endcol] = 'b';
				}				
				return 2;
			}else{
				return 0;
			}
		}
		//This if statement repeats the logic of the previous.
		if(player == 'W' && board[startrow][startcol] == 'w'){
			if(board[endrow][endcol] == '*' && abs((int)startrow - (int)endrow) == 1 
				&& abs((int)endcol - (int)startcol) == 1 && startrow > endrow){
				board[startrow][startcol] = '*';

				if(endrow == 0){
					board[endrow][endcol] = 'W';
				}else{
					board[endrow][endcol] = 'w';
				}
				return 1;
			}else if(board[endrow][endcol] == '*' && (startrow - endrow) == 2 
				&& abs((int)endcol - (int)startcol) == 2 && endcol > startcol
				&& (board[startrow - 1][startcol + 1] == 'b'|| 
					board[startrow - 1][startcol + 1] == 'B')){
				board[startrow][startcol] = '*';
				board[startrow - 1][startcol + 1] = '*';

				if(endrow == 0){
					board[endrow][endcol] = 'W';
				}else{
					board[endrow][endcol] = 'w';
				}			
				return 2;
			}else if(board[endrow][endcol] == '*' && (startrow - endrow) == 2 
				&& abs((int)endcol - (int)startcol) == 2 && endcol < startcol
				&& (board[startrow - 1][startcol - 1] == 'b' || 
					board[startrow - 1][startcol - 1] == 'B')){
				board[startrow][startcol] = '*';
				board[startrow - 1][startcol - 1] = '*';

				if(endrow == 0){
					board[endrow][endcol] = 'W';
				}else{
					board[endrow][endcol] = 'w';
				}			
				return 2;
			}else{
				return 0;
			}
		}
		//This if statement is similar to the previous ones,
		//however, since kings can move up and down it must check
		//up and down as well as left and right.
		if((player == 'B' && board[startrow][startcol] == 'B') 
			|| (player == 'W' && board[startrow][startcol] == 'W')){
			if(board[endrow][endcol] == '*' && abs((int)endrow - (int)startrow) == 1 
				&& abs((int)endcol - (int)startcol) == 1){
				if(player == 'B'){
					board[endrow][endcol] = 'B';
				}
				if(player == 'W'){
					board[endrow][endcol] = 'W';
				}
				board[startrow][startcol] = '*';
				return 1;
			}else if(board[endrow][endcol] == '*' && abs((int)startrow - (int)endrow) == 2 
				&& abs((int)endcol - (int)startcol) == 2 && endcol > startcol){
				int row_move = ((int) endrow - (int) startrow)/2;

					if((board[startrow + row_move][startcol + 1] == 'b' || 
					board[startrow + row_move][startcol + 1] == 'B') && player == 'W'){
					board[endrow][endcol] = 'W';
					board[startrow][startcol] = '*';
					board[startrow + row_move][startcol + 1] = '*';
					return 2;
				}
				else if((board[startrow + row_move][startcol + 1] == 'w' || 
					board[startrow + row_move][startcol + 1] == 'W') && player == 'B'){
					board[endrow][endcol] = 'B';
					board[startrow][startcol] = '*';
					board[startrow + row_move][startcol + 1] = '*';
					return 2;
				}else{
					return 0;
				}
			}else if(board[endrow][endcol] == '*' && abs((int)endrow - (int)startrow) == 2 
				&& abs((int)endcol - (int)startcol) == 2 && endcol < startcol){
				int row_move = ((int) endrow - (int) startrow)/2;

				if((board[startrow + row_move][startcol - 1] == 'b' || 
					board[startrow + row_move][startcol - 1] == 'B') && player == 'W'){
					board[endrow][endcol] = 'W';
					board[startrow][startcol] = '*';
					board[startrow + row_move][startcol - 1] = '*';
					return 2;
				}
				else if((board[startrow + row_move][startcol - 1] == 'w' || 
					board[startrow + row_move][startcol - 1] == 'W') && player == 'B'){
					board[endrow][endcol] = 'B';
					board[startrow][startcol] = '*';
					board[startrow + row_move][startcol - 1] = '*';
					return 2;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}

	}else{
		return 0;
	}
}

//A function to generate a random computer move.
int computer_move(char board[NUM_ROWS][NUM_COLS], char player, 
	unsigned int *row, unsigned int *col){

	int moves = 0;

	//This triple loop plays the first open move which it finds.
	for(int i = 0; i < NUM_ROWS; i++){
		for (int j = 0; j < NUM_COLS; j++){
			for(int s = -2; s < 3; s++){
				if(board[i][j] == 'b' && player == 'B'){
					if(do_move(player, i, j, i-s, j-s, board) > 0){
						*row = i-s;
						*col = j-s;	
						moves++;
						int move_made = do_move(player, i, j, i-s, j-s, board);				
						return move_made;
					}else if(do_move(player, i, j, i+s, j-s, board) > 0){
						*row = i+s;
						*col = j-s;	
						moves++;				
						int move_made = do_move(player, i, j, i+s, j-s, board);			
						return move_made;
					}
				}
				if(board[i][j] == 'w' && player == 'W'){				
					if(do_move(player, i, j, i+s, j+s, board) > 0){
						*row = i+s;
						*col = j+s;	
						moves++;				
						int move_made = do_move(player, i, j, i+s, j+s, board);		
						return move_made;					
					}else if(do_move(player, i, j, i-s, j+s, board) > 0){
						*row = i-s;
						*col = j+s;
						moves++;
						int move_made = do_move(player, i, j, i-s, j+s, board);		
						return move_made;					
					}
				}
				if(board[i][j] == player){
					if(do_move(player, i, j, i+s, j+s, board) > 0){
						*row = i+s;
						*col = j+s;
						moves++;
						int move_made = do_move(player, i, j, i+s, j+s, board);		
						return move_made;
					}else if(do_move(player, i, j, i-s, j+s, board) > 0){
						*row = i-s;
						*col = j+s;
						moves++;
						int move_made = do_move(player, i, j, i-s, j+s, board);	
						return move_made;
					}else if(do_move(player, i, j, i-s, j-s, board) > 0){
						*row = i-s;
						*col = j-s;
						moves++;
						int move_made = do_move(player, i, j, i-s, j-s, board);
						return move_made;
					}else if(do_move(player, i, j, i+s, j-s, board) > 0){
						*row = i+s;
						*col = j-s;
						moves++;
						int move_made = do_move(player, i, j, i+s, j-s, board);
						return move_made;
					}
				}
			}
		}
	}
	if(moves == 0){
		return 0;
	}
}

//A function to test the computer moves.
void test_computer_move(){
	unsigned int rowM;
    unsigned int colM;

	char board1[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };
	char board2[8][8] = { {'b','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };
	char board3[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'b','*','w','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };    
	char board4[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','W','*','w','*','w','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };  
	char board5[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','B','*','*','*','*'}  }; 
	char board6[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','b','*','*','*'},
                         {'*','*','*','w','*','w','*','*'},
                         {'*','*','w','*','*','*','w','*'},
                         {'*','w','*','*','*','w','*','*'},
                         {'*','*','w','*','w','*','*','*'},
                         {'*','*','*','B','*','*','*','*'}  };  
	char board7[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'b','*','w','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  }; 
	char board8[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','W','*','w','*','w','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };  

	printf("Computer_move: %u, expected: 0\n", 
		computer_move(board1, 'B', &rowM, &colM));
	printf("Computer_move: %u, expected: 1\n", 
		computer_move(board2, 'B', &rowM, &colM));
	printf("Computer_move: %u, expected: 2\n", 
		computer_move(board3, 'B', &rowM, &colM));
	printf("Computer_move: %u, expected: 2\n", 
		computer_move(board7, 'W', &rowM, &colM));
	printf("Computer_move: %u, expected: 1\n", 
		computer_move(board8, 'B', &rowM, &colM));
	printf("Computer_move: %u, expected: 2\n", 
		computer_move(board4, 'W', &rowM, &colM));
	printf("Computer_move: %u, expected: 1\n", 
		computer_move(board5, 'B', &rowM, &colM));
	printf("Computer_move: %u, expected: 0\n", 
		computer_move(board6, 'B', &rowM, &colM));
}

//A function to test the do_move function.
void test_do_move(){

	char board1[8][8] = { {'w','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };
	char board2[8][8] = { {'b','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };
	char board3[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'b','*','w','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };    
	char board4[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','W','*','w','*','w','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };  
	char board5[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','B','*','*','*','*'}  }; 
	char board6[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','b','*','*','*'},
                         {'*','*','*','w','*','w','*','*'},
                         {'*','*','w','*','*','*','w','*'},
                         {'*','w','*','*','*','w','*','*'},
                         {'*','*','w','*','w','*','*','*'},
                         {'*','*','*','B','*','*','*','*'}  };  
	char board7[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'b','*','w','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  }; 
	char board8[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'b','*','w','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };                        

	printf("do_move: %u, expected: 0\n",do_move('B', -1, -1, 1, 1, board1));
	printf("do_move: %u, expected: 1\n",do_move('B', 0, 0, 1, 1, board2));
	printf("do_move: %u, expected: 2\n",do_move('B', 1, 1, 3, 3, board3));
	printf("do_move: %u, expected: 0\n",do_move('B', 1, 1, 2, 0, board7));
	printf("do_move: %u, expected: 2\n",do_move('W', 2, 2, 0, 0, board8));
	printf("do_move: %u, expected: 0\n",do_move('W', 5, 4, 6, 3, board4));
	printf("do_move: %u, expected: 0\n",do_move('W', 5, 4, 5, 3, board4));
	printf("do_move: %u, expected: 1\n",do_move('W', 5, 6, 4, 7, board4));
	printf("do_move: %u, expected: 2\n",do_move('W', 5, 2, 7, 0, board4));
	printf("do_move: %u, expected: 1\n",do_move('B', 7, 3, 6, 2, board5));
	printf("do_move: %u, expected: 0\n",do_move('B', 7, 3, 6, 2, board6));
	printf("do_move: %u, expected: 0\n",do_move('B', 7, 3, 5, 1, board6));
	print_board(board4);
}

//A function to test the player_won function.
void test_player_won(){

	char board2[8][8] = { {'b','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };
	char board3[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','b','*','*','*','*','*','*'},
                         {'b','*','w','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'}  };    
	char board6[8][8] = { {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','*','*','*','*'},
                         {'*','*','*','*','b','*','*','*'},
                         {'*','*','*','w','*','w','*','*'},
                         {'*','*','w','*','*','*','w','*'},
                         {'*','w','*','*','*','w','*','*'},
                         {'*','*','w','*','w','*','*','*'},
                         {'*','*','*','B','*','*','*','*'}  };  

	printf("player_won: %u, expected: 1\n",player_won(board2, 'B'));
	printf("player_won: %u, expected: 0\n",player_won(board3, 'W'));
	printf("player_won: %u, expected: 1\n",player_won(board6, 'W'));
}

//A function compiling all the test functions.
void test_checkers(){
	test_computer_move();
	test_do_move();
	test_player_won();
}
