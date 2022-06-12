#include<stdio.h>
#include<stdlib.h>
#include "inventory.h"
#include "read_line.h"
#define MAX_LEN 30
struct part *inventory = NULL;
void search();
void print_all();
void insert();
void update();
void erase();
struct part *find_part(int num);
int main(){
	char ch;
	printf("Enter I (TO INSER) U(UPADE) S(SERCH),P(PRINT),Q(QUIT)\n");
	for(;;){
		printf("Enter the operation: ");
		scanf(" %c",&ch);
		while(getchar() != '\n')
			;
		switch(ch){
			case 'P':
				print_all();
				break;
			case 'Q':
				return 0;
			case 'I':
				insert();
				break;
			case 'U':
				update();
				break;
			case 'S':
				search();
				break;
			case 'E':
				erase();
				break;

			default :
				printf("Enter a write command\n");
				break;

		}
	}
}

struct part *find_part(int num){
	struct part *ptr,*cur;
	for(ptr = inventory ; ptr != NULL && num > ptr->number;cur = ptr,ptr = ptr->next)
		;

	if(ptr->number == num)
		return ptr;
	else
		return NULL;
}

void insert(){
	struct part *new_node,*pre,*cur;
	new_node = malloc(sizeof(struct part));
	if(new_node ==NULL){
		printf("Data base is full\n");
		return;
	}

	printf("Enter the part number: ");
	scanf("%d",&new_node->number);
	for(cur = inventory,pre = NULL;cur != NULL && new_node->number > cur->number; pre = cur,cur = cur->next)
		;

	if(cur != NULL && new_node->number == cur->number ){
		printf("Part exist already enter the new part name \n");
		free(new_node);

		return ;
	}
	printf("Enter the name of part :");
	read_line(new_node->name,MAX_LEN);
	printf("Enter the quantity of part :");
	scanf("%d",&new_node->quantity);
	if(pre ==NULL)
		inventory = new_node;
	else{
		pre->next = new_node;
	}
	new_node->next = cur;

}



void search(){
	struct part *ptr;
	int num;

	printf("Enter the part number :");
	scanf("%d",&num);
	ptr = find_part(num);
	if(ptr != NULL){
		printf("The part number is %d\n",ptr->number);
		printf("The name of part is %s\n",ptr->name);
		printf("The quantity of part is %d\n",ptr->quantity);
	}
	else
		printf("The part number not found\n");
}


void update(){
	struct part *ptr;
	int num;
	printf("Enter the part number :");
	scanf("%d",&num);
	ptr = find_part(num);
	if(ptr != NULL){
		printf("The name of part is %s\n",ptr->name);
		printf("Enter the number to update the quantity :");
		scanf("%d",&ptr->quantity);
	}
	else
		printf("The part number not found\n");
}

void print_all()
{
	struct part *ptr;

	printf("PART NUMBER  NAME     QUANTITY\n");
	for(ptr = inventory; ptr != NULL; ptr = ptr->next)
		printf("%7d     %-25s %-7d\n",ptr->number,ptr->name,ptr->quantity);

}

void erase(){
	struct part *ptr,*cur,*pre;
	int numb;
	printf("ENTER THE PART NUMBER :");
	scanf("%d",&numb);
	for(cur = inventory,pre = NULL;cur != NULL && numb > cur->number; pre = cur,cur = cur->next)
                ;
        if(cur != NULL && numb == cur->number ){
		if(pre == NULL){
			free(cur);
			inventory = NULL;
		}
		else{
		pre->next = cur->next;
		free(cur);
		}
	}


	}
