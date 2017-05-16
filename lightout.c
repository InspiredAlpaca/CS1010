// CS1010 AY2015/6 Semester 1
// PE2 Ex1: panel.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <stdlib.h>
#define GRID_SIZE 5
#define MAX_LENGTH 30

void readGrid(int grid[][GRID_SIZE]);
void printGrid(int grid[][GRID_SIZE]);
int readSequence(int sequence[]);
void press(int[][GRID_SIZE],int,int[]);
int allOff(int[][GRID_SIZE],int*);

int main(void) {
	int grid[GRID_SIZE][GRID_SIZE], sequence[MAX_LENGTH], length,counter;

	readGrid(grid);

	length = readSequence(sequence);

    press(grid,length,sequence);
    if(allOff(grid, &counter)){
        printf("Number of lighted panels: %d\n",counter);
        printGrid(grid);
    }
    else
        printf("All panels are off.\n");

	
	return 0;
}

void press(int grid[][GRID_SIZE],int seqLen,int sequence[]){
    int i, j,k;
    for(k = 0; k < seqLen; k++){
        i = abs(sequence[k]/5);
        j = sequence[k]%5;
    
    if(i -1 >= 0){ //if first row, it can only go down.
            if(grid[i -1][j] == 0)
                grid[i -1][j] = 1;
            else
                grid[i-1][j] = 0;
        }
    if(i+1 < GRID_SIZE){
            if(grid[i+1][j] == 0)
                grid[i+1][j] = 1;
            else
                grid[i+1][j] = 0;
        }
    if(j+1 < GRID_SIZE){
            if(grid[i][j+1] == 0)
                grid[i][j+1] = 1;
            else
                grid[i][j+1] = 0;
        }
    if(j-1 >= 0){
            if(grid[i][j-1] == 0)
                grid[i][j-1] = 1;
            else
                grid[i][j-1] = 0;
        }
        if(grid[i][j] == 0)
            grid[i][j] = 1;
        else
            grid[i][j] = 0;
             
    }
    
}

int allOff(int grid[][GRID_SIZE], int *counter){
    int i,j;
    *counter = 0;
    for(i = 0; i < GRID_SIZE; i++){
        for(j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] == 1){
                *counter += 1;
            }
        }
    }
    if (*counter == 0)
        return 0;
return 1;
}

// Read the initial state of a grid
void readGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	printf("Enter grid:\n");
	
	for (i=0; i<GRID_SIZE; i++)
		for (j=0; j<GRID_SIZE; j++)
			scanf("%d", &grid[i][j]);
}

// Print the current grid
void printGrid(int grid[][GRID_SIZE]) {
	int i,j;
	
	for (i=0; i<GRID_SIZE; i++){
		for (j=0; j<GRID_SIZE; j++)
			printf("%d ", grid[i][j]);
		printf("\n");
	}
}

// Read the sequence of panels to be pressed
int readSequence(int sequence[]) {
	int i,length;
	
	printf("Enter length of sequence: ");
	scanf("%d", &length);
	
	printf("Enter sequence of panels: ");

	for (i=0; i<length; i++)
		scanf("%d", &sequence[i]);
		
	return length;
}