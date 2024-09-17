////////////////////////////////////////////////////////////////////////////////
// Program: palindrome.c                                                      //
// Description: Checks if a given string (first command line argument) is a   //
//              palindrome.                                                   //
// By: John Smith                                                             //
// Date: 29/08/2024                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

// Prototypes
void isPalindrome(char *string);

int main(int argc, char **argv) {
    // Check whether the first command line argument is a palindrome.
    // Assume we have been provided an argument.
    isPalindrome(argv[1]);

    return 0;
}

///////////////////////////////////// TODO /////////////////////////////////////

/**
 * Checks if a given string is a palindrome.
 *
 * @param {string} string - The string to check for palindrome properties.
 * @returns {boolean} True if the string is a palindrome, otherwise false.
 *
 * @example
 * // Check if the string 'radar' is a palindrome:
 * const result = isPalindrome('radar');
 * console.log(result); // Outputs: true
 *
 * @example
 * // Check if the string 'hello' is a palindrome:
 * const result = isPalindrome('hello');
 * console.log(result); // Outputs: false
 */
void isPalindrome(char *string) {
    // Determine starting and ending index for string (halfway through)
    int length = strlen(string);
    int stopIndex = 0;
    if (length % 2 == 0) {
        stopIndex = length / 2;
    } else {
        stopIndex = ((length - 1) / 2) + 1; 
    }
    
    // Check that every i'th letter from the left is equal to the i'th letter
    // to the right.
    int index = 0;
    while (index != stopIndex) {
        if (string[index] != string[length - 1 - index]) {
            // If the letter's don't match, we do not have a palindrome.
            printf("no\n");
            return;
        }
        index++;
    }

    // We have a palindrome.
    printf("yes\n");
    return;
}

