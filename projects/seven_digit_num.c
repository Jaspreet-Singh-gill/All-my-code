#include<stdio.h>
#include<ctype.h>
#define MAX_digits 10
#define MAX_SEGMENTS 7
void clear_digit_array(void);
void process_digit_array(int digit,int position);
void print_digit_array(void);
char digits[3][40];
const int segments[MAX_digits][MAX_SEGMENTS] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1}};
const int segment_grid[7][2] = {{0, 1},{1, 2},
{2, 2}, 
{2, 1}, 
{2, 0},
 {1, 0}, 
{1, 1}};

int main(){
	char ch;
	int position = 0;
	printf("ENTER THE NUMBER :");
	clear_digit_array();
	while((ch =getchar()) != '\n'){
		if(isdigit(ch)){
			process_digit_array(ch -'0',position);
			position += 4;
		}
	}
	print_digit_array();
	return 0;
}

void clear_digit_array(void){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 40; j++){
			digits[i][j] = ' ';
		}
	}
}

void process_digit_array(int digit,int position){
	int row,col;
		for(int j = 0; j<7;j++){
			if(segments[digit][j]){
				row = segment_grid[j][0];
				col = segment_grid[j][1]+position;
				digits[row][col] = j %3 == 0 ? '_':'|';

			}
		}
	
}

void print_digit_array(void){
		for(int i = 0; i< 3;i++){
			for(int j = 0; j < 40; j++){
				putchar(digits[i][j]);
			}
			printf("\n");
		}
}

