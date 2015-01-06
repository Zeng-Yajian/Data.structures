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

#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

struct bst_node {
	void *data;					/* point to the actual data */
	struct bst_node *lchild;
	struct bst_node *rchild;
};

struct bst_root {
	struct bst_node *root;		/* the root of binary search tree */
	int (*cmp)(void *, void *); /* the user define cmp function */
};

struct bst_root *bst_init(int (*cmp)(void *, void *));
int bst_insert(struct bst_root *root, void *data);
int bst_delete(struct bst_root *root, void *data);
void bst_inorder_traverse(struct bst_root *root, void (*func)(void *));
void bst_inorder_traverse_stack(struct bst_root *root, void (*func)(void *));
void bst_postorder_traverse(struct bst_root *root, void (*func)(void *));

#endif
