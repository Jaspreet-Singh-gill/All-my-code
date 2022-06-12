#include<stdio.h>
struct fraction{
	int num;
	int dem;
};
int hcf(struct fraction f);
struct fraction add_frac(struct fraction f1,struct fraction f2);
struct fraction sub_frac(struct fraction f1,struct fraction f2);
struct fraction multi_frac(struct fraction f1,struct fraction f2);
struct fraction div_frac(struct fraction f1,struct fraction f2);

int main(){
	struct fraction f1,f2,result;
	char ch;
	printf("Enter the fraction :");
	scanf("%d/%d",&f1.num,&f1.dem);
	while(getchar() != '\n')
		;
	printf("Enter the operation :");
	scanf("%c",&ch);
	printf("Enter the fraction :");             scanf("%d/%d",&f2.num,&f2.dem);
	while(ch != 'Q'){
	switch(ch){
		case 'A':
			result = add_frac(f1,f2);
			break;
		case 'S':
			result = sub_frac(f1,f2);
			break;
		case 'M':
			result = multi_frac(f1,f2);
			break;
		case 'D':
			result = div_frac(f1,f2);
			break;
		default:
			printf("Enter a write operand\n");
			break;
	}
	printf("The answere is %d/%d\n",result.num,result.dem);

	printf("Enter the fraction :");
	scanf("%d/%d",&f1.num,&f1.dem);
	while(getchar() != '\n')
		;
        printf("Enter the operation :");            scanf("%c",&ch);
        printf("Enter the fraction :");             scanf("%d/%d",&f2.num,&f2.dem);	}
	return 0;
}

int hcf(struct fraction f){
	int m = f.num,n = f.dem,rem;
	//int temp;
	do{
		rem = m%n;
		if(rem ==0)
			return n;
		m = n;
		n = rem;
	}while(rem != 0);
	return n;
}

struct fraction add_frac(struct fraction f1,
struct fraction f2){
	struct fraction ans;
	f1.num *= f2.dem;
	f2.num *= f1.dem;
	int num = f1.num +f2.num;
	int dem = f1.dem*f2.dem;
	ans.num=num;
	ans.dem=dem;
	int HCF = hcf(ans);
	ans.num /= HCF;
	ans.dem /= HCF;
	return ans;
}


struct fraction sub_frac(struct fraction f1,struct fraction f2){
        struct fraction ans;
	f1.num *= f2.dem;                           f2.num *= f1.dem;
        int num = f1.num -f2.num;

	int dem = f1.dem*f2.dem;
	ans.num= num;
	ans.dem= dem;
	int HCF = hcf(ans);
	ans.num /= HCF;
	ans.dem /= HCF;
	return ans;
}
struct fraction multi_frac(struct fraction f1,struct fraction f2){
	struct fraction ans;
//	f1.num *= f2.dem;
//	f2.num *= f1.dem;

	int num = f1.num *f2.num;
                                                    int dem = f1.dem*f2.dem;
						    ans.num=num;                             ans.dem=dem;
						    int HCF = hcf(ans);                         ans.num /= HCF;                             ans.dem /= HCF;                             return ans;
}

struct fraction div_frac(struct fraction f1,struct fraction f2){
	struct fraction ans;
	int num = f1.num *f2.dem;
        int dem = f1.dem*f2.num;
        ans.num=num;                             ans.dem=dem;
        int HCF = hcf(ans);                         ans.num /= HCF;                             ans.dem /= HCF;                             return ans;
}

