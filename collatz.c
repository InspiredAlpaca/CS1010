// CS1010 AY2016/7 Semester 1
// PE1 Ex1: collatz.c
// Name:Wong Kai Min Herman 
// Matriculation number: A0139964M
// plab account-id: plab1029
// Discussion group: T13
// Description: This program prints out the value using the Collatz's sequence

#include <stdio.h>

//function prototype
void displayCollatzInternal(int,int);
int ifEven(int);
int ifOdd(int);

int main(void) {
	int num,iteration;
	// Get user input
	printf("Enter positive numbers for n and count: ");
	scanf("%d %d",&num, &iteration);
	printf("\n");
	// display the internal execution of Collatz's sequence
	displayCollatzInternal(num,iteration);

	return 0;
}
//This function prints out the collatz sequence of number and number of times it has been executed
//Input: number and number of iterations
//Output: print out the sequence
void displayCollatzInternal(int num, int iteration){
	int divisionCount =0,multiCount = 0, counter = 0;

	printf("The collatz sequence is: ");
	while(counter < iteration){ //Maximum number of count.
		if(num == 1) //condition: n cannot be equals to 1.
			break;
		if(num % 2 == 0){ //Check if it is even number.
			num = ifEven(num);
			divisionCount++; //Count how many division was done.
			printf("%d ",num);
		}
		
		else{
			num = ifOdd(num); //if odd number
			multiCount++; //Count how many multiplication was done
			printf("%d ",num);
		}
		counter++; 
	}
	printf("\nThe division statement has been executed %d times.\n",divisionCount);
	printf("The multiplication statement has been executed %d times.\n",multiCount);

}

//This function does the division if it is even
//input: num
//Output: number after division
int ifEven(int num){
	int n;
	n = num/2;
	return n;
}

//This function does the multiplication if number is odd
//Input:num
//Output: num after multiplication
int ifOdd(int num){
	int n;
	n = 3*num + 1;
	return n;
}
