// magic_square.c
// To generate a magic square for nxn matrix (n is odd integer)

#include <stdio.h>
#define MAX_SIZE 15

void printMagic(int [][MAX_SIZE], int);
void generateMagic(int [][MAX_SIZE], int);

int main(void) {
	int magic[MAX_SIZE][MAX_SIZE] = { {0} }; 
	int size; 

	printf("Enter size of matrix: ");
	scanf("%d", &size);
	printf("%d\n", size);
	generateMagic(magic, size);
	printMagic(magic, size);

	return 0;
}

// To generate the magic square
void generateMagic(int arr[][MAX_SIZE], int size) {
    int num,row,col,next_row,next_col; 
    row = 0;
    col = size/2;
    arr[row][col] = 1;
    for(num = 2; num<= size*size; num++){
           
            next_row = (row  -1 + size) % size;
            next_col = (col + 1) % size;
             //printf("Current next matrix: %d,%d\n",next_row,next_col);

            if(arr[next_row][next_col] > 0)
                row = (row + 1)%size; //Bring it back to top of matrix if necessary
            else{

                row = next_row;
                col = next_col;
            }
           arr[row][col] = num; 

    }

}


// To print the magic square
void printMagic(int arr[][MAX_SIZE], int size) {
	int row, col;

	for (row=0; row<size; row++) {
		for (col=0; col<size; col++) 
			printf("%5d", arr[row][col]);
		printf("\n");
	}
}