#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/* memory_new
 * create a new memory struct, initialze its address and size
 */
memory* memory_new(unsigned int addr, unsigned int size){
  memory* m = (memory*)malloc(sizeof(memory));
  m->addr = addr;
  m->size = size;
  return m;
}

/* free the dynamically allocated memory struct
 */
void memory_free(void* p){
  memory* m = (memory*)p;
  free(m);
}

/* compare two memory variables x and y by address 
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
int memory_addr_cmp(const void* x, const void* y){
  memory* xm = (memory*)x;
  memory* ym = (memory*)y;

  if(xm -> addr > ym -> addr){
    return 1;
  }
  else if(xm -> addr < ym -> addr){
    return -1;
  }
  else{
    return 0;
  }
}

/* compare two memory variables x and y by size 
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
int memory_size_cmp(const void* x, const void* y){
  memory* xm = (memory*)x;
  memory* ym = (memory*)y;

  if(xm -> size > ym -> size){
    return 1;
  }
  else if(xm -> size < ym -> size){
    return -1;
  }
  else{
    return 0;
  }
}

/* print the memory address and size
 */
void memory_print(void* data){
  if (data == NULL) return;
  memory* m = (memory*)data;
  printf("address: %u, size: %u\n", m->addr, m->size);
}