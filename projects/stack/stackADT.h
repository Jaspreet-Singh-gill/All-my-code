#ifndef STACK_ADT_H
#define STACK_ADT_H

#include <stdbool.h>
typedef struct stack_type *stack;
typedef int item;

stack create(void);
void destroy(stack s);

void push(stack s,item i);
item pop(stack s);
void stack_underflow(void);
void stack_overflow(void);
bool is_empty(stack s);
bool full(stack s);
void make_empty(stack s);


#endif
