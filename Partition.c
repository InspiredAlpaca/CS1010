// partition.c
#include <stdio.h>
#define N 20

void printArray(int [], int);
void partition(int[],int,int);

int main(void) {
    int size,i,pivot,array[N];
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    printf("Enter %d integers: ", size);
    for(i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    printf("Enter pivot: ");
    scanf("%d", &pivot);
    partition(array,size,pivot);
    // printf("rubbish");
    printArray(array,size);
    
    
    return 0;
}

// Print array arr
void printArray(int arr[], int size) {
    int i;
    //  printf("rubbish");
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void partition(int array[],int size,int pivot){
    int i,sIndex = 0,temp;
    
    for(i = 0; i < size; i++){
        if(array[i] < pivot){
            temp = array[i];
            array[i] = array[sIndex];
            array[sIndex] = temp;
            sIndex ++; //end of small number
        }
    }
    
}

