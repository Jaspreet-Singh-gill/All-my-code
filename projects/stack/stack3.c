#include <stdio.h>
#include<stdlib.h>

#include "stackADT2.h"
struct node{
	item content;
	struct node *next;

};
struct stack_type{
	struct node *top;
};



static terminate(){
	printf("Memory full\n");
	exit(0);
}
stack create(int size){
	stack s;
	s =  malloc(sizeof(struct stack_type));
	if(s == NULL)
		terminate();
	return s;
}
void destroy(stack s){
	make_empty(s);
	free(s);
	}


void push(stack s,item x)
{
	struct node *new = malloc(sizeof(struct node));
	if(new == NULL)
		terminate();
	new->content = x;
	new->next = s->top;
	s->top = new;


	
}

item pop(stack s )
{
    if (is_empty(s))
    {
	    terminate();
    }
    struct node *old;
    old = s->top;
    s->top = old->next;
    item i = old->content;
    free(old);
    return i;

   


}

bool is_empty(stack s)
{
    return s->top == NULL;
}

/*bool full(stack s)
{
    return s->top == s->size;
}*/

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
	while(!is_empty(s))
		pop(s);

}

int digit_to_int(char ch){
	return ch - '0';
}

