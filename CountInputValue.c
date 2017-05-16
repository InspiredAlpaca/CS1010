/** S1010 AY2015/6 Semester 1 Lab2 Ex3
 * bisection.c
 * <Richard Goh>
 * <T31>
 * <This program finds the root of a function given 2 inputs by bisection>
 */

#include <stdio.h>


//Given function prototype must not be changed


int main(void) {
    int x ,i;
    
    printf("Enter integers, terminate with ctrl-d\n");
    while(scanf("%d",&i) == 1){
        x++;
    }
    printf("Number of values entered = %d\n", x);
	return 0;
}