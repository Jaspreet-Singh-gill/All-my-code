#include<stdio.h>
#include<stdlib.h>
#include"queque.h"
#define MAX_LEN 20
struct quque_type{
	item content[MAX_LEN];
	int first;
	int last;
	int num ;
};
bool is_full(quque q);

static void terminate(){
	printf("Memory full\n");
	exit(0);
}

quque create(void){
	quque ptr;
	ptr = malloc(sizeof(struct quque_type));
	if(ptr == NULL)
		terminate();
	ptr->first = ptr->last = ptr->num = 0;

	return ptr;
}
void edquque(quque q,item i){
	if(q->num < MAX_LEN){
		q-> last = (q->num+1 == MAX_LEN ? 0 :q->last) ;

		q->content[q->last++] = i;
		q->num++;

	}
}
item dlquque(quque q){
	if(q->first == MAX_LEN)
		q->first =0;

	item i = q->content[q->first++];
	q->num--;
	return i;
}
item get_first(quque q){
	if(!is_empty(q)){
		if(q->last == 0)
			return q->content[MAX_LEN-1];
		else
			return q->content[q->first];
	}
	else{
		terminate();
	}
}

item get_last(quque q){
        if(!is_empty(q)){
               return q->content[q->last-1];
        }
        else{
                terminate();
        }
}
bool is_empty(quque q){
	return q->num == 0;
}
bool is_full(quque q){
	return q->num == MAX_LEN;
}
void destroy(quque q){
	//while(q->head != NULL)
	//	edquque(q);

	free(q);
}




