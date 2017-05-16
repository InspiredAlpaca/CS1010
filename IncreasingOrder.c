// check_order.c
// Repeatedly reads positive integer, until the input value
// is zero, or the data are not in increasing order.

#include <stdio.h>

int main(void) {
    int input, value, flag;
    flag = 1;
    value = 0;
    
    while(flag == 1){
        printf("Enter positive integer: ");
        scanf("%d",&input);
        if(input > value){
            value = input;
            flag = 1;
        }
        else if(input == 0){
            printf("Data are in increasing order.\n");
            flag = 0;
        }
        else if(input < value || input == value){
            printf("Data are not in increasing order.\n");
            flag = 0;
        }
    }
    return 0;
}
