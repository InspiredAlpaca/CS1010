#include <stdio.h>

int isAscending(int,int,int);

int main(void){
int num1,num2,num3, result;

	printf("Enter 3 positive integers: ");
	scanf("%d %d %d",&num1, &num2, &num3);
	result = isAscending(num1,num2,num3);
	printf("The integers are %d, %d and %d\n",num1,num2,num3);
	if (result == 0){
		printf("No\n");
	}	
	else if(result == 1){
		printf("Yes\n");
	}


	return 0;
}

int isAscending(int num1, int num2, int num3){
	int n1,n2,n3;
	if(num1 <  100 || num2 < 100 || num3 < 100){
		return 0;
	}
		n1 = (num1/100) % 10;
		n2 = (num2/100) % 10;
		n3 = (num3/100) % 10;
	if(n3 >  n2 &&  n2 >  n1){
		return 1;
	}
	else
		return 0;
	}
