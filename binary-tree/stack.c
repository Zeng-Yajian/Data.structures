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
