// perfectNumber.c 
// Repeatedly reads a non-negative value, and stops when zero is read.
// For each positive value read, it checks if the value is a perfect number.

#include <stdio.h>

int is_perfect(int);

int main(void) {
	int num,perfect;
	do{
		printf("Enter number: ");
		scanf("%d", &num);
		if(num == 0)
			break;
		perfect = is_perfect(num);
		if(perfect == 1)
			printf("%d is a perfect number.\n",num);
		else
			printf("%d is not a perfect number.\n",num);
		
	} while(num != 0);
	return 0;
}

int is_perfect(int num){
	int i,sum = 0;
	for(i = 1; i <= num/2; i++){
		if(num%i == 0)
			sum = sum + i;
	}
	if(sum == num)
		return 1;
	else
		return 0;
}
