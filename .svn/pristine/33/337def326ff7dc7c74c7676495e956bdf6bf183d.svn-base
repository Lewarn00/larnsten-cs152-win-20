#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"


//A function to extract the digit of a pattern at a given index.
unsigned int extract_digit(unsigned int pattern, unsigned int digit)
{
	int loc;

	if(digit == 0){
		loc = pattern % 10;
	}
	if(digit == 1){
		loc = (pattern / 10) % 10;
	}
	if(digit == 2){
		loc = (pattern / 100) % 10;
	}
	if (digit == 3){
		loc = (pattern / 1000) % 10;
	}
	return loc;
}

//A function to find the number of times a given number occurs in a pattern.
unsigned int num_of_color(unsigned int pattern, unsigned int color)
{
	int count_color = 0;

	for(int i = 0; i < 4; i++){
		if(extract_digit(pattern, i) == color){
			count_color++;
		}
	}
	return count_color;
}

//A function to find the number of exact matches between two patterns.
unsigned int count_exact_matches(unsigned int guess, unsigned int solution)
{
	int exact_matches = 0;

	for(int i = 0; i < 4; i++){
		if(extract_digit(guess,i) == extract_digit(solution,i)){
			exact_matches++;
		}
	}
	return exact_matches;
}

//A function to find the number of matches between 2 patterns
//regardless of their location. 
unsigned int count_color_matches(unsigned int guess, unsigned int solution)
{
	double color_matches = 0.0;

	for(int i = 0; i < 4; i++){

	    if(num_of_color(solution,extract_digit(guess,i)) >=
			num_of_color(guess,extract_digit(guess,i))){
			color_matches++;

		}
		else if(num_of_color(solution,extract_digit(guess,i)) < 
			num_of_color(guess,extract_digit(guess,i)) && 
			num_of_color(solution,extract_digit(guess,i)) > 0){

			color_matches = color_matches + 
			(double) num_of_color(solution,extract_digit(guess,i))/
			num_of_color(guess,extract_digit(guess,i));
		}

	}
	return color_matches;
}

//A function to report the number of exact guesses and correct numbers.
unsigned int get_guess_feedback(unsigned int guess, unsigned int solution)
{
	int color_matches = count_color_matches(guess,solution);
	int exact_matches = count_exact_matches(guess,solution);
	int not_exact_matches = color_matches - exact_matches;
	int final_output = (exact_matches * 10) + not_exact_matches;
	return final_output;
}

/* test_mastermind
 * This is the test function that has 3+ good test cases for this function in your
 * mastermind program. This verifies that the bits are working so that if you find a 
 * bug you can more easily localize it.
 * inputs:
 *   none. Tests are hard coded.
 * outputs:
 *   none. Test results are printed out.
 */
void check_extract_digit()
{
	printf("extract_digit(%u,%d)=%u, expected: 0\n",3413,-1,extract_digit(3413, -1)); 
	printf("extract_digit(%u,%u)=%u, expected: 3\n",3413,0,extract_digit(3413, 0)); 
	printf("extract_digit(%u,%u)=%u, expected: 1\n",3413,1,extract_digit(3413, 1)); 
	printf("extract_digit(%u,%u)=%u, expected: 3\n",3413,3,extract_digit(3413, 3)); 
}

void check_num_of_color()
{
	printf("num_of_color(%u,%d)=%u, expected: 0\n",3413,-1,num_of_color(3413, -1)); 
	printf("num_of_color(%u,%u)=%u, expected: 0\n",3413,0,num_of_color(3413, 0)); 
	printf("num_of_color(%u,%u)=%u, expected: 1\n",3413,1,num_of_color(3413, 1)); 
	printf("num_of_color(%u,%u)=%u, expected: 2\n",3413,3,num_of_color(3413, 3)); 
}
void check_count_exact_matches()
{
	printf("count_exact_matches(%u,%u)=%u, expected: 0\n",
		3413, 0000,count_exact_matches(3413, 0000)); 
	printf("count_exact_matches(%u,%u)=%u, expected: 1\n",
		3413, 1111,count_exact_matches(3413, 1111)); 
	printf("count_exact_matches(%u,%u)=%u, expected: 2\n",
		3413, 3123,count_exact_matches(3413, 3123)); 
	printf("count_exact_matches(%u,%u)=%u, expected: 4\n",
		3413, 3413,count_exact_matches(3413, 3413)); 
}

void check_count_color_matches()
{
	printf("count_color_matches(%u,%u)=%u, expected: 0\n",
		3413, 0000,count_color_matches(3413, 0000)); 
	printf("count_color_matches(%u,%u)=%u, expected: 1\n",
		3413, 1111,count_color_matches(3413, 1111)); 
	printf("count_color_matches(%u,%u)=%u, expected: 3\n",
		3413, 4132,count_color_matches(3413, 4132)); 
}
void check_get_guess_feedback()
{
	printf("get_guess_feedback(%u,%u)=%u, expected: 0\n",
		3413, 0000,get_guess_feedback(3413, 0000)); 
	printf("get_guess_feedback(%u,%u)=%u, expected: 10\n",
		3413, 1111,get_guess_feedback(3413, 1111)); 
	printf("get_guess_feedback(%u,%u)=%u, expected: 12\n",
		3413, 3123,get_guess_feedback(3413, 3132)); 
}

void test_mastermind()
{
	check_extract_digit();
	check_num_of_color();
	check_count_exact_matches();
	check_count_color_matches();
	check_get_guess_feedback();

}

/* print_mastermind_instructions
 * This prints out user instructions to play mastermind.
 * inputs:
 *   none
 * outputs:
 *   none. Insructions are printed to screen.
 */
void print_mastermind_instructions()
{
	printf("Welcome to mastermind. I am thinking of a 4-number\n");
	printf("sequence. All four numbers are between 1 and 6.\n");
	printf("You have 12 guesses to guess it correctly.\n");
	printf("Each time you guess, I'll tell two things.\n");
	printf("1. How many numbers are correct and in the correct position.\n");
	printf("2. How many other numbers are correct but in the wrong position.\n");
	printf("Let's get started!!!\n");
}

/* get_new_code
 * Generates a 4-digit number, with each digit a number from 1 to 6, inclusive.
 * inputs:
 *   none
 * outputs:
 *   unsigned int - 4-digit number with each digit from 1 to 6
 */
unsigned int get_new_code()
{
	int i;
	int result = 0;
	for (i = 0; i < 4; i++)
	{
		result = result * 10;
		result = result + ((rand() % 6) + 1);
	}
	return result;
}


/* play_mastermind
 * This is the game loop to play mastermind. All print statements are provided so that you 
 * have consistent messages for grading purposes. An example of how to do error checking is 
 * provided so you can model that.
 * inputs:
 *  none. Users play interactively
 * outputs:
 *  none. Everything is printed.
 */
void play_mastermind()
{

	unsigned int guess_num = 0;
	unsigned int solution = 0;
	unsigned int guess = 0;
	unsigned int feedback = 0;
	unsigned int win = 0;

	print_mastermind_instructions();
	solution = get_new_code();

	printf("solution: %u\n",solution);

	while(guess_num < 12 && win == 0){

		printf("Guess %d - ",guess_num + 1);
		printf("Input your 4-digit guess: ");
		scanf("%u",&guess);
		if(guess < 9999 && extract_digit(guess,0) < 7 && extract_digit(guess,0) > 0 
			&& extract_digit(guess,1) < 7 && extract_digit(guess,1) > 0 
			&& extract_digit(guess,2) < 7 && extract_digit(guess,2) > 0
			&& extract_digit(guess,3) < 7 && extract_digit(guess,3) > 0){

			feedback = get_guess_feedback(guess,solution);

			// report the feedback
			printf("Feedback: %u correct placement, correct color,\n",
				feedback / 10);
			printf("%u incorrect placement, correct color\n",
				feedback % 10);

			// if correct, print out congrats and return from this function.
			if(feedback / 10 == 4){
				printf("Congratulations! Your guess of %u was correct!\n",
					guess);
				win++;
			}
			else if(feedback / 10 != 4 && guess_num != 11){
				printf("Not quite - you still have %u guesses left!\n",
					11 - guess_num);
			}

			guess_num++;

			// only print this out if they ran out of guesses didn't win.
			if(guess_num == 12 && win == 0){
				printf("Sorry, you did not guess it! The solution was %u\n",solution);
			}

		}
		else{
			// note: If it's an invalid guess, go back and ask the guess immediately. Go back
			// to Guess %d - . Don't print out the Congratuations or Not quite below.
			printf("%u is an invalid guess. Make sure your guess is a 4-digit number, each digit between 1-6.\n",
		                guess);
		}

	}
}
