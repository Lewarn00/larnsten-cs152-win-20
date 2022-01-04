#include <stdlib.h>
#include <stdio.h>
#include "warmup2.h"

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. 
 */
void print_asterisk_letter(char letter)
{ 
	if(letter == 'S' || letter == 's'){
		printf(" ****\n*\n ***\n    *\n****\n");
	}
	if(letter == 'T' || letter == 't'){
		printf("*****\n  *\n  *\n  *\n  *\n");
	}
	if(letter == 'U' || letter == 'u'){
		printf("*   *\n*   *\n*   *\n*   *\n ***\n");
	}
	if(letter == 'V' || letter == 'v'){	
		printf("*   *\n*   *\n*   *\n * *\n  *\n");
	}
}

/* draw_hourglass_rec_helper
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 *   uint offset - amount of spaces that should be to the left of this hourglass
 * outputs:
 *   nothing returned, just printed to the screen
 */
void draw_asterisk(unsigned int height)
{
	if(height == 1){
		printf("*\n");
	}
	if(height > 1){
		printf("*");
		draw_asterisk(height - 1);
	}
}

void draw_hourglass_rec_helper1(unsigned int height, unsigned int offset)
{ 
	if(height == 1){
		printf("%*s",offset," ");
		draw_asterisk(height);
	}
	if(height > 1){
		printf("%*s",offset," ");
		draw_asterisk(height);
		draw_hourglass_rec_helper1(height-2,offset+1);
	}
}

void draw_hourglass_rec_helper2(unsigned int height, unsigned int offset)
{ 
	if(offset == 1){
		printf("%*s",offset," ");
		draw_asterisk(height);
	}
	if(offset > 1){
		printf("%*s",offset," ");
		draw_asterisk(height);
		draw_hourglass_rec_helper2(height+2,offset-1);
	}	
}
/* draw_hourglass_rec
 * draws a hourglass with asterisks. implemented recursively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_rec(unsigned int height)
{ 
	if (height == 0)
	{
		return;
	}
	if(height % 2 != 0){
		draw_hourglass_rec_helper1(height,1);
		draw_hourglass_rec_helper2(3,height/2);
	}	
	if(height % 2 == 0){
		height--;
		draw_hourglass_rec_helper1(height,1);
		draw_hourglass_rec_helper2(1,height/2+1);
	}
}

/* draw_hourglass_iter
 * draws a hourglass with asterisks. Implemented iteratively.
 * inputs:
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_hourglass_iter(unsigned int height)
{
	if (height == 0)
	{
		return;
	}
	if(height % 2 != 0){
		for(int i = height; i > 0; i = i-2){
			for(int s = 0; s < (height - i)/2; s++){
				printf(" ");
			}
			for(int n = 0; n < i; n++){
				printf("*");
			}
			printf("\n");
		}
		for(int i = 3; i <= height; i = i+2){
			for(int s = 0; s < (height - i)/2; s++){
				printf(" ");
			}
			for(int n = 0; n < i; n++){
				printf("*");
			}
			printf("\n");
		}
	}
	if(height % 2 == 0){
		height--;
		for(int i = height; i > 0; i = i-2){
			for(int s = 0; s < (height - i)/2; s++){
				printf(" ");
			}
			for(int n = 0; n < i; n++){
				printf("*");
			}
			printf("\n");
		}
		for(int i = 1; i <= height; i = i+2){
			for(int s = 0; s < (height - i)/2; s++){
				printf(" ");
			}
			for(int n = 0; n < i; n++){
				printf("*");
			}
			printf("\n");
		}
	}	
}

