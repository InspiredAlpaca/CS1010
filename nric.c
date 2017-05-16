#include <stdio.h>

char generateCode(int);

int main(void) {    
	int number;
	char code;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &number);

	code = generateCode(number);

	printf("Check code is %c\n", code);

	return 0;
}

// This function generates the check code for NRIC num
char generateCode(int num) {
	char code;
	int a,b,c,d,e,f,g;
	int sum;
	int remainder;

	g = num % 10; //last digit
	f = (num%100)/10; // sixth digit
	e = (num%1000)/100; //fifth digit
	d = (num%10000)/1000; //fourth digit
	c = (num%100000)/10000; //third  digit
	b = (num%1000000)/100000; //second  digit
	a = (num%10000000)/1000000; //first  digit

	a = a*2;
	b = b*7;
	c = c*6;
	d = d*5;
	e = e*4;
	f = f*3;
	g = g*2;

	sum = a + b + c + d + e + f +g;
	remainder = sum % 11;
	remainder = 11 - remainder;
	switch(remainder){
		case 1:
			code = 'A';
			break;
		case 2:
			code = 'B';
			break;
		case 3:
			code = 'C';
			break;	
		case 4:
			code = 'D';
			break;
		case 5:
			code = 'E';
			break;
		case 6:
			code = 'F';
			break;	
		case 7:
			code ='G';
			break;
		case 8:
			code = 'H';
			break;
		case 9:
			code = 'I';
			break;
		case 10:
			code = 'Z';
			break;
		case 11:
			code = 'J';
			break;
		default:
			printf("error\n");
	}

	return code;
}

