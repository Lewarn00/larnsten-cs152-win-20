#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

int main(int argc, char *argv[])
{
	// make sure there are two arguments - hw5 and filename
	if (argc < 2)
	{
		printf("Usage: ./hw6 filename. Missing filename\n");
		exit(1);
	}
	char *filename = argv[1];

	// open file for reading
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s for reading\n",filename);
		exit(2);
	}

	// read in each record from the file
	char buffer[BUFSIZ];
	node *testnode = NULL;
	while (!feof(fp) && (fgets(buffer,500,fp) != NULL))
	{
		// parse the line to split up the fields
		char *category;
		char *name;
		uint pID;
		uint current_stock;
		uint min_stock;
		uint max_stock;
		char *tmp_s;

		// first field is category
		category = strtok(buffer," ,\n\r");
		// second field is name
		name = strtok(NULL," ,\n\r");
		// third is pID;
		tmp_s = strtok(NULL," ,\n\r");
		pID = atoi(tmp_s);
		// fourth is current
		tmp_s = strtok(NULL," ,\n\r");
		current_stock = atoi(tmp_s);
		// fifth is min
		tmp_s = strtok(NULL," ,\n\r");
		min_stock = atoi(tmp_s);
		// sixth is max
		tmp_s = strtok(NULL," ,\n\r");
		max_stock = atoi(tmp_s);

		printf("Read in record: %s, %s, %u, %u, %u, %u\n",
			category, name, pID, current_stock, min_stock,
			max_stock);

		// now you need to write the code to create a record, testing create_product
		product_info *p = create_product(name, category, pID, current_stock, min_stock, max_stock);
		// and put that record into the linked list, testing insert_head
		//Should return a linked list in opposite order to the one inputed
		testnode = insert_head(testnode, p);
	}

	node *tmp1;
	node *test_sorted_ID = NULL;
	for(tmp1 = testnode; tmp1 != NULL; tmp1 = tmp1 -> next){
		test_sorted_ID = add_sorted_productID(tmp1 -> product, test_sorted_ID);
	}

	node *tmp2;
	node *test_sorted_category = NULL;

	for(tmp2 = testnode; tmp2 != NULL; tmp2 = tmp2 -> next){
		test_sorted_category = add_sorted_category_ID(tmp2 -> product, test_sorted_category);
	}	

	//Testing insert head
	FILE *fp1 = fopen("test_insert_head.txt", "w");
	print_list(testnode, fp1);
	//Testing add_sorted_productID
	FILE *fp2 = fopen("test_sorted_ID.txt", "w");
	print_list(test_sorted_ID, fp2);
	//Testing add_sorted_category_ID
	FILE *fp3 = fopen("test_sorted_category.txt", "w");
	print_list(test_sorted_category, fp3);

	//Testing find
	printf("Found: %s, expected: null\n",find(testnode, 1341));
	printf("Found %s, expected: Butter\n",find(test_sorted_ID, 2956) -> name);
	printf("Found %s, expected: BugSpray\n",find(testnode, 2653) -> name);

	//Testing product_sold
	product_sold(testnode, 38590);
	product_sold(testnode, 23765);
	product_sold(testnode, 92656);
	printf("Decremented: %u, expected: 16\n", find(testnode, 38590) -> current_stock);
	printf("Decremented: %u, expected: 4\n", find(testnode, 23765) -> current_stock);
	printf("Decremented: %u, expected: 8\n", find(testnode, 92656) -> current_stock);

	//Testing record_restocked_single
	record_restocked_single(testnode, 38590);
	record_restocked_single(testnode, 23765);
	record_restocked_single(testnode, 92656);
	printf("When restocked: %u, expected: 30\n", 
		find(testnode, 38590) -> current_stock);
	printf("When restocked: %u, expected: 8\n", 
		find(testnode, 23765) -> current_stock);
	printf("When restocked: %u, expected: 12\n", 
		find(testnode, 92656) -> current_stock);

	product_info *p = create_product("apple", "Grocery", 2450, 10, 5, 20);
	product_info *p1 = create_product("berry", "Grocery", 2453, 3, 5, 15);
	product_info *p2 = create_product("pen", "Office", 2451, 2, 5, 18);	
	product_info *p3 = create_product("cup", "Office", 2452, 6, 5, 35);
	product_info *p4 = create_product("pencil", "Office", 2449, 2, 5, 40);

	//Creating linked list to test restocking
	node *for_restock_list = NULL;
	for_restock_list = insert_head(for_restock_list, p);
	for_restock_list = insert_head(for_restock_list, p1);
	for_restock_list = insert_head(for_restock_list, p2);
	for_restock_list = insert_head(for_restock_list, p3);
	for_restock_list = insert_head(for_restock_list, p4);

	node *for_restock_list1 = NULL;
	for_restock_list1 = insert_head(for_restock_list, p);

	node *for_restock_list2 = NULL;

	//Testing make_restock_list
	node *restock_list = NULL;
	restock_list = make_restock_list(for_restock_list);
	printf("Restocked value: %u, expected: null\n", 
		make_restock_list(for_restock_list1));
	printf("Restocked value: %u, expected: null\n", 
		make_restock_list(for_restock_list2));
	printf("Restocked value: %s, expected: pencil\n", 
		(restock_list -> product) -> name);
	printf("Restocked value: %s, expected: pen\n", 
		(restock_list -> next -> product) -> name);
	printf("Restocked value: %s, expected: berry\n", 
		(restock_list -> next -> next -> product) -> name); 

	//Testing record_restocked_list
	record_restocked_list(restock_list, for_restock_list);
	printf("Restocked value: %u, expected: 40\n", 
		(for_restock_list -> product) -> current_stock);
	printf("Restocked value: %u, expected: 6\n", 
		(for_restock_list -> next -> product) -> current_stock);
	printf("Restocked value: %u, expected: 18\n", 
		(for_restock_list -> next -> next -> product) -> current_stock);
	printf("Restocked value: %u, expected: 15\n", 
		(for_restock_list -> next -> next -> next -> product) -> current_stock); 
	printf("Restocked value: %u, expected: 10\n", 
		(for_restock_list -> next -> next -> next -> next -> product) -> current_stock); 
}
