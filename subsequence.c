Good attempt! You failed the test cases where the array contains negative values, initialize your sum with the 1-interval subsequence sum and initialize arr[1] and [2] accordingly. Then, you will pass two more test cases.

/*S1011 AY2016/7 Semester 1 Lab3 Ex2
*subsequence.c
* This program reads in a list of integers and find the
* k-interval subsequence with the largest sum.
* <Wong Kai Min Herman>
* <T13>
*/

#include <stdio.h>

int scan_list(int []);
void sum_subsequence(int [], int, int []);

int main(void) {
	int list[10]= {0}, size; // array and actual number of elements entered
	int answers[3] = {0};     // stores the required answers
	size = scan_list(list); 
	sum_subsequence(list, size, answers);
	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);
	return 0;
}

/*
 * Read in elements for the array arr and returns the 
 * number of elements read.
 * Postcond: i > 0 
 */
int scan_list(int arr[]) {
	int num, i;
	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	return num;
}

/* This function reads in the array elements and find the maximum k-interval subsequence. 
 * Output:
 * ans[0] = maximum sum of solution subsequence
 * ans[1] = interval k of the solution subsequence
 * ans[2] = start position of the solution subsequence
 */
void sum_subsequence(int arr[], int size, int ans[]) {
	int start,j,k,sum;
	for(k = 1; k <= size; k++){                 //go through the maximum k-interval subsequence based on size.
		for( start = 0; start < k; start++ ){   //Loop through every possible starting points based on k-interval
			sum = 0;                    
			for(j = start; j < size; j += k){   //Cycle through the array with k intervals
				sum = arr[j] + sum;
			}
			if(sum > ans[0]){                   //Update answer if it is greater
				ans[0] = sum;
				ans[1] = k;
				ans[2] = start;
			}
		}
	}

}

