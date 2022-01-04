#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw5.h"

//A function to create an empty safe string.
safe_string* make_empty_string(){
	safe_string *s1 = malloc(sizeof(safe_string));
	s1 -> str = malloc(sizeof(char));
	s1 -> allocated_length = 1;
	s1 -> str[0] = '\0';
	return s1;
}

//A function to create a safe string from a string.
safe_string* make_string(char *str){

	if (str == NULL){
		return make_empty_string();
	}

	safe_string *s1 = malloc(sizeof(safe_string)); 

	int size = strlen(str);
	s1 -> str = malloc(sizeof(char) * size + 1); 
	s1 -> allocated_length = size + 1;

	memcpy(s1 -> str, str, size);

	return s1;	
}

//A function to copy a string to a destination address.
void safe_str_cpy(safe_string *dest, safe_string *src){
	int og_str_length = strlen(src -> str) + 1;
	int og_alloc_length = src -> allocated_length;
	int new_alloc_length = dest -> allocated_length;

	if(new_alloc_length <= og_str_length){
		char *new_string = malloc(og_alloc_length * sizeof(char) + 1);
		new_string = src -> str;
		free(src -> str);
		dest -> str = new_string; 
		dest -> allocated_length = og_alloc_length;
	}
	else{
		dest -> str = src -> str; 
	}
}

//A function to concat two strings together.
void safe_str_cat(safe_string *dest, safe_string *src){
	int og_length = strlen(src -> str); 
	int new_length = strlen(dest -> str); 

	if(new_length + og_length > (dest -> allocated_length)){
		char *new_string = malloc((og_length + new_length) * sizeof(char) + 1);
		memcpy(new_string, dest -> str, new_length);
		memcpy(new_string + (new_length * sizeof(char)), src -> str, og_length);

		free(src -> str);
		free(dest -> str);

		dest -> str = new_string;
		dest -> allocated_length = og_length + new_length + 1;
	}
	else{
		memcpy((dest -> str) + (og_length * sizeof(char)), src -> str, og_length); 
		dest -> allocated_length = og_length + new_length + 1;
	}
}

//A function to return a pointer to the appearance 
//of the character in the string.
char *safe_strchr(safe_string *s, char c){
	for(int i = 0; i < (strlen(s -> str)); i++){
		if(s -> str[i] == c){
			return s -> str + (i * sizeof(char));
		}	
	}

	return NULL;
}

//A function to compare two strings, return 1 if the first string 
//is later alphabetically, 0 if they are equal,
//and -1 if the first string is earlier.
int safe_strcmp(safe_string *s1, safe_string *s2){
	int comp_first_letter = 0;

	for(int i = 0; i < (strlen(s1 -> str)); i++){
		if(comp_first_letter == 0){ 
			if(s2 -> str[i] >= 'A' && s2 -> str[i] <= 'Z' 
				&& s1 -> str[i] >= 'a' && s1 -> str[i] <= 'z'){
				comp_first_letter = 1;
			}
			else if(s1 -> str[i] >= 'A' && s1 -> str[i] <= 'Z' 
				&& s2 -> str[i] >= 'a' && s2 -> str[i] <= 'z'){
				comp_first_letter = -1;
			}
			else if(s2 -> str[i] == s1 -> str[i]){ 
				comp_first_letter = 0;
			}
			else if(s2 -> str[i] > s1 -> str[i]){
				comp_first_letter = -1;
			}
			else{
				comp_first_letter = 1;
			}
		}
	}

	if(comp_first_letter == 0 && strlen(s1 -> str) == strlen(s2 -> str)){
		comp_first_letter = 0;
	}else if(comp_first_letter == 0 && strlen(s1 -> str) > strlen(s2 -> str)){
		comp_first_letter = 1;
	}else if(comp_first_letter == 0 && strlen(s1 -> str) < strlen(s2 -> str)){
		comp_first_letter = -1;
	}
	return comp_first_letter;
}

