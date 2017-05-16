/**
 * CS1010 AY2016/7 Semester 1 Lab5 Ex1
 * prerequisites.c
 * <This program checks if the module has prerequisite in the list>
 * <Wong Kai Min Herman>
 * <T13>
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_MOD 10
#define MAX_LEN 7

//Function prototype
int firstdigit(char [], char []);
int sameChars(char [], char []);
int otherDigits(char [], char []);
int scanModules(char[][MAX_LEN]);
int computePrereq(char[][MAX_LEN], int, char[], char[][MAX_LEN]);
void printPrereq(char[][MAX_LEN], int, char[]);

int main(void)
{
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],        // the list of modules codes
		 target[MAX_LEN],                 // the target module
		 prerequisites[MAX_MOD][MAX_LEN]; // prerequisites of the target module

	numModules = scanModules(codes);
	printf("Choose a module: ");
	scanf("%s", target);
	numPrereq = computePrereq(codes, numModules, target, prerequisites);
	printPrereq(prerequisites, numPrereq, target);
	return 0;
}
/*This function computes if the module has any prerequisites.
 * Input: List of modules, Module to check, number of modules.
 * Output: List of prerequisites if any.
 * Preconditions: Minimum of 2 modules and maximum of 10 modules which are distinct.
 */
int computePrereq(char codes[][MAX_LEN], int numModules, char target[], char prerequisites[][MAX_LEN]){
	int i, validity,j = 0, validMod = 0;

	for(i = 0; i < numModules; i++) { //Checks if the target module exists in the input list 
		if(!strcmp(codes[i],target))
			validMod = 1;
	}
	if(validMod != 1)
		return -1; 

	for(i = 0; i < numModules; i++) {

		validity = (sameChars(codes[i], target)); //Check if the first 2 characters are the same
		if(validity == 0){
			continue;
		}        
		validity = (firstdigit(codes[i], target)); //Check if the first digit is less than target module's 
		if(validity == 0){
			continue;
		}
		validity = (otherDigits(codes[i], target)); //Check if the last four digits are less or equal than target module's
		if(validity == 0){
			continue;
		}
		strcpy(prerequisites[j],codes[i]); //Copy module into prerequisites list if criteria are met
		j++;
	}
	if(j == 0) //No prequisite
		return 0;
	else
		return j;
}

/*This function checks if the first 2 characters are the same.
 * Input: List of modules and target.
 * Output: If module match's prerequisite criteria return 1
 */
int sameChars(char codes[], char target[])
{
	if(codes[0] == target[0] && codes[1] == target[1])
		return 1;
	return 0;
}

/*This function checks the module's first digit/third char if it is less than target module first digit.
 * Input: List of modules and target.
 * Output: If module match's prerequisite criteria return 1
 */
	int firstdigit(char codes[], char target[]){
		if(codes[2] < target[2])
			return 1;
		return 0;
	}

/*This function checks the module's last four digit and check if it is equal or less than target module's digits.
 * Input: List of modules and target.
 * Output: If module match's prerequisite criteria return 1
 */
int otherDigits(char codes[], char target[]){
	int i;
	for(i = 3; i <MAX_LEN - 1; i ++){
		if(!(codes[i] <= target[i]))
			return 0;
	}
	return 1;
}

// Print the prerequisites
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[])
{
	int i;

	if(numPrereq == -1) {
		printf("No such module %s\n", target);
	} else if(numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	} else {
		printf("Prerequisites for %s:", target);
		for(i = 0; i < numPrereq; i++) {
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}
/*This function scans in the number of modules & module codes.
 *Input:2D array for module code
 *Output:number of modules & module code
 *Precondition: Module code maximum of 6 characters & at least 2 modules
 */
int scanModules(char codes[][MAX_LEN])
{
	int size, i;
	printf("Enter number of modules: ");
	scanf("%d", &size);
	printf("Enter %d modules:\n", size);
	for(i = 0; i < size; i++) {
		scanf("%s", codes[i]);
	}

	return size;
}
