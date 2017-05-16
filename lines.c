// CS1010 AY2015/6 Semester 2 PE1 Ex1
//
// line.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

double computeK(double,double,double,double);
int determineType(double, double, double);
void printMessage(int);

#include <stdio.h>

int main(void) {
int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
double slopeAB,slopeCD,slopeAC,value;

	printf("Enter the coordinates of A: ");	 
    scanf("%d %d", &Ax,&Ay);
	printf("Enter the coordinates of B: ");	
    scanf("%d %d", &Bx,&By);
	printf("Enter the coordinates of C: ");
    scanf("%d %d", &Cx,&Cy);
	printf("Enter the coordinates of D: ");
    scanf("%d %d", &Dx,&Dy);
    
    slopeAB = computeK(Ax,Ay,Bx,By);
    slopeCD = computeK(Cx,Cy,Dx,Dy);
    slopeAC = computeK(Ax,Ay,Cx,Cy);
    value = determineType(slopeAB,slopeCD,slopeAC);
    printMessage(value);
	return 0;
}

double computeK(double x1,double y1,double x2,double y2){
    double slope;
    double y,x;
    //printf("I am taking y1-y2/ x1-x2 which are:/t (%d - %d) / (%d-%d)\n", y1,y2,x1,x2);
   // printf("y1 - y2 = %lf\n",(y1-y2));
   // printf("x1 - x2 = %lf\n",(x1-x2));
   // printf("the value of y1 is: %lf\n",y1);
     y = (double)y1 - y2;
     x = (double)x1 - x2;
   // printf("y = %lf\n", y);
  //  printf("x = %lf\n",x);
     slope = y/x;
    //slope = ((double)y1-y2)/(x1-x2);
   // printf("Sloppe is %lf\n",slope);
    return slope;
}

int determineType(double AB, double CD, double AC){
    if(AB == CD && AB != AC && CD !=AC)
        return 1;
    else if(AB != CD)
        return 2;
    else if(AB == CD && CD == AC)
        return 3;
}
void printMessage(int value){
    if(value == 1)
        printf("The two lines are parallel.\n");
    else if(value == 2)
        printf("The two lines are intersecting.\n");
    else if(value ==3)
        printf("The two lines are overlapping.\n");
return;

}