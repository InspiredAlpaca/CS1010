// pair.c
#define MAX_SIZE 10
#include <stdio.h>

int findPair(int [MAX_SIZE], int, int, int *, int *);

int main() {
	int num1, num2,size,i,target,arr[MAX_SIZE];


	printf("Please enter the number of elements: ");
    scanf("%d",&size);
	//input the elements into array
	printf("Please enter %d integers: ", size);
    for(i = 0; i<size; i++){
        scanf("%d", &arr[i]); 
    }

	printf("Please enter the target sum: ");
    scanf("%d",&target);
    if(findPair(arr,size,target,&num1,&num2))
        printf("The pair of values are %d and %d.\n",num1,num2);
    else
        printf("No solution!\n");
        
	return 0;
}

int findPair(int arr[MAX_SIZE], int size, int target, int *pointer1, int *pointer2){
    int i = 0,j = size -1;
    while(i != j){

        if(target - arr[i] < arr[j]){
            //printf("value of target is %d, value of arr[%d] is %d, value of arr[%d] is %d\n",target,i,arr[i],j,arr[j]);
            j--;
            
        }
        else if(target - arr[i] > arr[j]){
           // printf("value of target is %d, value of arr[%d] is %d, value of arr[%d] is %d\n",target,i,arr[i],j,arr[j]);
            i++;
            
        }
        else if(target - arr[i] == arr[j]){
            //printf("value of target is %d, value of arr[%d] is %d, value of arr[%d] is %d\n",target,i,arr[i],j,arr[j]);
            *pointer1 = arr[i];
            *pointer2 = arr[j];
            return 1;
        }
    }
return 0;
}
