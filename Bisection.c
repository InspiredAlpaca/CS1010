/*S1010 AY2016/7 Semester 1 Lab2 Ex3
 * bisection.c
 * <Wong Kai Min Herman>
 * <T13>
 * <This program calculates the root of a polynomial.>
 */

#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.0001


double polynomial(double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
		   pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);
	//Pre-condition that both points are of opposite signs
	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	while((fabs(a-b)) > THRESHOLD){
		m = (a + b)/2; //Calculate Mid point

		pA = polynomial(a,c3,c2,c1,c0);
		pB = polynomial(b,c3,c2,c1,c0);
		pM = polynomial(m,c3,c2,c1,c0);
		//Test iterations
		//printf("a: %.6lf, b: %.6lf, m: %.6lf, \n Pa: %.6lf,pB: %.6lf, pM: %.6lf \n", a,b,m,pA,pB,pM);
		if(pM > 0 && pA > 0){ //Check if mid-point's P value and pA are of the same sign.
			a = m;
		}
		else if(pM < 0 && pA < 0){
			a = m;
		}
		else if(pM == 0){
			break;
		}
		else{
			b = m;
		}

	}

	m = (a + b)/2; //Run the final iteration necessary to get the final answer.
	pM = polynomial(m,c3,c2,c1,c0);

	printf("root = %.6f\n", m);
	printf("p(root) = %.6f\n", pM);

	return 0;
}
//This function calculates the polynomial value at x point
double polynomial(double x,int c3, int c2,int c1,int c0){
	double pValue;
	pValue = c3 * pow(x,3) + c2 * pow(x,2) + c1 * x + c0;
	return pValue;
}
