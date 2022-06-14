#include<stdio.h>
#include"inventory.h"

struct part inventory[100];
int main(){
	int ch;
	printf("Enter 0 = quit,\
			1 = insert,\
			2 = update,\
			3 = delete,\
			4 = serach,\
			5 = print_all,\
			6 = read_file,\
			7 = write_file \n");
	void (*fun_name[])(void) = {
                    insert,
                    update,
                    delete,
                    search,
                    print_all,
		    read_database,
		    write_database
	};		    
	for(;;){
		printf("Enter the command :");
		scanf("%d",&ch);

		if(ch ==0)
			exit(0);
		if(ch >=0 && ch <=7)
			fun_name[ch-1]();
		else
			printf("Enter right commmand\n ");
	}

	return 0;
}



