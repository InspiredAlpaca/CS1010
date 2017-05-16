// CS1010 AY2016/7 Semester 1
// PE2 Ex1: spy.c
// Name:Wong Kai Min Herman 
// Matriculation number: A0139964M
// plab account-id: plab1279
// Discussion group: T13
// Description: This program encrpyts the message based on the keyword given.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
#define MAX_LENGTH 80
//Function prototype
void createAlphabet(char [], char []);
void encrypt(char [], char[], char []);
void simplify(char []);

// Do NOT change the main function!
int main(void) {
	char keyword[MAX_LENGTH+1], alphabet[ALPHABET_SIZE+1], message[MAX_LENGTH+1], result[MAX_LENGTH+1];

	printf("Enter keyword: ");
	scanf("%s", keyword);

	printf("Enter message: ");
	scanf("%s", message);

	simplify(keyword);
	createAlphabet(keyword, alphabet);	
	encrypt(message, alphabet, result);

	printf("Encrypted message: %s\n", result);

	return 0;
}
//This function removes duplicate letters in keywords
//Input:keywords
//Output:keywords without duplicated letters
void simplify(char keyword[]){
	int i,j,current = 0;
	char keys[ALPHABET_SIZE] = {0}; //array to store keyword's first occurance
	for(i= 0;keyword[i] != '\0';i++){ //Loops through keyword
		for(j = 0; j < ALPHABET_SIZE; j++){
			if(keyword[i] == keys[j])
				continue;
		}
		keys[current] = keyword[i];	
		current++;
	}
	for(i = 0; i <= current; i++){
		keyword[i] = keys[i];
	}
	keyword[current+1] = '\0';
}
//This functions creates the new alphabets.
//Input keywords
//Output: New alphabets
void createAlphabet(char keyword[], char alphabet[]){
	int len, i, j, alphalen = 0;
	char oldAlphabets[ALPHABET_SIZE];
	len = strlen(keyword);
	strcpy(alphabet,keyword); //Append keywords to the front of alphabets
	alphabet[len] = '\0';
	for(i = 0; i < ALPHABET_SIZE; i++){ //Creates normal alphabets
		oldAlphabets[i] = 'a' + i;
	}
	for(i = 0; i < len; i++){ //converts keyword into spaces for further deletion
		for(j = 0; j < ALPHABET_SIZE; j ++){
			if(keyword[i] == oldAlphabets[j]){
				oldAlphabets[j] = ' ';
			}
		}
	}	
	j =0;
	for(i = 0; i < ALPHABET_SIZE; i++){ //Remove space
		if(!isspace(oldAlphabets[i])){
			oldAlphabets[j] = oldAlphabets[i];
			j++;
			alphalen ++;
		}
	}
	oldAlphabets[alphalen] = '\0';
	strcat(alphabet,oldAlphabets); //joins keyword to alphabets
}
//This functions encrypts the word
//Input: Message, new alphabet
//Output:encrpyted Message
void encrypt(char message[], char alphabet[], char result[]){
	int i,len,position;
	len = strlen(message);
	for(i = 0; i < len; i++){ 
		position = message[i] - 'a'; //get position of it in normal alphat
		result[i] = alphabet[position];
	}
	result[i] = '\0';
}
