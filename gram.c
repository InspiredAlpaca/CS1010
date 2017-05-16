// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 101
#define SIZE 26

//Function prototype
void unigram(char[],int*,char[]);
void bigram(char[],int*,char[]);

int main(void) {
	char text[MAX_SIZE], result[3];
	int len, freq = 0, option;

	printf("Enter text: ");
	fgets(text,MAX_SIZE,stdin);
	len = strlen(text);
	if(text[len-1] == '\n')
		text[len-1] = '\0';
	printf("Enter option: ");
	scanf("%d",&option);
	if(option == 1){
		unigram(text,&freq,result);
		printf("Most frequent unigram: %s\n", result);
		printf("Frequency: %d\n", freq);
	}
	else{
		bigram(text,&freq,result);
		printf("Most frequent bigram: %s\n", result);
		printf("Frequency: %d\n", freq);
	}
	return 0;
}

void unigram(char text[],int*freq,char result[]){
	int i,len,arr[SIZE] = {0};
	len = strlen(text);
//	printf("len: %d\n",len);
	for(i = 0; i < len; i++){
		arr[text[i] - 'a']++;
	}
	for(i = 0; i < SIZE; i++){
		if(arr[i] > *freq){
			*freq  = arr[i];
			result[0] = 'a'+ i;
		}
	}
	result[1] = '\0';
}

void bigram(char text[],int*freq, char result[]){
	int i,j,len,arr[SIZE][SIZE] = {{0}};
	len = strlen(text);
	for(i = 0; i < len-1; i++){
		if(!isspace(text[i]) && !isspace(text[i+1])){
			arr[text[i] - 'a'][text[i+1] - 'a']++;
//			printf("value of arr[i][j] = %d %d\n",text[i]-'a',text[i+1] -'a');
		}
	}
	for(i = 0; i <SIZE; i++){
		for(j =0; j<SIZE; j++){
//			printf("value of arr when i:%d j: %d is %d\n",i,j,arr[i][j]);
			if(arr[i][j] > *freq){
				*freq = arr[i][j];
				result[0] = 'a' + i;
				result[1] = 'a' + j;
			}
		}
	}
	result[2] = '\0';

}
