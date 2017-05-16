// countNumbers.c
// To count the number of integers in the range [limit1, limit2]
// which are not divisible by divisor1 and divisor2
#include <stdio.h>

int count_numbers(int, int, int, int);
int division(int,int);
int division2(int,int);

int main(void) {    
	int divisor1, divisor2, limit1, limit2;
    
    do{
	printf("Enter 2 divisors: ");
    scanf("%d %d", &divisor1,&divisor2);
    
    } while(division(divisor1, divisor2) == 0);

    do{
	printf("Enter lower and upper limits: ");
    scanf("%d %d",&limit1, &limit2);
    } while (division2(limit1,limit2) == 0);
    
    printf("Answer = %d\n",count_numbers(divisor1,divisor2,limit1,limit2));

	return 0;
}

int division(int a,int b){
    if(a < 0 || b < 0 || a ==b || a == 0 || b == 0)
        return 0;
    else 
        return 1;
}

int division2(a,b){
        if(a < 0 || b < 0 || a >= b || a == 0 || b == 0)
        return 0;
    else 
        return 1;
}

int count_numbers(int divisor1, int divisor2, int limit1, int limit2){
    int i,counter = 0;
    for(i = limit1; i <= limit2; i++){
        if(i % divisor1 != 0 && i % divisor2 != 0){
            counter++;
            
        }
    }
    return counter;
}