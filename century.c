#include <stdio.h>
#include <math.h>

// CS1010 AY2011/2 Semester 1
// PE1 Ex1: century.c
// Name:
// Matriculation number:
// plab account-id:
// Discussion group:
// Description:
int printCentury(int);
void printOrdinal(int);

int main(void)
{

	int year,century; // user’s input
	printf("Enter year: ");
	scanf("%d",&year);
	century = printCentury(year);
	printf("The year %d falls in the %d",year,century);
	printOrdinal(century);
	printf(" century.\n");
	return 0;
}

int printCentury(int year){
	int century;
	if(year < 100)
		century =  1;
	else
	century = (year/100)+1;

	return century;
}

void  printOrdinal(int year){

	if(year % 100 <=13 && year %100 >= 11)
		printf("th");
	else if(year % 10 == 1)
		printf("st");
	else if (year % 10 == 2)
		printf("nd");
	else if (year % 10 == 3)
		printf("rd");
	else 
		printf("th");
}
