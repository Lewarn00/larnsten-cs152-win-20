#include <stdio.h>
#include <stdlib.h>

/* Convert centimeters to inches */
double convert_length(double centimeters)
{
	if(centimeters < 0)
	{
		fprintf(stderr,"ERROR (convert_length): Negative input\n");
		return -1;
	}
	else
	{
		double inches = 0.3937 * centimeters;
		return inches;
	}

}

/* Calculate the area of a trapezoid */
double trapezoid_area(unsigned int height, 
	unsigned int base1, unsigned int base2)
{
	if (height == 0 || base1 == 0 || base2 == 0)
	{
		fprintf(stderr,"ERROR (trapezoid_area): Zero input\n");
		return 0;
	}
	else
	{
		double area;
		area = ((base1 + base2)/2) * height;
		return area;
	}	

}

/* Print 5 rows of Pascal's Triangle */
void print_number_triangle(unsigned int start_num)
{
	if(start_num > 999)
	{
		fprintf(stderr,"ERROR (print_number_triangle):");
		fprintf(stderr," Numbers larger than 3 digits not supported\n");
	}
	else
	{
		printf("\t\t\t\t%3u\n",start_num);
		printf("\t\t\t%3u\t\t%3u\n",start_num,start_num);
		printf("\t\t%3u\t\t%3u\t\t%3u\n",start_num,start_num*2,start_num);
		printf("\t%3u\t\t%3u\t\t%3u\t\t%3u\n",
			start_num,start_num*3,start_num*3,start_num);
		printf("%3u\t\t%3u\t\t%3u\t\t%3u\t\t%3u\n",
			start_num,start_num*4,start_num*6,start_num*4,start_num);
	}

}

/* Helper function to test convert_length */
void check_length(double input, double expected_output,	double accuracy)
{
	double output;
	output = convert_length(input);

	if((output >= expected_output - accuracy) && 
		(output <= expected_output + accuracy))
	{
	printf("Test passed: convert_length(%lf) = %lf, expected %lf\n",
			input, output, expected_output);
	}
	if((output < expected_output - accuracy) && (
		output > expected_output + accuracy))
	{
	printf("Test failed: convert_length(%lf) = %lf, expected %lf\n",
			input, output, expected_output);
	}

}

/* Helper function to test trapezoid_area */
void check_trap(unsigned int height, unsigned int base1, unsigned int base2, 
	double expected_output, double accuracy)
{
	double output;
	output = trapezoid_area(height, base1, base2);

	if((output >= expected_output - accuracy) && 
		(output <= expected_output + accuracy))
	{
	printf("Test passed: trapezoid_area(%u,%u,%u) = %lf, expected %lf\n",
			height, base1, base2, output, expected_output);
	}
	if((output < expected_output - accuracy) && 
		(output > expected_output + accuracy))
	{
	printf("Test failed: trapezoid_area(%u,%u,%u) = %lf, expected %lf\n",
			height, base1, base2, output, expected_output);
	}
}

int main()
{
	check_length(0,0,0);
	check_length(6,2.3622,0.01);
	check_length(500,196.85,0.01);
	check_length(-30,-1,0);

	check_trap(5,10,14,60,0.01);
	check_trap(100,500,600,55000,0.01);

	check_trap(0,10,14,0,0);
	check_trap(5,10,0,0,0);
	check_trap(5,0,14,0,0);

	print_number_triangle(5);
	print_number_triangle(0);
	print_number_triangle(100);
	print_number_triangle(1000);
}