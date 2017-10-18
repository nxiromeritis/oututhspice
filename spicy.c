#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "spicy.h"
#include "lists.h"
#include "hashtable.h"
#include "cir_parser.h"

int main(int argc, char *argv[]) {

	char filename[LINE_MAX];
	unsigned long components_num;
	int ht_put_ret;

	if (argc != 2) {
		printf("Error. Invalid number of arguments..\n");
		printf("Use: %s <filename>\n", argv[0]);
		return 1;
	}

	if (strlen(argv[1]) > LINE_MAX-1) {
		printf("Error. Filename too long. Exiting..\n");
		return 1;
	}


	strcpy(filename, argv[1]);

	components_num = get_components_num(filename);
	ht_init(components_num >> 1);

	// add grounding into the hash table (we want it to be reserved)
	ht_put("0", 0);

	init_lists();

	printf("Total number of components: %lu\n\n", components_num);
	parse_cir(filename);

	printHastable();
	print_id_list();
	print_list1();
	print_list2();
	print_sec_list();

	freeHashTable();
	free_lists();

	return 0;
}