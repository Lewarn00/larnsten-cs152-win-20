#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

char *category_strings[] = { "Grocery", "Office", "Pharmacy", "Hobby"};

void print_product(product_info *p, FILE *fp)
{
	fprintf(fp,"%s (%u) %s:",p->name, p->productID,
		category_strings[p->category]);
	fprintf(fp, "current: %u, min: %u, max: %u",
		p->current_stock, p->min_for_restock, p->max_after_restock);
}

void print_list(node *head, FILE *fp)
{
	node *tmp;
	printf("Product Status:\n");
	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		print_product(tmp->product,fp);
		printf("\n");
	}
}

//A function to create a product with the given information.
product_info *create_product(char *name, char *category, uint id,
				uint current, uint mn, uint mx){
	product_info *p = malloc(sizeof(product_info));

	if(strcmp(category, "Grocery") == 0) {
		p -> category = 0;
	}
	if(strcmp(category, "Office") == 0) {
		p -> category = 1;
	}
	if(strcmp(category, "Pharmacy") == 0) {
		p -> category = 2;
	}
	if(strcmp(category, "Hobby") == 0) {
		p -> category = 3;
	}
	*(p -> name) = malloc(40 * sizeof(char));
	memcpy(p -> name, name, strlen(name) + 1);
	p -> productID = id;
	p -> current_stock = current;
	p -> min_for_restock = mn;
	p -> max_after_restock = mx;

	return p;
}

//A function to inset a product at the head of a linked list
node* insert_head(node *head, product_info *pinfo){
	node *newnode;
	newnode = (node *)malloc(sizeof(node));
	newnode -> product = pinfo;
	newnode -> next = head;
	head = newnode;
	
	return head;
}

//A function to find a product with a given ID
product_info *find(node *head, uint pID){
	node *tmp;

	for(tmp = head; tmp != NULL; tmp = tmp -> next){
		if( ((tmp -> product) -> productID) == pID){
			return tmp -> product;
		}
	}

	return NULL;
}

//A function to change the current stock of a product to its max after restock
void record_restocked_single(node *head, uint pID){
	node *tmp;

	for(tmp = head; tmp != NULL; tmp = tmp -> next){
		if( ((tmp -> product) -> productID) == pID){
			(tmp -> product) -> current_stock = (tmp -> product) -> max_after_restock;
		}
	}
}

//A function to decrement a product's stock by one unit when it is sold
void product_sold(node *head, uint pID){
	node *tmp;

	for(tmp = head; tmp != NULL; tmp = tmp -> next){
		if( ((tmp -> product) -> productID) == pID){
			((tmp -> product) -> current_stock)--;
		}
	}
}

//A function to sort products into a list by ID
node *add_sorted_productID(product_info *pinfo, node *head){

	node *curr, *prev, *newnode;
	
	if(head == NULL){
		newnode = (node *)malloc(sizeof(node));
		newnode -> product = pinfo;
		newnode -> next = NULL;
		head = newnode;

		return head;
	}

	for(curr = head, prev = NULL; curr != NULL; prev = curr, curr = curr -> next){
		if( ((curr -> product) -> productID) >= (pinfo -> productID) ){
			newnode = (node *)malloc(sizeof(node));
			newnode -> product = pinfo;
			newnode -> next = curr;
			if (prev != NULL) {
				prev -> next = newnode;
			}
			else{
				head = newnode;
			}

			return head;
		}
	}
	
	if(curr == NULL){
		newnode = (node *)malloc(sizeof(node));
		newnode -> product = pinfo;
		newnode -> next = NULL;
		prev -> next = newnode;

		return head;
	}
}

//A function to sort products into a list by category, then ID
node *add_sorted_category_ID(product_info *pinfo, node *head){
	
	node *curr, *prev, *newnode;

	if(head == NULL){
		newnode = (node *)malloc(sizeof(node));
		newnode -> product = pinfo;
		newnode -> next = NULL;
		head = newnode;

		return head;
	}
	
	for(curr = head, prev = NULL; curr != NULL; prev = curr, curr = curr -> next){
		if( ((curr -> product) -> category) > (pinfo -> category) ){
			newnode = (node *)malloc(sizeof(node));
			newnode -> product = pinfo;
			newnode -> next = curr;
			if (prev != NULL) {
				prev -> next = newnode;
			}
			else{
				head = newnode;
			}

			return head;
		}
		if( ((curr -> product) -> category) == (pinfo -> category) ){
			if( ((curr -> product) -> productID) >= (pinfo -> productID) ){
				newnode = (node *)malloc(sizeof(node));
				newnode -> product = pinfo;
				newnode -> next = curr;
				if (prev != NULL) {
					prev -> next = newnode;
				}
				else{
					head = newnode;
				}

				return head;
			}
		}		
	}

	if(curr == NULL){
		newnode = (node *)malloc(sizeof(node));
		newnode -> product = pinfo;
		newnode -> next = NULL;
		prev -> next = newnode;

		return head;
	}
}

//A function to make a new linked list with products that need to be restocked
node *make_restock_list(node *head){
	node *new_list = NULL;

	node *tmp1;
 	for(tmp1 = head; tmp1 != NULL; tmp1 = tmp1 -> next){
		if( (tmp1 -> product) -> current_stock < (tmp1 -> product) -> min_for_restock ){
			new_list = add_sorted_productID(tmp1 -> product, new_list);
		}
	}

	if(new_list == NULL || head == NULL){
		return NULL;
	}
	else{
		return new_list;
	}
}

//A function to restock items that need to be restocked
void record_restocked_list(node *restocked_list, node *head){
	node *tmp;
	product_info *restocked_p;

	for(tmp = restocked_list; tmp != NULL; tmp = tmp -> next){
		if(find(head, (tmp -> product) -> productID) != NULL){
			restocked_p = find(head, (tmp -> product) -> productID);
			record_restocked_single(head, restocked_p -> productID);
		}
	}
}
