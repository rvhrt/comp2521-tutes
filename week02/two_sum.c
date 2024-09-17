////////////////////////////////////////////////////////////////////////////////
// Program: two_sum.c                                                         //
// Description: Checks if there are two numbers in the array (first command   //
//              line argument) that sum up to a given value (second command   //
//              line argument).                                               //
// By: Ravindu Abeykoon Herath                                                //
// Date: 29/08/2024                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Prototypes
bool hasTwoSum(int a[], int n, int v);

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target_sum> <list_of_numbers>\n", argv[0]);
        return 1;
    }

    // Convert the first argument to an integer (the sum we want)
    int targetSum = atoi(argv[1]); 

    // Parse the remaining command-line arguments as integers
    // Lazy assume we can have a max of 100 numbers.
    int numbers[100]; 
    int count = 0;
    for (int i = 2; i < argc; i++) {
        if (count >= 100) {
            fprintf(stderr, "Too many numbers provided. Maximum is 100.\n");
            return 1;
        }
        numbers[count++] = atoi(argv[i]);
    }

    // Check if there are two numbers that sum to the target value
    if (hasTwoSum(numbers, count, targetSum)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

///////////////////////////////////// TODO /////////////////////////////////////

/**
 * Checks if there are two numbers in the array that sum up to a given value.
 *
 * @param {number[]} a - The array of integers to search within.
 * @param {number} n - The number of elements in the array.
 * @param {number} v - The target sum to check for.
 * @returns {boolean} True if there are two numbers in the array that add up to 
 * the target sum, otherwise false.
 *
 */
bool hasTwoSum(int a[], int n, int v) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == v) {
                return true;
            }
        }
    }
    return false;
}