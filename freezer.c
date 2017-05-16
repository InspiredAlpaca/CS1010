#include <stdio.h>
#include <math.h>

int main(void){
	float hours, min, time, temp;

	printf("Enter hours and minutes since power failure:" );
	scanf("%f %f",&hours,&min);
;
	time = min/60  + hours;

	temp = 4* pow(time,2) /(time + 2) -20;

	printf(" Temperature in freezer = %.2f\n",temp);


	return 0;
}



