/*S1010 AY2016/7 Semester 1 Lab1 Ex3
 * packing.c
 * <This program computes the maximum number of slabs that can be placed into a tray>
 * <Wong Kai Min Herman>
 * <T13>
 */
#include <stdio.h>

int compute_max_slabs(int,int,int,int);

int main(void) {
	int max_slabs,trayWidth,trayLength,slabWidth,slabLength;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &trayWidth, &trayLength);		
	printf("Enter dimension of slab: ");
	scanf("%d %d", &slabWidth, &slabLength);

	max_slabs = compute_max_slabs(trayWidth,trayLength,slabWidth,slabLength);				
	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

int compute_max_slabs(int tw, int tl, int sw, int sl){
	int horizontal, vertical, max_slab;
	//This computes the number of slabs that can be fit in vertically or horizontally.
	horizontal = (tw/sw) * (tl/sl);
	vertical = (tw/sl) * (tl/sw);

	//this compares the slabs in the horizontal and vertical orientation and find the maximum number of slabs possible.
	if(horizontal > vertical){
		max_slab = horizontal;
	}
	else{
		max_slab = vertical;
	}

	return max_slab;
}



