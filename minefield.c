// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
void printField(int [][MAX_SIZE], int);
void detonate(int [MAX_SIZE][MAX_SIZE], int [MAX_SIZE][MAX_SIZE],int,int*,int*);
int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE] = {{0}};
	int size,damage = 0,safeArea = 0;

	size = readField(field);
	detonate(field,aftermath,size,&safeArea,&damage);
	printf("Aftermath: \n");
	printField(aftermath, size);
	printf("Maximum damage: %d\n",damage); // Incomplete
	printf("Number of safe areas: %d\n",safeArea); // Incomplete

	return 0;
}

void detonate(int field[][MAX_SIZE],int aftermath[][MAX_SIZE],int size,int*safe, int*damage){
	int i,j,k,l,max = 0;
	for(i = 0; i < size; i++){ 
		for(j = 0; j <size; j++){
			if(field[i][j] != 0){
				k = i;
				for(l=0; l<field[i][j] -1;l++){ //explode upwards
					k--;
					if(k >= 0){
						(aftermath[k][j])++;
					}
					else
						break;
				}
			
			k = i;
			for(l=0; l<field[i][j]-1;l++){ //explode upwards
				k++;
				if(k <= size){
					(aftermath[k][j])++;
				}
				else
					break;
			}
			k = j;
			for(l=0; l<field[i][j]-1;l++){ //explode upwards
				k++;
				if(k <= size){
					(aftermath[i][k])++;
				}
				else
					break;
			}
			k = j;
			for(l=0; l<field[i][j]-1;l++){ //explode upwards
				k--;
				if(k >= 0){
					(aftermath[i][k])++;
				}
				else
					break;
			}

			aftermath[i][j]++; 
            
	}
	}
	}
    	for(i = 0; i < size; i++){ 
		for(j = 0; j <size; j++){
            if(aftermath[i][j] == 0){
            *safe += 1;
            }
            if(aftermath[i][j] > max)
                max = aftermath[i][j];
        }
        }
    *damage = max;
}



// Read in a minefield
// Do NOT modify this function!
int readField(int field[][MAX_SIZE]) {
	int i,j, size;

	printf("Enter size: \n");
	scanf("%d", &size);

	printf("Enter minefield: \n");
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			scanf("%d", &field[i][j]);

	return size;
}

// Print a minefield
// Do NOT modify this function!
void printField(int field[][MAX_SIZE], int size) {
	int i,j;

	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}