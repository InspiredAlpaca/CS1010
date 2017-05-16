// Week11_Points.c
// Read points data and find the area of the smallest
// circle that encloses all the points.
// This is a skeleton program for students.

#include <stdio.h>
#include <math.h>
#define MAX_POINTS 10
#define PI 3.14159

typedef struct{
	int x;
	int y;
} point_t;

int read_points(point_t []);
void print_points(point_t [], int);
float circle_area(point_t [], int);
float length(int, int);
int main(void) {
	point_t points[MAX_POINTS];
	int size;

	size = read_points(points);
	// print_points(points, size); // for checking

	printf("Area of smallest circle = %.2f\n", 
			circle_area(points, size));

	return 0;
}

// Read input data
// Return the number of points read
int read_points(point_t points[]) {
	int i,numPoints;

	printf("Enter number of points: ");
	scanf("%d",&numPoints);
	printf("Enter data for %d points:\n",numPoints);
	for(i = 0; i < numPoints; i++){
		scanf("%d %d",&points[i].x, &points[i].y);

	}
	return numPoints;
}

// Print points data
void print_points(point_t points[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("(%d, %d)\n", points[i].x, points[i].y);
}

// Compute area of the smallest circle that encloses
// all the points.
// This is a stub.
float circle_area(point_t points[], int size) {
	float  max = -1;
	int i;
	for(i = 0; i <size; i++){
		if(length(points[i].x, points[i].y) > max){
			max = length(points[i].x, points[i].y);
		}
	}

		return PI * max * max;
}
float length(int x, int y){
	return pow((x*x + y*y),0.5);
}
