/* Copyright (C) 
* 2014 - ZengYajian
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
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
