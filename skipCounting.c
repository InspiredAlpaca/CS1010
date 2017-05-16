#include <stdio.h>

int skipCount(int, int, int);
int countOddDigits(int);

int main(void){
	int startPos, endPos, lower, upper;

	// Insert appropriate statements for reading the inputs.
	printf("Enter starting position: ");
	scanf("%d",&startPos);
	printf("Enter lower bound and upper bound: ");
	scanf("%d %d",&lower, &upper);

	endPos = skipCount(startPos, lower, upper);
	
	printf("The ending position is %d.\n", endPos);

	return 0;
}

int skipCount(int startPos, int lower, int upper){
	int currentPos,i, num;
	currentPos = startPos;
	for(i = lower; i <=upper; i++){
		num = countOddDigits(i);
		currentPos = currentPos + num;
		if(currentPos == 5){
			continue;
		}
		currentPos = currentPos % 5;	
	}
	return currentPos;
}


int countOddDigits(int num){
	int lastDigit, counter;
	counter = 1;
	while(num >0){
	lastDigit =	num % 10; //get last digit
	num = num/10;
	if(lastDigit == 0){
		continue;
	}
	if(lastDigit % 2 != 0){
		counter++;
	}
	


	}
return counter;
}

