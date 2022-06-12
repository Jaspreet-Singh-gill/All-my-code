#include<stdio.h>
#include<stdlib.h>
#include"queque.h"
#define MAX_LEN 20
struct node{
	item content;
	struct node *next;
};

struct quque_type{
	struct node *tail,*head;

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
	ptr->tail = NULL;
	ptr->head = NULL;

	return ptr;
}
void edquque(quque q,item i){
	struct node *ptr;
	ptr = malloc(sizeof(struct node));
	if(ptr == NULL)
		terminate();
	ptr->content = i;

	if(q->head == NULL){
                q->head = ptr;
		q->tail = ptr;

                return;                          }
	q->tail->next = ptr;
	q->tail = ptr;
	


}
item dlquque(quque q){
        if(is_empty(q)){
	terminate();
	}
	item i;

	struct node *ptr;
	ptr = q->head;
	if(q->head == q->tail){
		q->head = q->tail = NULL;
	}
       else{
	q->head = ptr->next;
       }
       i = ptr->content;

	free(ptr);
	return i;


}
item get_first(quque q){

	return q->head->content;
}

item get_last(quque q){
        return q->tail->content;
}
bool is_empty(quque q){
	return q->head == NULL;

}
/*bool is_full(quque q){
	return q->num == MAX_LEN;
}*/
void make_empty(quque q){
	while(!is_empty(q))
		dlquque(q);
}
void destroy(quque q){
	make_empty(q);

		
	free(q);

}




