#include <stdio.h>

int countWinners(int,int,int);
int mustHavefunc(int,int);

int main(void){
	int factor,mustHave,participants,number;       

	printf ("Enter factor-digit: ");
	scanf("%d",&factor);
	printf("Enter must-have-digit: ");
	scanf("%d",&mustHave);
	printf("Enter number of participants: ");
	scanf("%d",&participants);
	number = countWinners(factor,mustHave,participants);
	printf("Number of winners: %d\n",number);

	return 0;

}
int countWinners(int factor, int mustHave, int participants){
	int i,counter = 0;
	for(i = 1; i<= participants; i++){
		if(i%factor == 0){
			counter = counter + mustHavefunc(i,mustHave);
		}
	}
return counter;
}

int mustHavefunc(int num, int mustHave){
	while(num > 0){
		if(num%10 == mustHave)
			return 1;
		num = num / 10;
	}
	return 0;
}

