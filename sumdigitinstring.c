// sumDigits.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	int i, sum = 0;
    char str[25];

	printf("Enter input: ");
    fgets(str,25,stdin);
    for(i = 0; i <strlen(str);i++){
        if(isdigit(str[i])){
            sum += str[i] - '0';
        }
        if(isspace(str[i])){
            break;
        }
    }
	printf("Sum = %d\n", sum);

	return 0;
}