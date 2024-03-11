#include <stdio.h>
#include <string.h>


char* getFirstWord(char *input, char *remainder) {

    size_t spaceIndex = strcspn(input, " ");


    strncpy(remainder, input, spaceIndex);
    remainder[spaceIndex] = '\0';

    return input + spaceIndex + 1;
}

int main() {
    char inputString[100];
    char firstWord[50];
    char remainingString[50];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    char* remainder = getFirstWord(inputString, firstWord);

    printf("First Word: %s\n", firstWord);
    printf("Remaining String: %s\n", remainder);

    return 0;
}
