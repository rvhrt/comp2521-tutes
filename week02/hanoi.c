////////////////////////////////////////////////////////////////////////////////
// Program: hanoi.c                                                           //
// Description: Simple text based visualiser to the Tower of Hanoi problem    //
// By: Ravindu Abeykoon Herath                                                //
// Date: 29/08/2024                                                           //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Prototypes
void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod);

int main(void) {
    // Get the number of disks.
    printf("How many disks? ");
    int numDisks = 0;
    scanf("%d", &numDisks);

    // Start solving.
    solveHanoi(numDisks, "A", "C", "B");

    // All done!
    return 0;
}

///////////////////////////////////// TODO /////////////////////////////////////

/**
 * Solves the Tower of Hanoi puzzle using recursion.
 *
 * @param {number} numDisks - The number of disks in the puzzle.
 * @param {string} fromRod - The rod from which disks are moved.
 * @param {string} toRod - The rod to which disks are moved.
 * @param {string} otherRod - The rod used as an intermediary during the move.
 *
 * @example
 * // To move 3 disks from rod A to rod C using rod B:
 * solveHanoi(3, 'A', 'C', 'B');
 */
void solveHanoi(int numDisks, char *fromRod, char *toRod, char *otherRod) {
    // ORIGINAL base case; if we have a single disk, simply move it!
    // if (numDisks == 1) {
    //     printf("Moved %s to %s\n", fromRod, toRod);
    //     return;
    // } 
    // I've left this in here as a reminder that its tricky to get fully correct
    // code on the first try, but there's nothing stopping you from getting
    // a working solution and optimising after :)

    // New base case: If we have 0 disks, return:
    if (numDisks == 0) {
        return;
    }

    solveHanoi(numDisks - 1, fromRod, otherRod, toRod);
    printf("Move disk from Rod %s to Rod %s\n", fromRod, toRod);
    solveHanoi(numDisks - 1, otherRod, toRod, fromRod);
}