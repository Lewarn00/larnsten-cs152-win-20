#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hw5.h"

int main(int argc, char *argv[])
{

	char func_num = *argv[1];

	switch (func_num)
	{
	    case '0':
	    {
	    	char *str1 = argv[2];
	        printf("String: %s, Allocated length: %u, Expected string: %s\n", 
	        	make_string(str1) -> str, make_string(str1) -> allocated_length, argv[3]);
	        break;
	    }
	    case '1': 
	    {
	    	char dest[20];
	    	safe_string *d = make_string(dest);
	    	safe_string *s = make_string(argv[2]);
	    	safe_str_cpy(d, s);
	    	printf("String in destination: %s, Allocated length: %u, Expected string: %s\n", 
	    		d -> str, d -> allocated_length, argv[3]);
	        break;
	    }
	    case '2':
	    {
	    	safe_string *d = make_string(argv[2]);
	    	safe_string *s = make_string(argv[3]);

	        safe_str_cat(d, s);
	    	printf("String in destination: %s, Allocated length: %u, Expected string: %s\n", 
	    		d -> str, d -> allocated_length, argv[4]);
	        break;
	    }
	    case '3': 
	    {
	    	safe_string *str1 = make_string(argv[2]);
	    	char c = argv[3][0];
	        printf("Result: %s, Expected %s\n", safe_strchr(str1,c), argv[4]);

	        break;
	    }    
	    case '4': 
	    {
	    	safe_string *s1 = make_string(argv[2]);
	    	safe_string *s2 = make_string(argv[3]);

	        printf("Output: %d, Expected %s\n", safe_strcmp(s1, s2), argv[4]);
	        break;
	    }             
	    default:
	    	printf("Error in first argument.\n");
	}
}