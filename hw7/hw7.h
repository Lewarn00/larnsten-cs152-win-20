#include "bst.h"

#ifndef HW7_H
#define HW7_H

#define BUFSIZ 120

bst* read_memory_blocks(char *filename, 
  int (*cmp)(const void* x, const void* y));

#endif