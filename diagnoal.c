#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

void scanMatrix(int [][MAX_COL], int);
void printMatrix(int [][MAX_COL], int);
int is_diagonal(int [][MAX_COL], int);
int is_upper_triangular(int [][MAX_COL], int);

int main(void) {
	int matrix[MAX_ROW][MAX_COL]; 
	int result2,result,size;

	scanf("%d", &size);
	scanMatrix(matrix, size);
	printf("Matrix read:\n");
	printMatrix(matrix, size);
	result = is_diagonal(matrix,size);
	if(result){
		printf("Matrix is not a diagonal matrix.\n");
	}
	else{
		printf("Matrix is a diagonal matrix.\n");
	}
	// Complete the program
	result2 = is_upper_triangular(matrix,size);
	if(result2){
		printf("Matrix is not an upper triangular matrix.\n");
	}
	else{
		printf("Matrix is an upper triangular matrix.\n");
	}
	return 0;
}

// Return 1 if matrix is diagonal, otherwise return 0.
int is_diagonal(int mtx[][MAX_COL], int size) {
	// Complete the code
	int i,j;
	for(i = 0; i<size; i++){
		for(j = 0; j<size; j++){
			if(i == j){
			continue;
			}
			if(mtx[i][j] != 0){
			return 1;
			}
		}
	}
	return 0; // this is a stub
}

// Return 1 if matrix is upper-triangular, otherwise return 0.
int is_upper_triangular(int mtx[][MAX_COL], int size) {
	// Complete the code
	int i,j;
		for(i = 0; i<size;i++){
			for(j = 0; j<size;j++){
				if(i > j){
					if(mtx[i][j] != 0){
					return 1;
					}
				}
			}
		}
	return 0; // this is a stub
}

// To read values into mtx
void scanMatrix(int mtx[][MAX_COL], int size) {
	int row, col;

	for (row=0; row<size; row++)
		for (col=0; col<size; col++) 
			scanf("%d", &mtx[row][col]);
}

// To print values of mtx
void printMatrix(int mtx[][MAX_COL], int size) {
	int row, col;

	for (row=0; row<size; row++) {
		for (col=0; col<size; col++) 
			printf("%4d", mtx[row][col]);
		printf("\n");
	}
}

