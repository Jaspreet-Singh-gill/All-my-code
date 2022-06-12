#include<stdio.h>
#include "inventory.h"
#include "read_line.h"
#include "quicksort.h"
#define MAX_DATA 100
#define MAX_LEN 20
struct part inventory[MAX_DATA];
int num_pos = 0;
void search();
void print_all();
void insert();
void update();
int find_part(int part);
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
			default :
				printf("Enter a write command\n");
				break;

		}
	}
}

int find_part(int part){
	for(int i = 0 ; i <  num_pos+1 ;i++){
		if(inventory[i].number == part)
			return i;
	}
	return -1;
}

void insert(){
	int part;
	if(num_pos == MAX_DATA)
		printf("data base is full\n");

	printf("Enter the part number: ");
	scanf("%d",&part);
	if(find_part(part) >=  0){
		printf("Part exist already enter the new part name \n");
		return ;
	}
	inventory[num_pos].number = part;
	printf("Enter the name of part :");
	read_line(inventory[num_pos].name,MAX_LEN);
	printf("Enter the quantity of part :");
	scanf("%d",&inventory[num_pos].quantity);
	num_pos++;
}


void search(){
	int part;
	printf("Enter the part number :");
	scanf("%d",&part);
	int i = find_part(part);
	if(i >= 0){
		printf("The part number is %d\n",inventory[i].number);
		printf("The name of part is %s\n",inventory[i].name);
		printf("The quantity of part is %d\n",inventory[i].quantity);
	}
	else
		printf("The part number not found\n");
}


void update(){
	int part;
	printf("Enter the part number :");
	scanf("%d",&part);
	int i = find_part(part);
	if(i+1){
		printf("The name of part is %s\n",inventory[i].name);
		printf("Enter the number to update the quantity :");
		scanf("%d",&inventory[i].quantity);
	}
	else
		printf("The part number not found\n");
}

void print_all()
{
	quicksort(inventory,0,num_pos-1);

	printf("PART NUMBER  NAME     QUANTITY\n");
	for(int i = 0; i< num_pos;i++)
		printf("%7d     %-25s %-7d\n",inventory[i].number,inventory[i].name,inventory[i].quantity);
}

