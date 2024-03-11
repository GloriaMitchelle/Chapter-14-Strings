#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100

// Function to remove leading and trailing blanks from a string
void trimString(char *str) {
    // Remove leading blanks
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Remove trailing blanks
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *(end + 1) = '\0';
}

// Function to extract and return the last name from a full name
const char *extractLastName(const char *fullName) {
    const char *lastName = strrchr(fullName, ' '); // Find the last space in the string

    if (lastName != NULL) {
        lastName++; // Move to the character after the last space
    } else {
        lastName = fullName; // If no space is found, consider the whole string as the last name
    }

    return lastName;
}

int main() {
    char inputName[MAX_NAME_LENGTH];

    // Read a string containing a first name followed by a blank and then a last name
    printf("Enter a full name (first name + last name): ");
    fgets(inputName, sizeof(inputName), stdin);

    // Remove leading and trailing blanks
    trimString(inputName);

    // Extract and print the last name
    const char *lastName = extractLastName(inputName);
    printf("Last Name: %s\n", lastName);

    return 0;
}
