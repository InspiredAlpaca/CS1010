#include <stdio.h>
#include <math.h>

float speed_of_sound(float);

int main(void){
	float temp,speed;
	printf("Temperature in degree Fahrenheit: ");
	scanf("%f",&temp);
	speed = speed_of_sound(temp);
	printf("Speed of sound in air of %.2f degree = %.2f ft/sec\n",temp,speed);

	return 0;
}

float speed_of_sound(float temp){
	float s;
	s = (1086) * (sqrt(((5*temp)+297)/247));

	return s;
}
