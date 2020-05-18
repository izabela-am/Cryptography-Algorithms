#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    // TAKE USER INPUT FOR TXT AND KEY VALUE
    char userInput[] = "";
    int i, key = 0;
    printf("Enter text you want to encode: ");
    scanf(userInput);
    printf("Enter value of your secret key: ");
    scanf(key);
    
    int inputLength = strlen(userInput);
    char *cipherText = malloc(sizeof(char) * (inputLength + 1));

    // ENCODE
    for(i = 0; i < inputLength; i++) {
        if(isalpha(userInput[i])) {
            cipherText[i] = (toupper(userInput[i]) - 'A' + key) % 26 + 'A';
        } else {
            cipherText[i] = userInput[i];
        }
    }

    cipherText[i] = 0;
    char *userInput2 = malloc(sizeof(char) * (inputLength + 1));

    // DECODE
    for(i = 0; i < inputLength; i++) {
        if(isalpha(userInput[i])) {
            userInput2[i] = (toupper(cipherText[i]) - 'A' + 26 - key) % 26 + 'A';
        } else {
            userInput2[i] = cipherText[i];
        }
    }

    userInput2[i] = 0;

    printf("%s\n%s\n%s\n", userInput, cipherText, userInput2);
    return 0;
}