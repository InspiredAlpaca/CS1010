// pointers.c
// Exercise on using pointers.
#include <stdio.h>
#include <math.h>

void loopfunction(int*,float*);

int main(void) {
	int a,* a_ptr;
	float b, *b_ptr;

	printf("Enter an integer: ");
	scanf("%d", &a);

	printf("Enter a real number: ");
	scanf("%f", &b);
printf("Values entered are %d and %.2lf\n",a,b);
    loopfunction(&a,&b);
    printf("Final value of a = %d\n",a);


	return 0;
}


void loopfunction(int* A,float* B){
 //  printf("value of a: %d, value of b: %lf\n", *A,*B);
    while(*A < pow(*B,2)){
      // printf("%d\n",*A);
        *A =  *A * *B; 
    }
}