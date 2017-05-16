// echo.c

#include <stdio.h>
#define MAX_SIZE 10000

int scan(int [],int*);
void print(int [], int);
int echo(int [], int [], int, int, int);

int main(void) {
    int sound[MAX_SIZE],result[MAX_SIZE],copies,decay,size;
    
    scan(sound, &size);
	printf("Enter number of echoes and decay percentage: ");
    scanf("%d %d",&copies, &decay);
    echo(sound,result,size,copies,decay);
	printf("The sound wave with echoes added: \n");
    print(result,size*(copies+1));
	
    return 0;
}

// To add echo effects to a sound wave and return the size 
// of the resulting sound wave.
// Precond: 
int echo(int sound[], int result[], int size, int copies, int decay) {
    int i = 0, j = size, k = 0; //Is there another way i do not need this 'k' variable?
    for(i = 0; i<size;i++){
        result[i] = sound[i];
    }
    while(j < size*(copies+1)){  //copies + 1 to take into consideration the initial sound wave. Any better way instead of copies+1*size?
        result[j] = result[k]*(1-decay/100.0);
    j++;    //is there another way to do this?
    k++;
    }
	return 0;
}

// To read in a sound wave
int scan(int sound[],int*size) {
    int i,count;
	printf("Enter size: ");
    scanf("%d", size);
	printf("Enter values: \n");
    for(i = 0; i < *size; i++){
        scanf("%d",&sound[i]);
    }
	return 0;
}

// To print a sound wave
void print(int sound[], int size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%d ", sound[i]);
	printf("\n");
}