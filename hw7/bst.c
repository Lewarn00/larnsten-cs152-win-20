#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/* malloc a new node and assign the data
 * pointer to its data field
 */
node* node_new(void* data){
  node *n = malloc(sizeof(node));
  n -> data = data;
  n -> left = NULL;
  n -> right = NULL;

  return n;
}

/* create a new bst, initialize its root to be NULL
 */
bst* bst_new(int (*cmp)(const void* x, const void* y)){
  bst *t = malloc(sizeof(bst));
  t -> cmp = cmp;
  t -> root = NULL;

  return t;
}

//Helper function for node_delete
node *subtree_insert(node *root, node *new,
  int (*cmp)(const void* x, const void* y)){
  if(root == NULL){
    return new;
  }
  int c = cmp(new -> data, root -> data);
  if(c <= 0){
    root -> left = subtree_insert(root -> left, new, cmp);
  } 
  else{
    root -> right = subtree_insert(root -> right, new, cmp);
  }
  return root;
}

/* Insert a node to to a subtree with a root node as parameter
 * Insertion is in sorted order. 
 * Return the new root of the modified subtree.  
 */
node* node_insert(node* root, void* data, 
  int (*cmp)(const void* x, const void* y)){
  return subtree_insert(root, node_new(data), cmp);
}

/* Insert a new node to the bst
 */
void bst_insert(bst* b, void* data){
  b -> root = node_insert(b -> root, data, b -> cmp);
}

/* delete a node from a subtree with a given root node
 * use the comparison function to search the node and delete 
 * it when a matching node is found. This function only
 * deletes the first occurrence of the node, i.e, if multiple 
 * nodes contain the data we are looking for, only the first node 
 * we found is deleted. 
 * Return the new root node after deletion.
 */
node* node_delete(node* root, void* data, 
  int (*cmp)(const void* x, const void* y)){
  if(root == NULL){
    return NULL;
  }

  int c = cmp(data, root -> data);
  if(c == 0){
    if(root -> left == NULL && root -> right == NULL){ 
      free(root);
      root = NULL;
    }
    else if(root -> left == NULL && root -> right != NULL){
      root = root -> right; 
    }
    else if(root -> left != NULL && root -> right == NULL){
      root = root -> left; 
    }
    else{
      node *temp = root -> left;
      root = subtree_insert(root -> right, temp, cmp);
    }    
  }
  else if(c < 0){
    root -> left = node_delete(root -> left, data, cmp);
  }
  else{
    root -> right = node_delete(root -> right, data, cmp);
  }
  return root;  
}

/* delete a node containing data from the bst
 */
void bst_delete(bst* b, void* data){
  b -> root = node_delete(b -> root, data, b -> cmp);
}

/* Search for a node containing data in a subtree with
 * a given root node. Use recursion to search that node. 
 * Return the first occurrence of node. 
 */
void* node_search(node* root, void* data, 
  int (*cmp)(const void* x, const void* y)){
  if(root == NULL){
    return NULL;
  }
  int c = cmp(data, root -> data);
  if(c == 0){
    return root -> data; 
  }
  else if(c < 0){
    return node_search(root -> left, data, cmp);
  }
  else{
    return node_search(root -> right, data, cmp);
  }

}

/* Search a node with data in a bst. 
 */
void* bst_search(bst* b, void* data){
  return node_search(b -> root, data, b -> cmp);
}

/* traverse a subtree with root in ascending order. 
 * Apply func to the data of each node. 
 */
void inorder_traversal(node* root, void(*func)(void* data)){
  if(root == NULL){
    return;
  }

  inorder_traversal(root -> left, func);
  func(root -> data);
  inorder_traversal(root -> right, func);
}

/* traverse a bst in ascending order. 
 * Apply func to the data of each node. 
 */
void bst_inorder_traversal(bst* b, void(*func)(void* data)){
  inorder_traversal(b -> root, func);
}

/* free the bst with 
 */
void bst_free(bst* b){
  bst_inorder_traversal(b, free);
  free(b);
}
