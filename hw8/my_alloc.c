#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "memory.h"
#include "llist.h"

/* Global variables
 * By declaring these outside of a function:
 *   Scope: Every function inside of this file may use them. 
 *   		No functions in other files may use them.
 *   Lifetime: They exist for the entire program - they are created
 *		when the program begins and exist until the program
 *		ends.
 */   		

/* This is the tree that holds the available memory. */
bst *avail_mem = NULL; //init_alloc()

/* This includes all of the functions for the memory allocator.
 * The last two functions (my_malloc and my_free) are public 
 * functions with prototypes in the header function. The rest of the
 * functions are helper functions only called by my_malloc and 
 * my_free. You must implement these helper functions. If you wish,
 * you may add helper functions we did not define.
 */

/* compact_memory
 *
 * Search through all available memory and attempt to merge memory
 * that is stored next to each other.
 * This uses global variable avail_mem, so it does not need any
 * input parameters. Look at the bst functions and memory functions.
 */
void compact_memory()
{
	memory *item, *prev;
	for(item = bst_iterate(avail_mem); item != NULL; prev = item, item = bst_iterate(NULL)){
		memory *merged = merge_memory(prev, item);
		if(merged){
			bst_delete(avail_mem, item);
			memory *m = bst_search(avail_mem, prev -> addr);
			m = merged;
		}
	}
}

/* print_available_memory 
 *
 * Print out all available memory in ascending order by size.
 */
void print_memory()
{
	bst_inorder_traversal(avail_mem, memory_print);
}

/* init_alloc
 *
 * Initializes the data structures. This initializes avail_mem so 
 * that, instead of being a NULL pointer, it points to a valid bst
 * struct whose root pointer is NULL.
 */
void init_alloc()
{
	static unsigned int called = 0;

	if(called == 0){
		bst *b = bst_new(memory_size_cmp); 
		avail_mem = b;
	}

	called++;
}

/* my_malloc
 * 
 * function that finds a piece of available memory that is at least
 * num_bytes size. A pointer to the beginning of the usable piece of
 * that chunk is returned.
 */
void *my_malloc(int num_bytes)
{
	if(num_bytes < 24){
		num_bytes = 24;
	}
	if(num_bytes % 8 != 0){
		num_bytes = num_bytes + (8 - (num_bytes % 8));
	}
	
	memory *chunk_of_mem = NULL;
	int size = 0;
	void *addr = NULL;

	if(bst_item_or_successor(avail_mem, num_bytes) != NULL){
		chunk_of_mem = (memory *)bst_item_or_successor(avail_mem, num_bytes);
		size = chunk_of_mem -> size;
		addr = chunk_of_mem -> addr;
	}

	if(size >= 2 * num_bytes){
		memory *tmp = memory_new(chunk_of_mem -> addr, chunk_of_mem -> size);
		bst_delete(avail_mem, chunk_of_mem);

		memory *retval = split_memory(tmp, num_bytes);
		tmp -> addr = retval;
		tmp -> size = (tmp -> size) - num_bytes;
		bst_insert(avail_mem, tmp);

		return addr;
	}
	else if(size <= 2 * num_bytes && size >= num_bytes){
		memory *tmp = memory_new(chunk_of_mem -> addr, chunk_of_mem -> size);
		bst_delete(avail_mem, chunk_of_mem);

		return addr;
	}
	else{
		memory *retval = allocate_memory_page();
		retval -> addr = (retval -> addr) + num_bytes;
  		retval -> size = (retval -> size) - num_bytes;

		bst_insert(avail_mem, retval);
		return retval -> addr - num_bytes;
	}

	return NULL;
}

/* my_free
 * 
 * Function that returns the memory chunk whose usable piece starts
 * at that address back to the set of available memory so that it can
 * be reused in a subsequent free call
 */
void my_free(void *address)
{
	memory *m = bst_search(avail_mem, address - 8);
	bst_delete(avail_mem, m);
	memory *tmp = allocate_memory_page();	
	bst_insert(avail_mem, tmp);
}