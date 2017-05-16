#include <stdio.h>

int count_multiples(int);

int main(void) {
	int num, count;

	printf("Enter positive integer: ");
	scanf("%d", &num);
	count = count_multiples(num);
	if(count == 0)
		printf("There are no multiples of 5 or 7 in [1,%d].\n", num);
	else
	printf("There %s %d multiple%s of 5 or 7 in [1,%d].\n",(count > 1) ? "are" : "is",  count,(count >1)? "s": "",  num);
	return 0;
}

// Precond: value > 0
int count_multiples(int value) {
	int i, counter = 0;
	for(i = 1; i <= value; i++){
		if(i % 5 == 0 || i % 7 == 0)
			counter++;
	
	}
return counter;
}

 
