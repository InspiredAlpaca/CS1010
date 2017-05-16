// validate.c
// To read age from user, until the 
// age entered is valid (1 - 100).
#include <stdio.h>

int main(void) {    
    int age,
        count;
    
	printf("Enter age: ");
    scanf("%d", &age);
    count = 1;
    while(age > 100 || age < 1){
        printf("Enter age: ");
        scanf("%d",&age);
        count ++;
    }
	printf("Your age is %d.\n", age);
	printf("Number of attempts = %d\n", count);

	return 0;
}