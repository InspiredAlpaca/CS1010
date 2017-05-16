/*CS1010 AY2016/7 Semester 1 Lab3 Ex1
* estimatePi.c
* This program reads in a list of n distinct integers and
* computes the estimate value for pi.
* This program uses an external GCD function (provided in gcd.o).
* <Wong Kai Min Herman>
* <T13>
*/

//Function prototype
double pi(int[],int);

#include <stdio.h>
#include <math.h>
#include "gcd.h"
#define MAX 50

int main(void) {
	int size,i,set[MAX];
	double piValue;
	scanf("%d", &size); //size of array
	for(i = 0; i < size; i++){ //Input of array
		scanf("%d",&set[i]);
	}
	piValue = pi(set,size);
	printf("Estimated pi = %.4lf\n",piValue);
	return 0;
}

/*
 * This function should finds the value of pi given a range of numbers. 
 * precond: input numbers must be positive integers, there must not be more than 50 numbers
 * Output: Pi.
 */

double pi(int arr[], int size) {
	int i,j,pairsWithoutGCD = 0,totalPairs = 0;
	double pi;
	for(i = 0; i < size; i++){
		for(j = i+1; j<size; j++){
			totalPairs++; //Count total pairs
			if(gcd(arr[i],arr[j]) == 1){ 
				pairsWithoutGCD++; //Count pairs with no common factor other than 1
			}
		}
	}
	pi = sqrt((totalPairs*6.0)/pairsWithoutGCD);
	return pi; 
}
