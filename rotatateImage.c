// rotate.c
#include <stdio.h>
#define MAX_SIZE 11

int scan(int [][MAX_SIZE]);
void print(int [][MAX_SIZE], int);
void rotate(int [][MAX_SIZE], int, int);

int main(void) {
    int size,degree, image[MAX_SIZE][MAX_SIZE];
    size = scan(image);
	printf("Enter degree of rotation: ");
    scanf("%d",&degree);
    degree = degree%360;
    rotate(image,size,degree);
	printf("The image after rotation: \n");
    print(image,size);
	return 0;
}

void rotate(int image[][MAX_SIZE], int size, int degree) {
    int i,j,temp;
    switch(degree){
        case 90: //flip horizontall then diagonally.
        for(i = 0; i < size/2; i++){
            for(j = 0; j <size; j++){
                temp = image[i][j];
                image[i][j] = image[size-i-1][j];
                image[size-i-1][j] = temp;
            }
        }
            for(i = 0; i <= size; i++){
        for(j = i+1; j <size; j++){
            temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
        break;
        case 180:
            for(i = 0; i <size;i++){
                for(j = 0; j<size/2;j++){
                    temp = image[i][j];
                    image[i][j] = image[i][size-j-1];
                    image[i][size-j-1] = temp;
                }
            }
            for(i = 0; i <size/2;i++){
                for(j = 0; j<size;j++){
                    temp = image[i][j];
                    image[i][j] = image[size-i-1][j];
                    image[size-i-1][j] = temp;
                }
            }
            break;
        case 270:
        for(i = 0; i <= size; i++){  //If you cut the middle as row, didive by row. if cut middle as column didvde by colum
            for(j = 0; j <size/2; j++){
                temp = image[i][j];
                image[i][j] = image[i][size-j-1];
                image[i][size-1-j] = temp;
            }
        }
            for(i = 0; i <= size; i++){
        for(j = i+1; j <size; j++){
            temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
     break;       
    }
}

// To read in an image
int scan(int image[][MAX_SIZE]) {
    int size, i,j;
	printf("Enter size: ");
    scanf("%d", &size);
	printf("Enter values: \n");
    for(i = 0; i < size; i++){
        for(j = 0; j <size; j++){
            scanf("%d", &image[i][j]);
            }
    }
return size;

}
// To print an image
void print(int image[][MAX_SIZE], int size) {
	int row, col;
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) 
			printf("%d ", image[row][col]);
		printf("\n");
	}
}