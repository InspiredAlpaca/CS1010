// CS1010 AY2016/7 Semester 1
// PE1 Ex2: numerology.c
// Name: Wong Kai Min Herman
// Matriculation number: A0139964M
// plab account-id: plab1029
// Discussion group: T13
// Description: This program  provides "advice" based on an input number.

#include <stdio.h>
#include <math.h>

//function prototype
int multiply2Digit(int);
int returnDGT(int);
int checkSign(int);
void giveAdvice(int,int);

//precondition: number must be non-zero integer.

int main(void) {
	int num, sign;
	printf("Enter a non-zero integer: "); 
	scanf("%d", &num);
	sign = checkSign(num);
	num = fabs(num); //Get the absolute number for input
	num = returnDGT(num); //return dgt number
	giveAdvice(num,sign);
	return 0;
}

//This function checks if the number is positive or negative
//input: number
//output: 1 for positive, 0 for negative.
	int checkSign(int num){
		if(num > 0) //If postive
			return 1;
		else		//if negative
			return 0;
	}


//This function calculates numPrime
//input: number 
//output:Each digit in the number is multiplied
int multiply2Digit(int num){
	int lastDigit,numPrime = 1;
	while(num > 0){
		lastDigit = num%10; //get the last digit
		num = num/10;
		numPrime = lastDigit * numPrime;
	}
	return numPrime;
}

//This function calculates the dgt number.
//input num
//output: dgt number
int returnDGT(int num){
	while(num >= 10){ //while number is not a single digit, do multiply2digit again.
		num = multiply2Digit(num);
	}
	return num;
}

//This function prints the given advice based on the number.
//input: number
//ouput: The advice
void giveAdvice(int num,int sign){
	printf("Advice for you: ");
	if(sign == 1){ //If the number given is positive. 
		switch(num){
			case 0: //if dgt is 0,3,7,9
			case 3:
			case 7:
			case 9:
				printf("You should protect life.\n"); 
				break;
			case 2: //if dgt is 2,5,8
			case 5:
			case 8:
				printf("Share your wealth, donate generously.\n"); 
				break;
			case 1: //if dgt is 1,4,6
			case 4:
			case 6:
				printf("Build harmony, bring people together.\n"); 
				break;
		}	
	}
	else if(sign == 0){ //If the number given is negative.
		switch(num){
			case 0:  //if dgt is 0,3,7,9      
			case 3:
			case 7:
			case 9:
				printf("Speak honestly.\n"); 
				break;
			case 2:
			case 5:
			case 8:
				printf("Praise others' successes.\n"); 
				break;
			case 1:
			case 4:
			case 6:
				printf("Lend your hand to those who are in need.\n"); 
				break;

		}
	}
}
