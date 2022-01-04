#include <stdio.h>
#include <stdlib.h>
#include "hw7.h"
#include "bst.h"
#include "memory.h"

#define BUFSIZ 120

void display_file(char *filename)
{
  FILE *fp;
  char buf[BUFSIZ] = "Garbage";
  int i;

  // attempt to open the file, then check whether that worked.
  if ((fp = fopen(filename, "r")) == NULL)
  {
    fprintf(stderr,"Could not open file %s\n",filename);
    exit(1);
  }

  // for each line of the file, read it in and then print it out
  i = 0;
  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    printf ("Line %4d: %s", i, buf);
    i++;
  }

  printf("\n");
  fclose(fp);
}

int main(int argc, char *argv[])
{
  char *filename = argv[1];
  display_file(filename);

  //Testing for bst_insert and bst_new (includes node_new, node_insert)
  printf("Tree created from file using address:\n");
  bst *t_addr = read_memory_blocks(filename, memory_addr_cmp);
  //Testing bst_inorder_traversal (includes inorder_traversal) 
  //to print out the binary tree that was created.
  bst_inorder_traversal(t_addr, memory_print);

  //Testing bst_search (includes node_search)
  memory *m1 = memory_new(1, 200);
  memory *m2 = memory_new(5, 150);
  memory *m3 = memory_new(10, 10);
  printf("Testing bst_search, got: %u %u, expected: 1 200\n", 
    ((memory*)bst_search(t_addr, m1)) -> addr, 
    ((memory*)bst_search(t_addr, m1)) -> size);
  printf("Testing bst_search, got: %u %u, expected: 5 150\n", 
    ((memory*)bst_search(t_addr, m2)) -> addr, 
    ((memory*)bst_search(t_addr, m2)) -> size);
  printf("Testing bst_search, got: %s, expected: NULL\n", 
    (memory*)bst_search(t_addr, m3));

  //Testing bst_delete (includes node_delete)
  bst_delete(t_addr, m1);
  printf("Testing bst_delete: 1, 200 deleted\n");
  bst_inorder_traversal(t_addr, memory_print);
  bst_delete(t_addr, m2);
  printf("Testing bst_delete: 5, 150 deleted\n");
  bst_inorder_traversal(t_addr, memory_print);
  bst_delete(t_addr, m3);
  printf("Testing bst_delete: non-existant node deleted\n");
  bst_inorder_traversal(t_addr, memory_print);

  //Testing bst_free
  bst_free(t_addr);
  printf("Testing bst_free: tree should be empty\n");
  bst_inorder_traversal(t_addr, memory_print);

  printf("Tree created from file using size:\n");
  bst *t_size = read_memory_blocks(filename, memory_size_cmp);
  bst_inorder_traversal(t_size, memory_print);
}