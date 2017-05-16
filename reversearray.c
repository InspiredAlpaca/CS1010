// reverse_array.c
// Reverse all values in an integer array.
#include <stdio.h>
#define MAX_SIZE 15

int readArray(int []);
void printArray(int [], int);
void reverseArray(int [], int);

int main(void) {
	int list[MAX_SIZE], size;

	size = readArray(list);
	reverseArray(list, size);

	printArray(list, size);

	return 0;
}

// Read values into array.
// Return number of elements read.
int readArray(int arr[]) {
	int size, i;
	FILE *infile;
	infile = fopen("array.in","r");
	fscanf(infile,"%d",&size);
	for (i=0; i<size; i++){
		fscanf("%d", &&arr[i]);
	}
	fclose(infile);
	return size;
}

// Print values in array
void printArray(int arr[], int size) {
	int i;
	FILE *outfile;
	outfile = fopen("array.out", "w");
	for (i=0; i<size; i++){
		fprintf(outfile, "%d\n",arr[i]);
	}
	fclose(outfile);
}

// Reverse all the values in the array arr
// Pre-cond: size >= 1
void reverseArray(int arr[], int size) {
int i, temp;
	
	for(i = 0; i < size/2; i++){
		temp = arr[i];
		arr[i]= arr[size-i-1];
		arr[size-i-1] = temp;
	}
}


