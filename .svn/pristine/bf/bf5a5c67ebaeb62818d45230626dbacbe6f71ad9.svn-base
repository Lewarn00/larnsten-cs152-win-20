#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw7.h"
#include "bst.h"
#include "memory.h"

//A function to read in a file and split it into memory blocks
//Then inset into a bst with given cmp function
bst* read_memory_blocks(char *filename, 
  int (*cmp)(const void* x, const void* y)){

  bst *t = bst_new(cmp);

  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Could not open file %s for reading\n",filename);
    exit(1);
  }


  char buf[BUFSIZ] = "Garbage";
  int i = 0;

  while (fgets(buf, sizeof(buf), fp) != NULL)
  {

    unsigned int addr;
    unsigned int size;
    char *tmp;

    tmp = strtok(buf," ,\n\r");
    addr = atoi(tmp);

    tmp = strtok(NULL," ,\n\r");
    size = atoi(tmp);

    memory *m = memory_new(addr, size);

    bst_insert(t, m);

    i++;
  }

  return t;
}