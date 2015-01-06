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

#ifndef __STACK_H__
#define __STACK_H__

struct item;

struct stack_t {
	unsigned int size;
	struct item *head;
};

struct item {
	struct item *next;
	void *data;
};

struct stack_t *stack_init();
void stack_destory(struct stack_t *stack, void (*func)(void *));
int stack_is_empty(struct stack_t *stack);
int stack_get_size(struct stack_t *stack);
void *stack_pop(struct stack_t *stack);
void stack_push(struct stack_t *stack, void *data);
void stack_traverse(struct stack_t *stack, void (*func)(void *));
#endif
