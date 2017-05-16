#include <stdio.h>

int sumDigits(int);

int main(void) {
	int num;

	printf("Enter a non-negative integer: ");
	scanf("%d", &num);
	//sumDigits(num);
	printf("Sum of its digits = %d\n", sumDigits(num));

	return 0;
}

// Return sum of digits in n
// Precond: n >= 0
int sumDigits(int n) {
	if(n < 10)
		return n;
	else{
		return sumDigits(n/10)+(n%10);
	}

	
}

