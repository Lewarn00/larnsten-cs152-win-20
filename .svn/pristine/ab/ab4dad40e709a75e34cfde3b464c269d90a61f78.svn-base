#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/* memory_new
 * create a new memory struct, initialze its address and size
 */
memory* memory_new(void* addr, unsigned int size){
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
  memory* ym = (memory*)y;

  if(x > ym -> size){ 
    return 1;
  }
  else if(x < ym -> size){ 
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
  printf("address: %p, size: %u\n", m->addr, m->size);
}

//A function to allocate a new memory page.
memory *allocate_memory_page(){
  void *rev_val;
  memory *memory = malloc(sizeof(memory));
  memory -> addr = malloc(4096);
  memory -> size = 4088;
  rev_val = memory;
  return rev_val;
}

//A function to split memory at a certain size.
void *split_memory(memory* data, unsigned int size_desired){
  void *rev_val;
  char *pc = (char*)(data -> addr);
  pc += size_desired;
  rev_val = (void*)pc;
  return rev_val;
}

//A function to merge two memory structs if their addresses are adjacent.
memory *merge_memory(memory *first, memory *second){
	if((first -> addr) + (first -> size) + 8 == (second -> addr)){
		first -> size = first -> size + second -> size;
		memory_free(second);

		return first;
	}

	return NULL;
}
