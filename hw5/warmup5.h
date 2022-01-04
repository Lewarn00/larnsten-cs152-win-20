#include "warmup5_provided.h"

#ifndef WARMUP5_H
#define WARMUP5_H

char *safe_str_concat(char *str1, char *str2);

typedef struct {
	unsigned int allocated_size;
	int *array;
} int_vector;

int_vector* make_init_array();

void write_value(int_vector *vector, unsigned int index, int value);
int read_value(int_vector *vector, unsigned int index);

pixel** make_and_init_image(int height, int width, pixel color);

#endif