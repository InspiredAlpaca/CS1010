#include <stdio.h>

int get_magic(int x);


int main(void){
    
 int x;

    printf("Enter 1st value: ");
    scanf("%d",&x);
    printf("Magic number = %d\n",get_magic(x));
    
    printf("Enter 2nd value: ");
    scanf("%d",&x);
    printf("Magic number = %d\n",get_magic(x));


	return 0;
}

int get_magic(int x){
    
    int sum = 0;
    
    while(x > 0){
    sum += x % 10;
    x /= 100;
    //printf("the sum is %d\n", sum);
    }
    
    return (sum % 10);
    
}