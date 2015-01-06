/* 
* The MIT License (MIT)
* 
* Copyright (c) 2015 Zeng.Yajian
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* 
*/

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

	printf("del %d\n", array[1]);
	bst_delete(tree, &array[1]);
	printf("inorder traverse (use stack):\n");
	bst_inorder_traverse_stack(tree, item_dump);

	printf("del %d\n", array[5]);
	bst_delete(tree, &array[5]);
	printf("inorder traverse (use stack):\n");
	bst_inorder_traverse_stack(tree, item_dump);

	printf("del %d\n", array[0]);
	bst_delete(tree, &array[0]);
	printf("inorder traverse (use stack):\n");
	bst_inorder_traverse_stack(tree, item_dump);

	return 0;
}
