// ilink.c
#include <stdio.h>
#define MAXSIZE 11

void printArr(int [][MAXSIZE], int);
//void readFriends(int [][MAXSIZE], int);
void iSolitude(int [][MAXSIZE], int);
void uFriend(int [][MAXSIZE], int);

int main() {
	int friendArr[MAXSIZE][MAXSIZE] = { {0} };
	int size, pairsNum;
	int i, j, k;

	printf("Read in the number of users: ");
	scanf("%d", &size);

	printf("There are %d users, indexed from 0 to %d.\n", size, size-1);
	printf("Enter the number of pairs of direct friends: ");
	scanf("%d", &pairsNum);

	printf("Enter actual pairs of direct friends:\n");

	for (k = 0; k < pairsNum; k++) {
		scanf("%d %d", &i, &j);
		friendArr[i][j] = 1;
	}

	printArr(friendArr,size);

	for (i = 0; i < size; i++) {
		friendArr[i][i] = 1;
		for (j = i+1; j < size; j++) {
			if (friendArr[i][j] != friendArr[j][i]) {
				friendArr[i][j] = 1; 
				friendArr[j][i] = 1;
			}
		}
	}

	printf("The friendship matrix is:\n");
	printArr(friendArr, size);

	iSolitude(friendArr, size);

	uFriend(friendArr, size);

	return 0;
}

void printArr(int arr[][MAXSIZE], int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}

void uFriend(int arr[][MAXSIZE],int size){
    int i,j,k;
    for(i = 0; i<size;i++){
        for(j = 0; j<size; j++){
            if(arr[i][j] == 1 && i != j && j != size-1){
                for(k = j+1; k <size; k++){
                    if(arr[i][k] == 1 && k != i){
                        if(arr[j][k] == 0){
                            arr[j][k] = 2;
                            
                        }
                    }
                }
            } 
        }
    }
 
    for(i = 0; i<size;i++){
        for(j = 0; j<size; j++){
            if(arr[i][j] == 2){
            printf("(%d,%d) has a friend-of-friend relation.\n",i,j);
            }
        }
    }    
}

void iSolitude(int arr[][MAXSIZE],int size){
    int i,j,min,finalMin = 7;
    for(i = 0; i<size; i++){
        min = 0;
        for(j=0; j<size;j++){
            min += arr[i][j];
        }
        if(min < finalMin)
            finalMin = min;
            
    }
    printf("The least number of friends found is %d\n",finalMin);
    for(i = 0; i<size; i++){
        min = 0;
        for(j=0; j<size;j++){
            min += arr[i][j];
        }
        if(min == finalMin)
            printf("User %d has least number of friends\n",i);
    }
}