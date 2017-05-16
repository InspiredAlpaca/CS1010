// pig_latin.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

void convert(char [], char []);

int main(void) {
    int len;
    char sentence[MAX*100],converted[MAX*100] ={'\0'};
	printf("Enter sentence: ");
	fgets(sentence,MAX+1,stdin);
    
	len = strlen(sentence);

	if(sentence[len-1] == '\n')
		sentence[len-1] = '\0';

	convert(sentence,converted);
	printf("\nConverted: %s\n", converted);

	return 0;
}

// Convert src into pig-latin in dest
void convert(char string[], char dest[]) {
	int i = 0,destP = 0;
	char temp;
	while(string[i] != '\0'){
		if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            while(isalpha(string[i])){
            dest[destP] = string[i];
            destP++;
            i++;
            }
            strcat(dest,"way ");
            destP += 4;
            i++;
		}

		else{

			temp = string[i];
			i++;
			while(isalpha(string[i])){
				dest[destP] = string[i];
				destP++;
				i++;
			}
			dest[destP] = temp;
			destP++;
			strcat(dest,"ay ");
            destP += 3;
            i++;
		}
	}
}
