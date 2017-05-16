// transpose.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_ROWS 10    // maximum number of rows
#define MAX_COLS 10    // maximum number of columns
#define MAX_LENGTH 100 // maximum number of characters in the message & result

int encrypt(int, int, char[], char[]);
int decrypt(int, int, char[], char[]);

int main(void)
{
    int code, row, col; // Please change result
    char len, dummy, result[MAX_LENGTH], message[MAX_LENGTH];

    printf("Enter 1 for encryption, 2 for decryption: ");
    scanf("%d", &code);
    printf("Enter dimensions of a 2D array: ");
    scanf("%d %d", &row, &col);
    printf("Enter message: ");
    scanf("%c", &dummy);
    fgets(message, MAX_LENGTH, stdin);
    len = strlen(message);
    if(message[len - 1] == '\n')
        message[len - 1] = '\0';
    if(code == 1)
        if(encrypt(row, col, message, result))
            printf("Encrypted message: %s\n", result);
        else
            printf("Encryption failed.\n");
    else if(decrypt(row, col, message, result))
        printf("Decrypted message: %s\n", result);
    else
        printf("Decryption failed.\n");

    return 0;
}

// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[])
{
    int i, j, k = 0, len;
    char arr[MAX_ROWS][MAX_COLS];
    len = strlen(message);
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(k <= len - 1) {
                arr[i][j] = message[k];
                k++;
            } else {
                arr[i][j] = '@';
            }
        }
    }
    if(k != len)
        return 0;
    k = 0;
    for(i = 0; i < cols; i++) {
        for(j = 0; j < rows; j++) {
            result[k] = arr[j][i];
            k++;
        }
    }
    result[k] = '\0';
    return 1;
}

// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[])
{
    int i, j, k, len;
    char arr[MAX_ROWS][MAX_COLS];
    len = strlen(message);
    for(j = 0; j < cols; j++) {
        for(i = 0; i < rows; i++) {
            if(k < len) {
                arr[i][j] = message[k];
                k++;
            } else
                return 0;
        }
    }
    if(k < len)
        return 0;
    k = 0;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(arr[i][j] == '@')
                continue;
            result[k] = arr[i][j];
            k++;
        }
    }
    result[k] = '\0';
    return 1;
}