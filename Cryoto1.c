// rot.c

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 80

void encrypt(char [], char []);
void decrypt(char [], char []);

int main(void) {
    int value;
    char message[MAX_LENGTH], result[MAX_LENGTH];
	printf("Enter 1 for encryption, 2 for decryption: ");
    scanf("%d",&value);
	printf("Enter message: ");
    scanf("%s",message);
    if(value == 1){
        encrypt(message,result);
        printf("Encrypted message: %s\n",result);
    }
    else{
        decrypt(message,result);
        printf("Decrypted message: %s\n",result);
    }
	return 0;
}

// Encrypt a message based on transpose-13 algorithm
void encrypt(char message[], char result[]){
    int len,i;
    len = strlen(message);  
    for(i = 0; i < len; i++){
        if(message[i]  < 96){
            if(message[i] < 78){
                result[i] = message[i] + 13;
            }
            else{
                result[i] = message[i] - 13;
            }
        }
        else{
            if(message[i] < 110){
                result[i] = message[i] + 13;
            }
            else{
                result[i] = message[i] - 13;
            }
        }
    }
    result[len] = '\0';
}

// Decrypt a message based on transpose-13 algorithm
void decrypt(char message[], char result[]){
        int len,i;
    len = strlen(message);  
    for(i = 0; i < len; i++){
        if(message[i]  < 96){
            if(message[i] < 78){
                result[i] = message[i] + 13;
            }
            else{
                result[i] = message[i] - 13;
            }
        }
        else{
            if(message[i] < 110){
                result[i] = message[i] + 13;
            }
            else{
                result[i] = message[i] - 13;
            }
        }
    }
        result[len] = '\0';
}