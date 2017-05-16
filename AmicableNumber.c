// CS1010 AY2015/6 Semester 1
// PE1 Ex2: amicable.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>

void countPairs(int lower, int upper, int results[]);
int sumFactors(int number);

// Do NOT change the main function at all!
int main(void){
	int lower, upper, results[2] = {0};
	
	printf("Enter range: ");
	scanf("%d %d", &lower, &upper);

	countPairs(lower, upper, results);
	
	printf("Number of full pairs: %d\n", results[0]);
	printf("Number of half pairs: %d\n", results[1]);

	return 0;
}

void countPairs(int lower, int upper, int results[]){
    int i, sumNum,sumNum2, fullcounter = 0,halfcounter = 0;
    for(i = lower; i <=upper; i++){
        sumNum = sumFactors(i);
        sumNum2 = sumFactors(sumNum);
        if(sumNum2 == i && sumNum != i){
            if(sumNum>= lower && sumNum <= upper){
                fullcounter ++;
            }
            else
                halfcounter++;
        }
    }
    results[0] = fullcounter/2;
    results [1] = halfcounter;
}
	// Remember to assign the calculated number of full pairs to results[0],
	// and the calculated number of half pairs to results[1]


int sumFactors(int number){
    int i, sum = 0;
    for(i = 1; i < number; i++){
        if(number % i == 0){ //dont divide by 2 cause you did not repeat. is go through entire thing. %2 does not give u the division of it,
            sum = sum + i;
        }
	}
            return sum; // stub
}
