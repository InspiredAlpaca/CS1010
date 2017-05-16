// palindrome.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 20

int isPalindrome(char []);

int main(void) {
    int len;
	char word[MAXLEN+1];

	printf("Enter word: ");
    fgets(word,MAXLEN,stdin);
    len = strlen(word);
    if(word[len-1] == '\n'){
        word[len-1] = '\0';}

    //scanf("%s",word);
    printf("\"%s\"",&word);

	if (isPalindrome(word))
		printf(" is a palindrome.\n");
	else
		printf(" is not a palindrome.\n");

	return 0;
}

// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char str[]) {
    int i,j;
    for(i = 0, j = strlen(str)-1; i < strlen(str)/2; i++,j--){
        if(tolower(str[i]) == tolower(str[j]))
            continue;
        else
            return 0;
    }


	return 1;
}