/**
 * CS1010 AY2016/7 Semester 1 Lab0 Ex1
 * box_volume.c
 * This program calculates the volume of a box.
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>

int main(void) {

	int length, width, height, volume;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");

	scanf("%d",& height);

	volume = length *  width *  height;

	printf("Volume = %d\n", volume);

	return 0;
}

