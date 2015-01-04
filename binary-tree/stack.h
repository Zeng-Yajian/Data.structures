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
