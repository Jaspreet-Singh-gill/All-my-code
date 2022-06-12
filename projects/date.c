#include <stdio.h>

struct date{
	int day;
	int month;
	int year;
};
int count_days(struct date d1);
int compare_date(struct date d1,struct date d2);

int main(){
	struct date d1,d2;
	printf("Enter the date in dd/mm/yy:");
	scanf("%d/%d/%d",&d1.day,&d1.month,&d1.year);
	printf("Enter the date in dd/mm/yy:");
        scanf("%d/%d/%d",&d2.day,&d2.month,&d2.year);
	if(compare_date(d1,d2) < 0){
		printf("%d/%d/%d is earlier than %d/%d/%d\n",d1.day,d1.month,d1.year,d2.day,d2.month,d2.year);
	}
	else if(compare_date(d1,d2) >0){
		printf("%d/%d/%d is earlier than %d/%d/%d\n",d2.day,d2.month,d2.year,d1.day,d1.month,d1.year);}
	else{
		printf("%d/%d/%d is similar to  %d/%d/%d\n",d1.day,d1.month,d1.year,d2.day,d2.month,d2.year);
	}
	return 0;
}

int count_days(struct date d1){
	int num_days[] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	int DAYS = 0;
	if(d1.year %4 == 0)
		DAYS++;
	for(int i = 0; i < d1.month-1;i++){
		DAYS += num_days[i];
	}
	DAYS += d1.day;
	return DAYS;
}

int compare_date(struct date d1,struct date d2){
	if(d1.year < d2.year)
		return -1;
	else if(d1.year > d2.year)
		return 1;
	else{
		int days1,days2;
		days1 = count_days(d1);
		days2 = count_days(d2);
		if(days1 < days2)
			return -1;
		else if(days1 > days2)
			return 1;
		else
			return 0;
	}
}
