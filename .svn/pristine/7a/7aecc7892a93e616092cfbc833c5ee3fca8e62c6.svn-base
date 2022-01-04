#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup5_provided.h"
#include "warmup5.h"

//A helper function to print int_vector.
void print_int_vec(int_vector *v)
{
	for (int i = 0; i < v -> allocated_size; i ++) {
		printf("%d", v -> array[i]);
	}
}

//A helper function to put digits in their correct place.
int e_n(int n)
{
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= 10;
	}
	return res;
}

//A helper function to convert strings to integers.
int str_to_int(char *s)
{
	int res = 0;
	int i_;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		i_ = strlen(s) - i;
		res += e_n(i_ - 1) * ((int)s[i] - '0');
	}
	return res;
}

int main(int argc, char *argv[])
{	
	char func_num = *argv[1];

	switch (func_num)
	{
	    case '0':
	    {
	    	char *str1 = argv[2];
	    	char *str2 = argv[3];
	        printf("New string: %s, Expected: %s\n", safe_str_concat(str1, str2), argv[4]);
	        break;
	    }
	    case '1': 
	    {
	    	int_vector *v = make_init_array();

	    	for(int i = 0; i < strlen(argv[2]); i++){
	    		write_value(v,i, (int) argv[2][i] - '0');
	    	}

	    	int index = str_to_int(argv[3]);
	    	int value = str_to_int(argv[4]);
	    	write_value(v , index, value);
	    	print_int_vec(v);
	    	printf(" Allocated_size: %u, Expected array: %s, Expected size: %s \n", v -> allocated_size, argv[5],argv[6]);
	        break;
	    }
	    case '2':
	    {
	    	int_vector *v = make_init_array();

	    	for(int i = 0; i < strlen(argv[2]); i++){
	    		write_value(v,i, (int) argv[2][i] - '0');
	    	}

	    	int index = str_to_int(argv[3]);
	        printf("Value: %u, expected: %s \n",read_value(v , index), argv[4]); 
	        break;
	    }
	    case '3': 
	    {
	    	pixel p;
	    	p.red = str_to_int(argv[4]);
	    	p.green = str_to_int(argv[5]);
	    	p.blue = str_to_int(argv[6]);
	    	int height = str_to_int(argv[2]);
	    	int width = str_to_int(argv[3]);
	        pixel** image = make_and_init_image( height, width, p);	
	        provided_write_png_struct(argv[7], image, width, height);

	        break;
	    }               
	    default:
	    	printf("Error in first argument.\n");
	}
}
