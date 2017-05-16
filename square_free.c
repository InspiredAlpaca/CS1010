/**
 * CS1010 AY2016/7 Semester 1 Lab2 Ex2
 * square_free.c
 * <Wong Kai Min Herman>
 * <T13>
 * <Calculate pair that has the most square free number.>
 */
 int count_square_free(int,int);

#include <stdio.h>
#include <math.h> 

count_square_free(int, int);

int main(void) {
	int lower1, upper1, //first pair
        lower2, upper2, //second pair
        num_square_free1,num_square_free2; //variable to hold number of square free num.

	printf("Enter four positive integers: ");
    scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);
    num_square_free1 = count_square_free(lower1,upper1);
    num_square_free2 = count_square_free(lower2,upper2);

     
    if(num_square_free1 > num_square_free2){
        printf("Range [%d, %d] has more square-free numbers: %d\n", lower1,upper1,num_square_free1);
    }
    else if(num_square_free2 > num_square_free1){
        printf("Range [%d, %d] has more square-free numbers: %d\n", lower2,upper2,num_square_free2);
    }
    else{
	printf("Both ranges have the same number of square-free numbers: %d\n",num_square_free1);
    }
	return 0;
}
//This functions counts the number of square free number are there in the range.
int count_square_free(int l, int u){
    int x, flag, counter = 0;
    for(l = l; l <= u; l++){
        flag = 1; //flag to determine if a square num is found
        for( x = 2; x <= sqrt(u); x++){ 
            if(l % (x*x) == 0){
                flag = 0;
            }       
        }
        if(flag == 0)
            continue;
        else
        counter ++; //flag is equals 1 indicating a square free number is found
    }
    return counter;
}