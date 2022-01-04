#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "warmup3.h"

//A fucntion to remove the maximum values from an array.
int remove_max(int array[], unsigned int length){
	int max = 0;
	int maxes_index[length];
	int max_offset = 0;
	int all_same = 0;

	//Finding the max
	for(int i = 0; i < length; i++){
		if(array[i] >= max){
			max = array[i];
		}
	}

	//Making a new array with the indexes of the max values.
	for(int i = 0; i < length; i++){
		if(array[i] >= max){
			maxes_index[i] = i;
			all_same++;
		}else{
			maxes_index[i] = 0;
		}
	}

	//Shifting all of the indexes of the max values to the end of the array.
	for(int i = 0; i < length; i++){
		if(maxes_index[i] > 0){
			for(int n = maxes_index[i] - max_offset; n < length; n++){
				if(all_same != length){
					array[n] = array[n + 1];
				}
			}
			max_offset++;
		}
	}
	
	//Accounting for the fact that the first value may have been
	//missed if it was a max.
	if(array[0] == max){
		for(int n = 0; n < length; n++){
			if(all_same != length){
				array[n] = array[n + 1];
			}
		}		
	}

	for(int n = 0; n < length; n++) {
        printf("%d ", array[n]);
    }
 
	if(length != 0){
		return max;
	}else{
		return INT_MIN;
	}
}

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
 *    none. Puts results in array.
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
					board[i][j] = '*';
				}
				else{
					board[i][j] = 'w';
				}
			}
			else if(i >= white && i % 2 != 0){
				if(j % 2 != 0){
					board[i][j] = 'w';
				}
				else{
					board[i][j] = '*';
				}
			}
			else{
				board[i][j] = '*';
			}
		}
	}
}

//A function to place a piece in an open spot on a board.
unsigned int place_piece(char board[NUM_ROWS][NUM_COLS], 
	char player, unsigned int row, unsigned int col){

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

//A function to calculate the area and perimeter of a square.
void area_and_perimeter(double height, double length, 
	double *area, double *perimeter){

	double area_value = height * length;
	double perimeter_value = 2 * height + 2 * length;

	*area = area_value;
	*perimeter = perimeter_value;
}

//The same as remove_max, except it also changes the array length.
int remove_max_in_out(int array[], unsigned int *length){
	
	int max = 0;
	int maxes_index[*length];
	int max_offset = 0;
	int new_length = *length;
	int all_same = 0;
	
	for(int i = 0; i < *length; i++){
		if(array[i] >= max){
			max = array[i];
		}
	}

	for(int i = 0; i < *length; i++){
		if(array[i] >= max){
			maxes_index[i] = i;
			all_same++;
		}else{
			maxes_index[i] = 0;
		}
	}

	for(int i = 0; i < *length; i++){
		if(maxes_index[i] > 0){
			for(int n = maxes_index[i] - max_offset; n < *length; n++){
				if(all_same != *length){
					array[n] = array[n + 1];
				}
			}
			max_offset++;
			new_length--;
		}
	}

	if(array[0] == max){
		for(int n = 0; n < *length; n++){
			if(all_same != *length){
				array[n] = array[n + 1];
			}
		}
		new_length--;		
	}

	for(int n = 0; n < *length; n++) {
        printf("%d ", array[n]);
    }
 
	*length = new_length;

	return max;
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

//A fucntion to test remove_max.
void test_remove_max(){
	int array1[] = {-2, 4, 6, -5, 6};
	int array2[] = {1, 1, 1, 1, 1};
	int array3[] = {0};
	int array4[] = {8,7,5,8,3,8,5,3,2};
	printf("remove_max(%s,%u)=%u, expected: {-2,4,-5,X,X}\n","{-2, 4, 6, -5, 6}",5,
		remove_max(array1,5)); 
	printf("remove_max(%s,%u)=%u, expected: {1,1,1,1,1}\n","{1, 1, 1, 1, 1}",5,
		remove_max(array2,5));
	printf("remove_max(%s,%u)=%u, expected: INT_MIN\n","{0}",0,
		remove_max(array3,0));
	printf("remove_max(%s,%u)=%u , expected: {7,5,3,5,3,2,X,X,X}\n",
		"{8,7,5,8,3,8,5,3,2}",9,remove_max(array4,9));
}

//A function to test remove_max_in_out.
void test_remove_max_in_out(){
	int array1[] = {-2, 4, 6, -5, 6};
	int array2[] = {1, 1, 1, 1, 1};
	int array3[] = {0};
	int array4[] = {8,7,5,8,3,8,5,3,2};
	unsigned int l1 = 5;
	unsigned int l2 = 0;
	unsigned int l3 = 9;
	unsigned int l4 = 5;
	printf("remove_max_in_out(%s,%u)=%u length %u, expected: {-2,4,-5,X,X}, length 3\n",
		"{-2, 4, 6, -5, 6}",5,remove_max_in_out(array1,&l1),l1); 
	printf("remove_max_in_out(%s,%u)=%u length %u, expected: {1,1,1,1,1}, length 0\n",
		"{1, 1, 1, 1, 1}",5,remove_max_in_out(array2,&l4),l4);
	printf("remove_max_in_out(%s,%u)=%u length %u, expected: INT_MIN\n",
		"{0}",0,remove_max_in_out(array3,&l2),l2);
	printf("remove_max_in_out(%s,%u)=%u length %u, expected: {7,5,3,5,3,2,X,X,X}, length 6\n",
		"{8,7,5,8,3,8,5,3,2}",9,remove_max_in_out(array4,&l3),l3);
}

//A helper function for ensuring the area and perimeter are
//calculated accurately.
void test_area_and_perimeter_helper(double height, double width, 
	double expected_area, double expected_perim, double accuracy)
{
    double area1;
    double perim1;
    area_and_perimeter(height, width, &area1, &perim1);

	if((area1 >= expected_area - accuracy) && 
		(area1 <= expected_area + accuracy) &&
		(perim1 <= expected_perim + accuracy) &&
		(perim1 >= expected_perim - accuracy))
	{
	printf("Test passed: area_and_perimeter(%f,%f)=%f,%f expected: area %f, perimeter %f\n",
		height,width,area1,perim1,expected_area,expected_perim); 
	}
	else
	{
	printf("Test failed: area_and_perimeter(%f,%f)=%f,%f expected: area %f, perimeter %f\n",
		height,width,area1,perim1,expected_area,expected_perim); 
	}
}

//A function to test finding the area and perimeter of a rectangle.
void test_area_and_perimeter(){
	test_area_and_perimeter_helper(0.0, 0.0, 0.0, 0.0, 0.0);
	test_area_and_perimeter_helper(1.0, 1.0, 1.0, 4.0, 0.01);
	test_area_and_perimeter_helper(10.3, 5.1, 52.53, 30.8, 0.01);
	test_area_and_perimeter_helper(50.0, 30.0, 1500.0, 160.0, 0.01);
}

//A function to test the place_piece function.
void test_place_piece(){
	char board[8][8];
	init_board(board);
	printf("place_piece(board, 'W', -1, -1):%u, expected: 0\n",place_piece(board, 'W', -1, -1));
	printf("place_piece(board, 'W', 0, 0):%u, expected: 1\n",place_piece(board, 'W', 0, 0));
	printf("place_piece(board, 'B', 5, 4):%u, expected: 1\n",place_piece(board, 'B', 5, 4));
	print_board(board);
}

//A function to test the init_board function.
void test_init_board(){
	char board[8][8];
	init_board(board);
	print_board(board);
}


