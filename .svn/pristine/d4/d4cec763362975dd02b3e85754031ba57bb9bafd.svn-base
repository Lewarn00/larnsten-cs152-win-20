#include <stdio.h>
#include <stdlib.h>
#include "warmup4.h"

/* count_vowels
 * search through str and count the number of vowels.
 * input: char *str - a string
 * output: int - the number of vowels in the string str
 */
int count_vowels(char *str)
{
	
 	char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};
	int counter = 0;

	for(int i = 0; str[i] != '\0'; i++){
		for(int c = 0; c<10; c++){
			if(vowels[c] == str[i]){
				counter++;
			}
		}
	}
	return counter;
}

/* make_lowercase
 * modify str such that all alphabetic characters are lower case
 * input: char *str - a string
 * output: no return value - str is out parameter
 */
void make_lowercase(char *str)
{
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] <= 90 && str[i] >= 65){
			str[i] = str[i] + 32;
		}
	}
	printf("%s\n", str);
}

/* make_horizontal_stripes
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains black and colored stripes. All stripes are 
 *   stripe_height. The stripe colors are indicated by stripe_color.
 *   The top stripe is colored. The image is heightxwidth.
 * inputs: 
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int stripe_height,  - height of a single stripe
 *   unsigned int stripe_red,  - red component of stripe pixel
 *   unsigned int stripe_green,  - green component of stripe pixel
 *   unsigned int stripe_blue,  - blue component of stripe pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * 
 */
void make_horizontal_stripes( 
	unsigned int red[ROWS][COLS], 
	unsigned int green[ROWS][COLS], 
	unsigned int blue[ROWS][COLS], 
	unsigned int stripe_height, 
	unsigned int stripe_red, 
	unsigned int stripe_green, 
	unsigned int stripe_blue, 
	unsigned int width, 
	unsigned int height)
{
	if (width > COLS || height > ROWS)
	{
		printf("Array size too big.\n");
	}
	else if(stripe_height <= 0){
		for(int i = 0; i < height; i++){
			for (int j = 0; j < width; j++)
			{
				red[i][j] = 0;
				green[i][j] = 0;
				blue[i][j] = 0;					
			}
		}
	}
	else{
		for(int i = 0; i < height; i++){
			for (int j = 0; j < width; j++)
			{
				if((i / stripe_height) % 2 == 0)
				{
					red[i][j] = stripe_red;
					green[i][j] = stripe_green;
					blue[i][j] = stripe_blue;
				}else{
					red[i][j] = 0;
					green[i][j] = 0;
					blue[i][j] = 0;					
				}
			}
		}
	}
}

/* make_checker_board
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains white and colored squares. All squares are 
 *   square_width x square_width. The square colors are indicated by 
 *   square_color. The image is heightxwidth. The top-left square is colored.
 * inputs: 
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int square_height,  - height of a single square
 *   unsigned int square_red,  - red component of square pixel
 *   unsigned int square_green,  - green component of square pixel
 *   unsigned int square_blue,  - blue component of square pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * 
 */
void make_checker_board( 
        unsigned int red[ROWS][COLS],
        unsigned int green[ROWS][COLS],
        unsigned int blue[ROWS][COLS],
        unsigned int square_width,
        unsigned int square_red,
        unsigned int square_green,
        unsigned int square_blue,
        unsigned int width,
        unsigned int height)
{

	if (width > COLS || height > ROWS)
	{
		printf("Array size too big.\n");
	}
	else if(square_width <= 0){
		for(int i = 0; i < height; i++){
			for (int j = 0; j < width; j++)
			{
				red[i][j] = 255;
				green[i][j] = 255;
				blue[i][j] = 255;					
			}
		}
	}
	else{
		for(int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				if ( ((i / square_width) % 2) == ((j / square_width) % 2) )
				{
					red[i][j] = square_red;
					green[i][j] = square_green;
					blue[i][j] = square_blue;						
				}else{
					red[i][j] = 255;
					green[i][j] = 255;
					blue[i][j] = 255;						
				}
			}
		}
	}
}

