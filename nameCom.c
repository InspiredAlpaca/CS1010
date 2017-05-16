// CS1010 AY2013/4 Semester 1
// PE2 Ex1: compatible.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Given two names, strike off matching letters in the names,
// find the number of remaining letters in the names, and 
// determines if the names are compatible.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Name has at most 35 characters
#define MAXLEN 36

// Fill in your function prototypes below
void readName(char[]);
int  match(char[],char[]);
void removeSpace(char[]);
int main(void) {
	char name1[MAXLEN], name2[MAXLEN];
	int remain1,   // number of remaining characters in name1 
		remain2;   // and name2 after matching

	printf("Enter 2 names below:\n"); // given, do not remove/change this line
	readName(name1);                  // given, do not remove/change this line
	readName(name2);                  // given, do not remove/change this line

	// Call the match() function here
	match(name1,name2);
	remain1 = strlen(name1);
	remain2 = strlen(name2);
	printf("Number of letters remaining in 1st name = %d\n", remain1);
	printf("Number of letters remaining in 2nd name = %d\n", remain2);

	if(match(name1,name2))
	printf("The names are compatible.\n");
	else
	printf("The names are not compatible.\n");

	return 0;
}

// To students: You must write the function's description here. [1 mark]/
void readName(char name[MAXLEN]){
	int len;
	fgets(name,36,stdin);
	len = strlen(name);
	if(name[len-1] == '\n')
		name[len-1] = '\0';
}


// To students: You must write the function's description here. [1 mark]
// match() function
int  match(char name1[MAXLEN],char name2[MAXLEN]){
	int i = 0, j,len;
	while(name1[i] != '\0'){ //Loop through the entire string
		len = strlen(name2);
		for(j = 0; j < len; j++){
			if(tolower(name1[i]) == tolower(name2[j])){
				name1[i] = ' ';
				name2[j] = ' ';
			}
		}
		i++;
	}
	removeSpace(name1);
	removeSpace(name2);
	if((strlen(name1) % 2 == 1 && strlen(name2) %2 == 1) || ((strlen(name1) %2 == 0 && strlen(name2) %2 == 0)))
			return 1;
	return 0;
	}


			void removeSpace(char name[MAXLEN]){
			int i=0, j=0;
			while(name[i] != '\0'){
			if(isalpha(name[i])){
			name[j] = name[i];
			j++;
			}
			i++;
			}
			name[j] = '\0';
			}
