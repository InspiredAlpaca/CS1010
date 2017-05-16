/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex2
 * elevator.c
 * <This program simulates the elevator's movement and return the end state >
 * <Wong Kai Min Herman>
 * <T13>
 */
#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

typedef struct { 
	int currentFloor;
	int passengers;
	int usage;
} elevator_t;

//Function prototype
void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS];
	char sequences[MAX_ELEVATORS][MAX_LEN];

	printf("Enter number of elevators: ");
	scanf("%d", &size);

	setupElevators(elevators, size);
	readSequences(sequences, size);

	runElevators(elevators, sequences, size);

	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));

	return 0;
}
/*This functions initalizes n number of elevators array to the respective values
 * Input: Array of elevator_t structure & size
 * output:Initialized array of elevator
 * Precond: Size must not exceed 5
 */
void setupElevators(elevator_t elevators[], int size){
	int i;
	for(i = 0; i < size; i ++){ 
		elevators[i].currentFloor = 1;
		elevators[i].passengers = 0;
		elevators[i].usage = 0;
	}
}	

// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i;

	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}
/*This functions simulates the elevator as it goes through the sequence
 * Input: Array of elevator_t structure,sequence, size
 * output:Updated elevator's floor,passengers & usage
 * Precond: Elevator's single sequence must be from 1-9
 */
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int i,j,len;
	for(i = 0; i < size; i ++){ //Loop through the number of elevators
		len = strlen(sequences[i]);
		for(j = 0; j < len; j++){ //Look through length of sequence
			goToFloor(&elevators[i],sequences[i][j]-48); //Minus 48 due to ASCII value
		}
	}
}

/*This function updates the number of passengers,floor and usage after every level
 * Input: Address of elevator to be updated and floor
 * output:Updated elevator's floor,passengers & usage
 * Precond: Elevator's single sequence must be from 1-9
 */
void goToFloor(elevator_t *elevator, int floor){
	if((*elevator).currentFloor < floor){ //If elevator's current floor is less than new floor (Go up)
		elevator->passengers += floor; //Add passengers
		if(elevator->passengers > 15){ //Check capacity - Max only 15
			elevator->passengers = 15;
		}
		elevator->currentFloor = floor; //Update current floor
	}
	else if(elevator->currentFloor > floor){//If elevator's current floor is greater than new floor(Go down)
		if(elevator->passengers > 0){ //Check if there are any passenger left
			if(elevator->passengers < floor){ //If passengers less than passenger supposed to leave based on floor num
				(*elevator).usage += elevator->passengers;  //Empty the elevator 
				elevator->passengers = 0;
			}
			else{
				elevator->passengers -= floor; //If number of passengers equal or greater than number leaving the elevator
				(*elevator).usage += floor; 
			}
		}
		elevator->currentFloor = floor;
	}
}

/*This functions prints the respective value in elevator_t structure for each element in the array
 * Input: Array of elevator_t structure & size
 * output: Display respective value for each element of elevator array.
 */
void printElevators(elevator_t elevators[], int size){
	int i;
	for(i = 0; i < size; i ++){
		printf("Elevator %d:\n",i+1); 
		printf("Floor: %d\n",elevators[i].currentFloor);
		printf("Number of passengers: %d\n",elevators[i].passengers);
		printf("Usage: %d\n",elevators[i].usage);
	}
}

/*This functions computes the elevator with highest usage
 * Input: Array of elevator & size
 * output: Highest usage elevator
 */
int mostUsedElevator(elevator_t elevators[], int size){
	int i, max = -1, mostUsed;
	for(i = 0; i < size; i++){
		if(elevators[i].usage > max){
			max = elevators[i].usage;
			mostUsed = i+1;
		} 
	}
	return mostUsed;
}

