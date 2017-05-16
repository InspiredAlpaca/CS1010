/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex3
 * driver.c
 * This program calculate the possible routes given an array of gas stations available within distance.
 * Ho Bing Xuan
 * T13
 */

#include <stdio.h>
#define MAX_STATIONS 20

void readStations(int [], int [], int *, int *);
void printStations(int [], int [], int, int);
int calcPossibleRoutes(int, int [], int [], int, int);

int main(void) {
	int distances[MAX_STATIONS];
	int fuels[MAX_STATIONS];
	int totalDist, numStation;
	int possibleRoute;

	readStations(distances, fuels, &totalDist, &numStation); 
	printStations(distances, fuels, totalDist, numStation); 

	possibleRoute = calcPossibleRoutes(100, distances, fuels, numStation, totalDist);
	//initial gasAvail is 100

	printf("Possible number of routes = %d\n", possibleRoute);

	return 0;
}

// Read the gas stations' distances and available fuel 
// and return the total distance and number of gas stations read.
// Note: Do not change this function
void readStations(int distances[], int fuels[], int *totalDistPtr, int *numStationPtr) {
	int i;

	printf("Enter total distance: ");
	scanf("%d", totalDistPtr);//non-negative integers

	printf("Enter number of gas stations: ");
	scanf("%d", numStationPtr);//non-negative integers

	printf("Enter distance and amount of fuel for each gas station:\n");
	// gasStation Array will store in such way [dist0, fuel0, dist1, fuel1, dist2, fuel2, ...]
	for (i = 0; i < *numStationPtr; i++) {
		scanf("%d %d", &distances[i], &fuels[i]);//distances are integers in increasing order
		//fuels are integers
	}
}

// Print total distance and gas stations' distances and fuel
// Note: Do not change this function
void printStations(int distances[], int fuels[], int totalDist, int numStation) {
	int i;

	printf("Total distance = %d\n", totalDist);
	printf("Number of gas stations = %d\n", numStation);
	printf("Gas stations' distances: ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", distances[i]);
	}
	printf("\n");
	printf("Gas stations' fuel amt : ");
	for (i = 0; i < numStation; i++) {
		printf("%4d ", fuels[i]);
	}
	printf("\n");
}

//return the number of possible routes
int calcPossibleRoutes(int gasAvail, int distances[], int fuels[], int numStation, int totalDist) {
	
	if(numStation == 0) {//if there is no station
		if(totalDist > gasAvail)//and if the totalDist is more than the gasAvail
			return 0;//impossible to finish - 0 possible routes
		else//if gasAvail is enough for toatalDist
			return 1;//only 1 possible route to finish, no station for choice of refill
	}

	else if(numStation == 1) {//last station before destination
		if(gasAvail >= totalDist)//gas is enough even if does not refill
			return 2;//refill or dont refill, 2 possibilities
		else if(gasAvail + fuels[0] < totalDist)
		//gas is not enough even if refilled
			return 0;
		else 
		//gas is enough iff refil
			return 1;
	}

	else {
		if(gasAvail >= distances[1])//gas is enough to reach the next station
			return calcPossibleRoutes(gasAvail+fuels[0], distances+1, fuels+1, numStation-1, totalDist) 
			+ calcPossibleRoutes(gasAvail, distances+1, fuels+1, numStation-1, totalDist);
			//can either refill or not, number of possible routes is the sum refilling and not refilling
		else if(gasAvail < distances[0])//gas is not enough to reach the first station
			return 0;//impossible to finish
		else//can reach the next station iff refill
			return calcPossibleRoutes(gasAvail+fuels[0], distances+1, fuels+1, numStation-1, totalDist);
			//does not contribute any variation in possiblities
	}

}
