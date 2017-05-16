/*S1010 AY2016/7 Semester 1 Lab4 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * <Wong Kai Min Herman>
 * <T13>
 */

#include <stdio.h>
#define DIM 12

//Function Prototypes
void scanBoard(int [][DIM]);
int checkDiagonal(int [][DIM],int,int,int);
int checkHorizontal(int [][DIM],int,int,int);
int checkVertical(int [][DIM],int,int,int);
int search(int[][DIM],int*,int*,int);

int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length = 0;           // length of the longest sequence of search digit
	int bestRow, bestCol;     // where the longest sequence of search digit starts in the board
	scanBoard(board); 
	scanf("%d",&search_digit);
    length = search(board,&bestRow,&bestCol,search_digit);
	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", bestRow, bestCol);      
	}
	else
		printf("No such sequence.\n");

	return 0;
}

/*This function reads in the input for the board.
 * Precond: Positive integers in the range of [1-9].
 */
void scanBoard(int arr[][DIM]) {
	int row, col;
	for (row=0; row<DIM; row++){
		for (col=0; col<DIM; col++) {
			scanf("%d", &arr[row][col]);
		}
	}
}

/*This function searches the board for the longest sequence of the search digit.
 * Input: Board's array and search digit.
 * Output: Starting postion of longest sequence and length.
 */ 
int search(int arr[][DIM],int *bestRow, int *bestCol,int search_digit) {
	int row,col,counter = 0,length = 0 ;
	for(row = 0; row < DIM; row++){
		for(col = 0; col < DIM; col++){
			if(arr[row][col] == search_digit){ //if found a search digit, check vertically.
				counter = checkVertical(arr,row,col,search_digit);
				if(counter > length){ //If the found sequence is longer then current length, swap length and update position.
					length = counter; 
					*bestRow = row;
					*bestCol = col;
				}
				counter = checkHorizontal(arr,row,col,search_digit); //if found a search digit, check horizontally.
				if(counter > length){ //If the found sequence is longer then current length, swap length and update position.
					length = counter;
					*bestRow = row;
					*bestCol = col;
				}
				counter = checkDiagonal(arr,row,col,search_digit); //if found a search digit, check diagonally.
				if(counter > length){ //If the found sequence is longer then current length, swap length and update position.
					length = counter;
					*bestRow = row;
					*bestCol = col;
				}
			}
		}	
	}
	return length;
}

/*This functions checks vertically if the number below contains the search digit and counts how long it is.
 * Input: Board's array, current position and search digit.
 * Output: Return length of the consecutive search digit.
 */
int checkVertical(int arr[][DIM],int row, int col,int search_digit){
	int counter = 0;
	while(arr[row][col] == search_digit){ //If it equals search digit, continue searching in that direction
		row++;
		counter++;
	}
	return counter;
}

/*This functions checks diagonally if the number diagonally contains the search digit and counts how long it is.
 * Input: Board's array, current position and search digit.
 * Output: Return length of the consecutive search digit.
 */
int checkDiagonal(int arr[][DIM],int row, int col,int search_digit){ 
	int counter = 0;
	while(arr[row][col] == search_digit){ //If it equals search digit, continue searching in that direction
		row++;
		col++;
		counter++;
	}
	return counter;
}

/*This functions checks horizontally if the number beside it contains the search digit and counts how long it is.
 * Input: Board's array, current position and search digit.
 * Output: Return length of the consecutive search digit.
 */
int checkHorizontal(int arr[][DIM],int row, int col,int search_digit){
	int counter = 0;
	while(arr[row][col] == search_digit){ //If it equals search digit, continue searching in that direction
		col++;
		counter++;
	}
	return counter;
}