/**
 * CS1010 AY2016/7 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * <Wong Kai Min Herman>
 * <discussion group 13>
 */
#include <stdio.h>
#include <math.h>

int main(void) {
	int principal, rate, numYears;
	float amount;

	printf("Enter principal amount: ");
	scanf("%d",&principal);

	printf("Enter interest rate   : ");
	scanf("%d",&rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);
	
//formula to calculate final investment amount

	amount = principal * (1 - pow((rate/100.00),(numYears + 1)))/(1 -(rate/100.00));

	printf("Amount = $%.2f\n",amount);

	return 0;
}

