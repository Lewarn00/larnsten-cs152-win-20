#include <stdio.h>
#include <stdlib.h>
#include "my_alloc.h"
#include "memory.h"
#include "bst.h"
#include "llist.h"

int main()
{
  //Test init_alloc
  init_alloc();

  //Testing my_malloc
  memory *new_memory3 = my_malloc(50); //includes allocate_memory_page
  memory *new_memory2 = my_malloc(1);  //Prints with wrong size
  memory *new_memory1 = my_malloc(0); 
  //Testing print memory
  print_memory();

  //Testing my_free
  my_free(4040);
  printf("Memory after free:\n");
  print_memory();

  bst *t = bst_new(memory_size_cmp);
  memory *m1 = memory_new(0, 10);
  memory *m2 = memory_new(18, 26);
  memory *m3 = memory_new(10, 18);
  memory *m4 = memory_new(26, 50);
  memory *m5 = memory_new(10, 18);
  bst_insert(t, m1);
  bst_insert(t, m2);
  bst_insert(t, m3);
  bst_insert(t, m4);
  bst_insert(t, m5);

  //As these is an error in my_malloc, testing bst_item_or_successor
  memory *m6 = memory_new(28, 19);
  memory *got = bst_item_or_successor(t, m6);
  //printf("Closest (>) chunck on memory to size 19: %u\n", got -> addr);

  //Testing split_memory
  void *split1 = split_memory(m3, 1);
  void *split2 = split_memory(m4, 10);
  void *split3 = split_memory(m5, 0);
  printf("Split: %u, Expected: 11\n", split1);
  printf("Split: %u, Expected: 36\n", split2);
  printf("Split: %u, Expected: 10\n", split3);

  //Testing merge_memory
  memory *merge1 = merge_memory(m1, m2);
  memory *merge2 = merge_memory(m5, m4);
  printf("Merged size: %u, Expected: 36\n", merge1 -> size);
  printf("Merged: %s, Expected: NULL\n", merge2);
 
  //Test compact_memory, iterator not working
  compact_memory();
  print_memory();
}