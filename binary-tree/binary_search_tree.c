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

/**
* @file binary_search_tree.c
* @brief: simply implementation of binary search tree
* @author ZengYajian
* @version v0.1
* @date 2014-12-29
*/

#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include "binary_search_tree.h"
#include "stack.h"

/**
* @brief: initial a binary search tree
* @param: cmp - the user define cmp function
* @return: if success, pointer of the bst root,
*          if failed, return NULL
*/
struct bst_root *bst_init(int (*cmp)(void *, void *))
{
	struct bst_root *r;

	if (!cmp) return NULL;

	r = malloc(sizeof(*r));
	if (r) {
		r->root = NULL;
		r->cmp = cmp;
	}

	return r;
}

/**
* @brief: search the given data from bst
* @param: root - the root node to start with
* @param: data - the given data
* @param: node - resust
* @return: 0 -- can not find the given data
*          1 -- find the given data, param node is point to it
*/
static int __bst_search(struct bst_root *root, void *data,
	struct bst_node **node)
{
	int ret;
	struct bst_node *p = root->root;
	struct bst_node *parent = NULL;

_search:
	/* if can't find the data in bst, param node is
     * point to position it will insert to */
	if (!p) {
		*node = parent;
		return 0;
	}

	parent = p;
	ret = root->cmp(data, p->data);
	if (ret==0){
		*node = p;
		return 1;
	} else if (ret>0)
		p = p->rchild;
	else
		p = p->lchild;

	goto _search;
}

/**
* @brief: insert the data to the given binary search tree(root)
* @param: root - the given bst
* @param: data - the item will insert to
* @return: 0 - insert ok; -1, means the data is already in the bst
*/
int bst_insert(struct bst_root *root, void *data)
{
	struct bst_node *p;
	struct bst_node *new;

	if (!__bst_search(root, data, &p)) {
		new = malloc(sizeof(struct bst_node));
		new->data = data;
		new->lchild = new->rchild = NULL;

		if (!p)
			root->root = new;
		else if (root->cmp(data, p->data)>0)
			p->rchild = new;
		else
			p->lchild = new;

		return 0;
	}

	/* the data is already in the bst */
	return -1;
}

void __bst_delete_by_merging(struct bst_node **parent)
{
	struct bst_node *del = *parent;
	struct bst_node *tmp;

	if (!del) return;

	if (!del->rchild) {
		*parent = del->lchild;
	} else if (!del->lchild) {
		*parent = del->rchild;
	} else {
		tmp = del->lchild;
		while (tmp->rchild) tmp = tmp->rchild;

		tmp->rchild = del->rchild;
		*parent = del->lchild;
	}

	free(del);
}

int bst_delete(struct bst_root *root, void *data)
{
	struct bst_node **parent = &root->root;
	struct bst_node *p = root->root;
	int ret;

	/* find the node to be del */
	while (p) {
		ret = root->cmp(data, p->data);
		if (ret==0) {
			break; /* find the node */
		} else {
			parent = (ret>0) ? &(p->rchild) : &(p->lchild);
			p = (ret>0) ? p->rchild : p->lchild;
		}
	}

	if (*parent) {
		__bst_delete_by_merging(parent);
		return 0;
	}

	return -1;
}

/**
* @brief: traverse a binary search tree, callback func for every node
* @param: root - the given binary search tree
* @param: func - the callback function
*/

static void __inorder(struct bst_node *node, void (*func)(void *))
{
	if (node) {
		__inorder(node->lchild, func);
		func(node->data);
		__inorder(node->rchild, func);
	}
}

void bst_inorder_traverse(struct bst_root *root, void (*func)(void *))
{
	__inorder(root->root, func);
}

void bst_inorder_traverse_stack(struct bst_root *root, void (*func)(void *))
{
	struct stack_t *stack;
	struct bst_node *node = root->root;

	stack = stack_init();
	while(1) {

		while (node) {
			stack_push(stack, node);
			node = node->lchild;
		}

		node = stack_pop(stack);
		if (!node) break;
		func(node->data);
		node = node->rchild;
	}
}

/**
* @brief: traverse a binary search tree by post order,
*         callback func for every node
* @param: root - the given binary search tree
* @param: func - the callback function
*/
static void __postorder(struct bst_node *node, void (*func)(void *))
{
	if (node) {
		__postorder(node->lchild, func);
		__postorder(node->rchild, func);
		func(node->data);
	}
}

void bst_postorder_traverse(struct bst_root *root, void (*func)(void *))
{
	__postorder(root->root, func);
}
