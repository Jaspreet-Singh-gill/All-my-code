#include<stdio.h>
#include"database.h"
#include"inventory.h"
#include"word.h"
extern struct part inventory[] ;
int top = 0;
int find_num(int num){
	struct part *p;
	int i ;
	for( i = 0;i < top && inventory[i].number != num;i++ )
	       ;

       if(inventory[i].number == num){
          return i;
       }
	//else if(top == 0)
	//	return 1;
         else
	       return 0;


}
int find_num2(int num){
        //struct part *p;
        int i ;
        for( i = 0;i < top && inventory[i].number != num;i++ )                 ;

       if(inventory[i].number == num){
          return 1;
       }
       else
	       return 0;
}
void insert(void){
	//struct part node;
	int num;
	printf("ENTER THE PART NUMBER :");
	scanf("%d",&num);

	if(find_num2(num)){
		printf("The part already exists \n");
		return;
	}
	inventory[top].number = num;
	printf("ENTER THE NAME:");
	read_word(inventory[top].name,25);  
	printf("ENTER THE QUANTITY :");
	scanf("%d",&inventory[top].on_hand);

	top++;
}

void delete(void){
	struct part cur ,pre ;
	int num,p;
	printf("ENTER THE NUMBER :");
	scanf("%d",&num);
	if(!find_num2(num)){                                                       printf("The part not exists \n");                                             return;                          }
	p = find_num(num);
	cur = inventory[top-1];
	inventory[top-1] = inventory[p];
	inventory[p] = cur;
	top--;
}

void search(void){
	//struct part *p;
	int num,p;
	printf("ENTER THE NUMBER :");
	scanf("%d",&num);
	if((find_num(num))){
		printf("The part not exists \n");
		return ;
	}
	p =find_num2(num);

	printf("THE NUMBER : %d\n",inventory[p].number);
	printf("THE NAME : %s\n",inventory[p].name);
	printf("THE QUANTITY : %d \n",inventory[p].on_hand);
}

void update(void){                                   
	int num,p;
        printf("ENTER THE NUMBER :");                     scanf("%d",&num);                                 if((find_num2(num)) == NULL){                          printf("The part not exists \n");                 return ;                                  }
	p = find_num(num);

	printf("ENTER THE NEW QUANTITY :");
	scanf("%d",&inventory[p].on_hand);
}


void print_all(void){
	printf("|  NO.|                    NAME |  QUANTITY|  \n");
       for(int i = 0; i < top; i++){
	       printf("|%4d |%24s |%10d| \n",inventory[i].number,inventory[i].name,inventory[i].on_hand);
       }
      printf("\n");

}

void write_database(void){
	FILE *ptr;
	char ch[60];
	printf("ENTER THE FILE NAME TO SAVE : ");
	read_word(ch,59);
	ptr = fopen(ch,"wb");
	if(ptr == NULL){
		fprintf(stderr,"The file %s cann't be writeen\n",ch);
		return;
	}
	fwrite(inventory,sizeof(inventory[0]),top,ptr);
}

void read_database(void){
	FILE *ptr;
	printf("ENTER THE FILE NAME TO READ : ");
	char ch[60];
	read_word(ch,59);
	ptr = fopen(ch,"rb");
	if(ptr == NULL){
		fprintf(stderr,"The file %s cann't be open\n",ch);
		return ;
	}
	/* fseek(ptr,0,SEEK_END);
	int pos = ftell(ptr);
	rewind(ptr);
*/
	int i = fread(inventory,sizeof(inventory[0]),50,ptr);
	top = top + i;

	if(ferror(ptr)){
		fprintf(stderr,"error has occur\n");
	}
	return ;
}

