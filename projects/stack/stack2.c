#include <stdio.h>
#include<stdlib.h>

#include "stackADT2.h"
#define PUBLIC
#define PRIVATE
struct stack_type{
	item *content;
	item top;
	int size;
}

PRIVATE static terminate(){
	printf("Memory full\n");
	exit(0);
}
PUBLIC stack create(int size){
	struct stack_type *s;
	s = (struct stack_type *) malloc(sizeof(struct stack_type));
	if(s == NULL)
		terminate();
	s->content = malloc(sizeof(item)*size);
	if(s->content == NULL)
		terminate();
	s->size = size;

	s->top = 0;

	return s;
}
PUBLIC void destroy(stack s){
	free(s->content);
	free(s);
	}


PUBLIC void push(stack s,item x)
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

PUBLIC item pop(stack s )
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

PUBLIC bool is_empty(stack s)
{
    return s->top == 0;
}

PUBLIC bool full(stack s)
{
    return s->top == s->size;
}

PUBLIC void stack_underflow()
{
    printf("The experation has no operand \n");
}

PUBLIC void stack_overflow()
{
    printf("The experation ia full \n");
    terminate();
}

PUBLIC void make_empty(stack s)
{
    s->top = 0;
}

PUBLIC int digit_to_int(char ch){
	return ch - '0';
}

