#include <stdio.h>
#define MAX_SIZE 900

int scan(int [],int*);
void print(int [], int);
int slowdown(int [], int [], int, int);
int speedup(int [], int [], int, int);

int main(void) {
    int size,sound[MAX_SIZE],result[MAX_SIZE] = {0},change;
    scan(sound,&size);
	printf("Enter speed change: ");
    scanf("%d",&change);
    printf("The sound wave after speed change: \n");
    
    if(change < 0){
        slowdown(sound,result,size,abs(change));
        print(result, size*abs(change));
    }
    else if(change > 0){
        speedup(sound,result,size,change);
        print(result, size/change);
    }
    
	return 0;
}


int slowdown(int sound[], int result[], int size, int change) {
	int i,j, currentPos = 0;
    for(i = 0; i < size; i++){
        for(j = 1; j <= change ; j++){
            result[currentPos] =  sound[i];
            currentPos ++;
        }
    }
    return 0;
}


int speedup(int sound[], int result[], int size, int change) {
    int i,j, currentPos = 0;
    for(i = 0; i<size; i = i + (change)){

        for(j = i; j< i+change;j++){
        result[currentPos] = (sound[j] + result[currentPos]);

        }

        result[currentPos] = result[currentPos]/change;

        currentPos++;
        
    }
	return 0;
}

// To read in a sound wave
int scan(int sound[], int *size) {
	int i;
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