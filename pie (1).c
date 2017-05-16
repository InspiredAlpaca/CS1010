#include <stdio.h>
#define MAX_SLICES 20
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int maxCherries(int [], int);
int i,size,pieSlice[MAX_SLICES],maxAlice;

int main(){
	printf("Enter number of slices: ");
	scanf("%d",&size);
	printf("Enter numbers of cherries: ");
    for(i = 0; i <size; i++){
        scanf("%d",&pieSlice[i]);
    }
    maxAlice = maxCherries(pieSlice,size);
	printf("The maximum number of cherries Alice can get is %d.\n",maxAlice); // Incomplete
    
	return 0;
}

int maxCherries(int pieSlice[], int size){
    int i, j,k, mostCherries, aliceCherries, totalCherries = 0, highest = 0;
    for(i = 0; i <size; i++){
        totalCherries = totalCherries + pieSlice[i];
       // printf("Total Cherries: %d",totalCherries);
    }
    for(j = 0; j<size; j++){
        mostCherries = 0;
        while(mostCherries <= totalCherries/2){ //What should be my while loop condition?
            //printf("The value of j: %d \t",j);
            //printf("The value of k: %d \t", k);
            //printf("most cherries: %d\n",mostCherries);
            //aliceCherries = mostCherries; 
            
            /*Is there a way to not use aliceCherries variable?
            My problem was that without aliceCherries,i would always 
             * return one iteration of mostCherries = pie[k} +mostcherries
             * */
            aliceCherries = mostCherries;
            mostCherries = pieSlice[k] + mostCherries;
            k++; //Can I not have so many variables like i,j,k. Is there a simpler way?
            k = k%size;
        }
        highest = MAX(highest,aliceCherries); //Is this type of "function" allowed in pratical?
    }
    return highest;
}