Nice attempt! For the test case that you failed, you did not check game state immediately after the final move. This resulted in the error


/*CS1010 AY2016/7 Semester 1 Lab3 Ex3
* frogs.c
* <This program allows the user to play a game by moving frogs from the left to the right and vice versa>
* <Wong Kai Min Herman>
* <T13>
*/
#include <stdio.h>

//Function Prototypes
int jump(int, int, int[]);
void printBridge(int, int[]);
int checkGameState(int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position;
	int validity;
	int numMoves = 0;
	int gameState =1;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);
	/*User to input position of frogs
	 * Input precond: Frog represented by 1 or -1 and blank space represented by 0.
	 *frog represented by 1 can only jump to the right and vice versa for -1.
	 */
	for (i=0; i<lengthOfBridge; i++) {
		int frogType;
		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);
		bridge[i] = frogType;
	}
	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);
	printf("Please start moving the frogs\n");
	while(gameState == 1){ //Valid moves are still left to be made
		printf("Move the frog at position: ");
		scanf("%d",&position);
		validity = jump(position,lengthOfBridge,bridge);
		while(validity == 0){ 
			printf("Invalid move!\n");
			printf("Move the frog at position: ");
			scanf("%d",&position);
			validity = jump(position,lengthOfBridge,bridge);
		}
		printBridge(lengthOfBridge, bridge);
		numMoves++;
		gameState = checkGameState(lengthOfBridge,bridge);
	}
	if(gameState == 0) //No more valid Moves
		printf("Oh no! It seems like the two clans of frogs are stuck!");
	else if(gameState == 2) //User has finished the game
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n",numMoves);
	/** Insert your code below **/

	return 0;
}

/* This function "jumps" the frog based on its position to 1/2 position infront of it and returns 1 if valid.
 * Returns 0 if no valid move can be made.
 */
int jump(int position, int size, int bridge[]){
	int validMove = 0;
	switch(bridge[position]){
		case 1:
			if(bridge[position+1] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position+1] = 1; 
				bridge[position] = 0; //previous position becomes 0.
				validMove++;
			}
			else if(bridge[position+2] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position+2] = 1; 
				bridge[position] = 0; //previous position becomes 0.
				validMove++;
			}
			else
				validMove = 0; //Frog is not able to move
			break;

		case -1:
			if(bridge[position-1] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position-1] = -1; 
				bridge[position] = 0; //previous position becomes 0.
				validMove++;
			}
			else if(bridge[position-2] == 0 ){ //if it is empty infront of frog, move forward.
				bridge[position-2] = -1; 
				bridge[position] = 0; //previous position becomes 0.)
				validMove++;
			}
			else
				validMove = 0; //Frog is not able to move
			break;

		case 0:
			validMove = 0; //blank space
	}
	return validMove;
}
/*
 * This function checks the current game state which falls in one of these catergories:
 * 1)There is valid moves left to be made. Returns 1.
 * 2)There is no more valid moves to be made. Returns 0.
 * 3)End of game state. Returns 2.
 */
int checkGameState(int size, int bridge[]){
	int i,j,k, flag = 0;
	for(i = 0; i < size; i++){
		if(bridge[i] == 1){ //If position holds value "1" frog, and there is still a valid move for it, return 1.
			if(bridge[i+1] == 0 || bridge[i+2] == 0 ){
				flag = 1;
				return flag;
			}
		}
		else if(bridge[i] == -1){ //If position holds value "-1" frog, and there is still a valid move for it, return 1.
			if(bridge[i - 1] == 0 || bridge[i - 2] == 0) {
				flag = 1;
				return flag;
			}
		}
		else if(bridge[i] == 0){ //If position is 0 & to check end game state
			for(j = i+1; j < size; j++){ //If there is any position right of 0 that has -1, the game has not ended.
				if(bridge[j] == -1)
					break;
				else if(bridge[j] == 1 && j == size-1){ //If there is no -1 to the right of 0. Check for any 1s to the left of 0.
					for(k = i-1; j > 0;k--){
						if(bridge[k] == 1)
							break; 
						else{
							flag =2; //If no 1s at the left of 0. It means the game has been completed. 
							return flag;
						}
					}
				}
			}

		}

	}

	flag = 0; //if it reaches here it means that no possible move
	printf("Flag value: %d\n",flag);
	return flag;
}

/*
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 */
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}
