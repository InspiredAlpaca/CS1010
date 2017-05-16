/**
 * CS1010 AY2016/7 Semester 1 Lab4 Ex1
 * square.c
 * Author: Jin
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * <Wong kai Min Herman>
 * <T13>
 */

#include <stdio.h>
#define MAXSIZE 9
//Functions Prototype
int scanSquare(int [][MAXSIZE]); 
int isSemiMagic(int[][MAXSIZE], int);

int main(void) {
    int size, square[MAXSIZE][MAXSIZE]; 
    size = scanSquare(square);
    if(isSemiMagic(square,size))
	printf("It is a semi-magic square.\n");
    else
	printf("It is not a semi-magic square.\n");

	return 0;
}
/*This function checks if it is a semi-magic square by:
 * 1)all rows and column sum are the same
 * 2)All integers from 1 to size*size is included.
 * input:2D array of sqaure and size
 * output:1 for semi magic square and 0 for not semi magic square.
 */ 
int isSemiMagic(int arr[][MAXSIZE], int size){
    int i,j, firstSum = 0, rowSum,colSum, num[MAXSIZE*MAXSIZE] ={0};
    for(i = 0; i < size; i++){ //Compute the sum of a row for comparison
        firstSum += arr[0][i];
    }
    for(i = 0; i<size; i++){ //Loop through each row/column and compute sum
        rowSum = 0;
        colSum = 0;
        for(j = 0; j <size; j++){
            rowSum += arr[i][j]; //i and j are flipped for row and column respectively
            colSum += arr[j][i];
            num[arr[i][j]-1] = 1; //Assign 1 to array if integer is present, checking if 1 to n^2 integer are included
        }
        if(rowSum != firstSum || colSum != firstSum) //If any of the sum is not equals to first row return 0
            return 0;
    }
    for(i = 0; i < size*size; i++){ //Loop through stored array of included integer. If not present return 0.

        if(num[i] == 0)
            return 0;
    }
    return 1;
}

/*This function reads in the input for the magic square.
 * Precond: Positive integers
 * output: Returns size of square.
 */
int scanSquare(int arr[][MAXSIZE]) {
    int i,j,size;
	printf("Enter size of square: ");
    scanf("%d",&size);
	printf("Enter values in the square: \n");
    for(i = 0; i < size; i++){
        for(j = 0; j< size; j++){
           scanf("%d",&arr[i][j]); 
        }
    }
    return size;
}