#include <stdio.h>
#include<stdlib.h>

#include "stackADT.h"
#define stack_size 20
struct stack_type{
	item content[stack_size];
	item top;
}

static terminate(){
	printf("Memory full\n");
	exit(0);
}
stack create(){
	struct stack_type *s;
	s = (struct stack_type *) malloc(sizeof(struct stack_type));
	if(s == NULL)
		terminate();
	s->top = 0;

	return s;
}
void destroy(stack s){
	free(s);
	}


void push(stack s,item x)
{
    if (full(s))
    {
        stack_overflow();
    }
    else
    {
        s->content[s->top++] = x;
  
    }
}

item pop(stack s )
{
    if (is_empty(s))
    {
        stack_underflow();
    }
    else
    {
        return s->content[--s->top];
    }
}

bool is_empty(stack s)
{
    return s->top == stack_size;
}

bool full(stack s)
{
    return s->top == stack_size;
}

void stack_underflow()
{
    printf("The experation has no operand \n");
}

void stack_overflow()
{
    printf("The experation ia full \n");
    terminate();
}

void make_empty(stack s)
{
    s->top = 0;
}

int digit_to_int(char ch){
	return ch - '0';
}

