#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup5.h"
#include "warmup5_provided.h"

//A function to safely concat two strings.
char *safe_str_concat(char *str1, char *str2){
	int len1 = strlen(str1); 
	int len2 = strlen(str2);


	char *new_array = malloc(len1 + len2 + 1); 

	if (new_array == NULL){
		return NULL;
	}

	memcpy(new_array, str1, len1);
	memcpy(new_array + len1, str2, len2);

	return new_array;
}

//A function to initialize an int_vector.
int_vector* make_init_array(){
	int initial_size = 16; 
	int_vector *v1; 

	v1 = malloc(sizeof(int_vector));
	v1 -> array = malloc(initial_size * sizeof(int));

	v1 -> allocated_size = initial_size;

	for(int i = 0; i < initial_size; i++){
		v1 -> array[i] = 0;
	}

	return v1;
}

//A function to write a value to a vector at a given index.
void write_value(int_vector *vector, unsigned int index, int value){
	if(index > (vector -> allocated_size)){
		if((2 * (vector -> allocated_size)) < index){

			int *bigger_array = malloc((index + 1) * sizeof(int));
			memcpy(bigger_array, vector -> array, vector -> allocated_size + 1);
			free(vector -> array);
			vector -> allocated_size = index + 1;

			bigger_array[index] = value;
			vector -> array = bigger_array;
		}
		else{

			int new_size = 2 * (vector -> allocated_size);
			int *bigger_array = malloc(new_size * sizeof(int));
			memcpy(bigger_array, vector -> array, vector -> allocated_size + 1);
			free(vector -> array);
			vector -> allocated_size = new_size;

			bigger_array[index] = value;
			vector -> array = bigger_array;
		}
	}
	else{
		vector -> array[index] = value;
	}
}

//A function to read a value from a vector at a given index.
int read_value(int_vector *vector, unsigned int index){
	if(index > (vector -> allocated_size)){
		return 0;
	}
	else{
		int value = vector -> array[index];
		return value;
	}
}

//A function to create a picture with the given specifications.
pixel** make_and_init_image(int height, int width, pixel color){

	pixel **pic = malloc(sizeof(pixel *) * height);
	for(int i = 0; i < height; i++){
		pic[i] = malloc(sizeof(pixel) * width);
		for (int j = 0; j < width; j++){
			pic[i][j].red = color.red;
			pic[i][j].green = color.green;
			pic[i][j].blue = color.blue;
		}
	}

	return pic;
}

