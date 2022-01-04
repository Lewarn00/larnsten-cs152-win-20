#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "warmup4.h"

//A function to test counting vowels.
void test_count_vowels(char *str, unsigned int expected){
	if(count_vowels(str) == expected){
		printf("Tested passed: got - %u, expected - %u \n", count_vowels(str), expected);
	}else{
		printf("Tested failed: got - %u, expected - %u \n", count_vowels(str), expected);
	}
}


int main()
{
	// declare variables
	unsigned int r[ROWS][COLS];
    unsigned int g[ROWS][COLS];
    unsigned int b[ROWS][COLS];
    unsigned int width;
    unsigned int length;

	char str1[] = {'H','o','w','d','y',' ','T','H','E','R','E','!','\0'};
	char str2[] = {'T','h','E','q','u','I','c','K','B','R',')','\0'};
	char str3[] = {'*','8','o','W','N',',','f','0','X','a','Z','9','\0'};
	char str4[] = {'*','8','a','z','\0'};
	char str5[] = {'\0'};

	//Test cases for counting vowels.
	printf("%d\n",count_vowels(str1));
	test_count_vowels(str1,3);
	test_count_vowels(str2,3);
	test_count_vowels(str3,2);
	test_count_vowels(str4,1);
	test_count_vowels(str5,0);

	//Test cases for converting to lowercase.
	printf("Expecting all lowercase:\n");
	make_lowercase(str1);
	make_lowercase(str2);
	make_lowercase(str3);
	make_lowercase(str4);
	make_lowercase(str5);

/*
	// read in ppm file
	// note that r, g, b, width, length are all out parameters
	// that means we need to declare the variables here and send
	// the locations to the function, as seen below.

	// note that for the warmup, you do not need to read in a png.
	provided_read_png("sample.png",r,g,b,&width,&length);
*/

	//Test cases for making horizontal stripes.
	// put in arrays
	make_horizontal_stripes(r, g, b, 1, 30, 144, 255, ROWS, COLS);
	// print to html to view
	provided_print_image_to_html("my_horiz_stripes1.html",r,g,b,ROWS, COLS);

	make_horizontal_stripes(r, g, b, 3, 30, 144, 255, 12, 12);
	provided_print_image_to_html("my_horiz_stripes2.html",r,g,b,12, 12);

	make_horizontal_stripes(r, g, b, 3, 30, 144, 255, 12, 12);
	provided_print_image_to_html("my_horiz_stripes3.html",r,g,b,10, 10);

	make_horizontal_stripes(r, g, b, 0, 30, 144, 255, 5, 5);
	provided_print_image_to_html("my_horiz_stripes4.html",r,g,b,5, 5);

	//Test cases for making checker board.
	// put in arrays
	make_checker_board(r,g,b,4,30,144,255, 12, 12);
	// print to html to view
	provided_print_image_to_html("my_checkboard1.html",r,g,b,12, 12);

	make_checker_board(r,g,b,1,30,144,255, 1, 1);
	provided_print_image_to_html("my_checkboard2.html",r,g,b,1, 1);

	make_checker_board(r,g,b,0,30,144,255, 10, 10);
	provided_print_image_to_html("my_checkboard3.html",r,g,b,10, 10);

	make_checker_board(r,g,b,3,30,144,255, 10, 10);
	provided_print_image_to_html("my_checkboard4.html",r,g,b,10, 10);
}