/*S1010 AY2016/7 Semester 1 Lab1 Ex2
* box.c
* <Compute the surface area and diagnonal between the two furthest point of a box >
* <Wong Kai Min Herman>
* <T13>
*/
int surfaceArea(int,int,int);
double diagonal(int,int,int);
#include <stdio.h>
#include <math.h>

// Write your function prototypes below (and remove this comment!)

int main(void) {

int length, width, height;
	printf("Enter length: ");
	scanf("%d", &length);
	printf("Enter width : ");
	scanf("%d", &width);
	printf("Enter height: ");
	scanf("%d", &height);


	printf("Surface area = %d\n",surfaceArea(length,width,height));
	printf("Diagonal = %.2f\n",diagonal(length,width,height));

	return 0;
}
//function to calculate surface area with input length,width height
int surfaceArea(int l, int w, int h){
	int surface_area;
//calculates surface area of each side and multiply by 2
	surface_area =2* ((l * w) + (l * h) + (h * w));
	
	return surface_area;
	}

double diagonal(int l, int w, int h){
	double diagonal_base,diagonal;
	//find length of box's diagonal base using pythagorean thorem of height and length	
	diagonal_base =(double)sqrt(pow(l,2)+pow(w,2)); 
	//find the diagonal length of the box that are furthest apart using pythagorean therem of diagonal base and height
	diagonal = sqrt(pow(h,2)+pow(diagonal_base,2));

return diagonal;
}
