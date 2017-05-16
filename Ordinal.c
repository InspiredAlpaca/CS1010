#include <stdio.h>

void printSuffix(int x);

int main(int argc, char **argv)
{
	int num;
	printf("Enter value: ");
	scanf("%d", &num);
	printf("%d",num);
	printSuffix(num);
	printf("\n");
	return 0;

}

void printSuffix(int x){
	int num = 0;

	num = x % 10;
	if(((x%10) != 1) && (((x/10)%10) == 1)){
		printf("th");}
	else if((x%10) != 2 && (((x/10)%10) == 1)){
		printf("th");}
	else if(((x%10) != 3) && (((x/10)%10) == 1)){
		printf("th");}
	else if(x %10 ==1){
		printf("st");}
	else if(x %10 ==2){
		printf("nd");}
	else if(x %10 ==3){
		printf("rd");}
	else{
		printf("th");
	}

}


