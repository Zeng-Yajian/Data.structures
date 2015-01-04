
#include <stdio.h>
#include "binary_search_tree.h"
#include "stack.h"

void item_dump(void *data)
{
	printf("  -- %d\n", *(int *)data);
}

int cmp(void *data1, void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

int main(int argc, char **argv)
{
	struct bst_root *tree;
	int i;
	int array[12] = {15,6,18,3,7,17,1,20,2,4,13,9};

	tree = bst_init(cmp);

	for (i=0; i<12; i++) {
		bst_insert(tree, (void *)&array[i]);
	}

	printf("inorder traverse:\n");
	bst_inorder_traverse(tree, item_dump);

	printf("inorder traverse (use stack):\n");
	bst_inorder_traverse_stack(tree, item_dump);

	printf("postorder traverse:\n");
	bst_postorder_traverse(tree, item_dump);

	return 0;
}
