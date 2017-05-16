// CS1010 AY2015/6 Semester 1
// PE2 Ex2: email.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 51
int checkemail(char []);
int main(void){
	char email[MAX_LENGTH];

	printf("Enter email address: ");
	scanf("%s", email);
	
	if(checkemail(email)== 0)
	printf("This email address is not valid.\n");
	else if(checkemail(email) == 1)
	printf("This email address is valid but not friendly.\n");
	else
	printf("This email address is valid and friendly.\n");

	return 0;
}

int checkemail(char email[]){
	char *pointer;
	int value,i;
	int atindex;
	pointer = strchr(email,'@'); //checks if the domain is correct
	if(pointer == NULL)
		return 0;
	value = strcmp(pointer+1,"u.nus.edu");
	if(value !=0)
		return 0;
	if(!isalpha(email[0])){ //if first letter is not a letter.
		return 0;
	}
	atindex = pointer - email;
	if(atindex <  3 || atindex > 21)
		return 0;
	for(i = 0; i < atindex; i++){
		if(isalpha(email[i]) || isdigit(email[i]) || email[i] == '.')
			continue;
		else
			return 0;
	}
	if(email[0] == 'a' || email[0] =='e'){
		for(i = 0; i < 8; i++){
		if(!isdigit(email[i]))
			break;
		}
		if(email[8] != '@')
			return 2;
		return 1;
}	

return 2;
}
