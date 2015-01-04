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

#include <memory.h>
#include <malloc.h>
#include "stack.h"

#define null NULL

/**
* @brief: init a stack struct
* @return: pointer to stack
*/
struct stack_t *stack_init()
{
	struct stack_t *s;

	s = malloc(sizeof(struct stack_t));
	if (s) {
		s->size = 0;
		s->head = null;
	}

	return s;
}

/**
* @brief: nothing
* @param: data
*/
static void noop(void *data)
{
	return;
}

/**
* @brief: destory a stack
* @param: stack - pointer to the stack to be destory
* @param: func  - function callback for every item
*/
void stack_destory(struct stack_t *stack, void (*func)(void *))
{
	struct item *p;

	if (!func) func = noop;

	while (1) {
		p = stack->head;
		if (!p) break;

		stack->head = p->next;
		func(p->data);
		free(p);
	}
}

/**
* @brief: is a stack empty
* @param: stack
* @return: 0 - the stack is not empty
*          1 - the stack is empty
*/
int stack_is_empty(struct stack_t *stack)
{
	return (stack->size == 0);
}

/**
* @brief: get the stack's size
* @param: stack
* @return: the size
*/
int stack_get_size(struct stack_t *stack)
{
	return stack->size;
}

/**
* @brief: pop a item from stack
* @param: stack
* @return: the item
*/
void *stack_pop(struct stack_t *stack)
{
	struct item *del;
	void *ret = null;

	if (stack->head!=null) {
		del = stack->head;
		stack->head = del->next;
		stack->size--;

		ret = del->data;
		free(del);
	}
	return ret;
}

/**
* @brief: push a item into stack
* @param: stack -
* @param: data  - the data to be add
*/
void stack_push(struct stack_t *stack, void *data)
{
	struct item *new_item;

	new_item = malloc(sizeof(*new_item));
	if (new_item) {
		new_item->data = data;
		new_item->next = stack->head;
		stack->head = new_item;
		stack->size++;
	}
}

/**
* @brief: traverse the stack
* @param: stack
* @param: func - callback founction for every item
*/
void stack_traverse(struct stack_t *stack, void (*func)(void *))
{
	struct item *p;

	if (!func) return;

	p = stack->head;
	while(p) {
		func(p->data);
		p = p->next;
	}
}
