#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAS_LEN 60
#define MAX_LEN 50
struct vstring{
	int day;
	char rem[];
};

int readline(char a[],int n);
int main(){
	int i,day,remind = 0;
	struct vstring *remender[MAX_LEN], day_str[3],message[MAS_LEN];
	for(;;){
		if(remind == MAX_LEN)
			break;

		printf("Enter the reminder : ");
		scanf("%2d",&day);
		readline(message,MAS_LEN);
		sprintf(day_str,"%2d",day);
		if(day== 0)
			break;
		for(i = 0; i <remind;i++){
			if(strcmp(day_str,(remender[i])->rem) < 0)
				break;
		}

		for(int j = remind; j > i;j--)
			remender[j] = remender[j-1];
		remender[i] = malloc(sizeof(struct vstring)+strlen(message));
		if(remender[i] ==  NULL)
			printf("No allocated storage\n");

		strcpy((remender[i])->rem,day_str);
		strcat((remender[i])->rem,message);
		remind++;
	}



	for(i = 0; i < remind; i++)
		printf("%s \n",(remender[i])->rem);
	return 0;
}
int readline(char a[],int n){
	char *p,ch;
	int i = 0; 
	for(p= a;p < a+n;p++)
	{ 
		ch = getchar();
		if(ch == '\n')
			break;
		else{
			*p = ch;
			i++;
		}
	
	
	}
	*p = '\0';
	return i;
}



