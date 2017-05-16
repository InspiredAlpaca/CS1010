#include <stdio.h>

int min_unused_area(int,int,int,int,int);
double min_perimeter(double,double);
int max_slab(int,int,int,int);
int main(void) {
	int trayHeight, trayWidth, slabHeight, slabWidth,maxSlab,unusedArea;
	double minPeri;

	printf("Enter size of tray: ");
	scanf("%d %d",&trayHeight, &trayWidth);
	printf("Enter size of slab: ");
	scanf("%d %d",&slabHeight, &slabWidth);

	maxSlab = max_slab(trayHeight,trayWidth,slabHeight,slabWidth);

	unusedArea = min_unused_area(trayHeight,trayWidth,slabHeight,slabWidth,maxSlab);
	printf("Minimum unused area = %d\n",unusedArea); // incomplete
	minPeri = min_perimeter(trayHeight,trayWidth);
	printf("Minimum perimeter after folding = %.2lf\n",minPeri); // incomplete

	return 0;
}

int max_slab(int trayHeight,int trayWidth, int slabHeight, int slabWidth){
	int firstPosition, secondPosition;

	firstPosition =(trayHeight/slabHeight) * (trayWidth/slabWidth);
	secondPosition =(trayHeight/slabWidth) *(trayWidth/slabHeight);

	if(firstPosition > secondPosition)
		return firstPosition;
	else
		return secondPosition;

}

int min_unused_area(int trayHeight,int trayWidth, int slabHeight, int slabWidth, int number){
	int slabArea, trayArea, unusedArea;

	trayArea = trayHeight * trayWidth;
	slabArea = slabHeight * slabWidth;
	unusedArea = trayArea - (slabArea*number);

	return unusedArea;
}

double min_perimeter(double trayHeight,double trayWidth){
	int i;
	for(i = 1; i <= 3; i++){
		if(trayHeight > trayWidth)
			trayHeight = trayHeight/2;
		else if(trayHeight < trayWidth)
			trayWidth = trayWidth/2;
	}
	return (trayHeight+trayWidth)*2;

}

