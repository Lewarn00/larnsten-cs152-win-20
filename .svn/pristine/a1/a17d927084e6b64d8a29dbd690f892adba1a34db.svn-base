#ifndef HW6_H
#define HW6_H

typedef unsigned int uint;

enum Category { GROCERY=0, OFFICE, PHARMACY, HOBBY};
#define NUM_CATEGORIES 4

typedef struct {
 enum Category category;
 char name[40];
 uint productID;
 uint current_stock;
 uint min_for_restock;
 uint max_after_restock;
} product_info;

// for the linked list, we will use the following struct
typedef struct _node node;

struct _node{
 product_info *product;
 node *next;
};

extern char *category_strings[];
void print_product(product_info *g, FILE *fp);
void print_list(node *head, FILE *fp);

product_info *create_product(char *name, char *category, uint id,
				uint current, uint mn, uint mx);

node* insert_head(node *head, product_info *pinfo);

product_info *find(node *head, uint pID);

void record_restocked_single(node *head, uint pID);
void product_sold(node *head, uint pID);
node *add_sorted_productID(product_info *pinfo, node *head);
node *add_sorted_category_ID(product_info *pinfo, node *head);
node *make_restock_list(node *head);
void record_restocked_list(node *restocked_list, node *head);

#endif