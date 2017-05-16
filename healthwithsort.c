// Week11_Health_Screen_Complete.c
#include <stdio.h>

#define MAX_READINGS 50   // maximum number of readings

typedef struct {
	float score; // the health score
	int   freq;  // how many people with that score
} reading_t;

void printReadings(reading_t [], int);
void bubbleSort(reading_t [], int);
int unique(reading_t [], int);

int main(void) {
	reading_t readings[MAX_READINGS];  
	int size = 0;

	printf("Enter score and frequency (end with 0 0):\n");
	do {
		scanf("%f %d", &readings[size].score, &readings[size].freq);
		if (readings[size].score > 0.0 && readings[size].freq > 0)
			size++;
		else
			break;
	} while (size < MAX_READINGS);

	// printReadings(readings, size); // for checking
	bubbleSort(readings, size);
	// printReadings(readings, size); // for checking

	printf("Number of unique readings = %d\n",
	       unique(readings, size));

	return 0;
}

// Print array arr
void printReadings(reading_t arr[], int size) {
	int i;

}

// Sort by health score
void bubbleSort(reading_t arr[], int size) {
	int i, limit;
	reading_t temp;

	for (limit = size-2; limit >= 0; limit--) 
		// limit is where the inner loop variable i should end 
		for (i=0; i<=limit; i++) 
			if (arr[i].score > arr[i+1].score)  {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
}

// Find the number of unique readings in arr
// Pre-cond: arr is sorted && size >= 0
int unique(reading_t arr[], int size) {
int count =1, i;
for(i = 0; i < size-1; i++){
	if(arr[i].score != arr[i+1].score)
		count++;
}
return count;
}

