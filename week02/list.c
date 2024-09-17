////////////////////////////////////////////////////////////////////////////////
// Program: list.c                                                            //
// Description: Used to create linked lists, and modify them as needed.       //
// By: Ravindu Abeykoon Herath                                                //
// Date: 23/08/2024                                                           //
////////////////////////////////////////////////////////////////////////////////

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of a linked list node.
struct node {
    int value;
    struct node *next;
};

// Function prototypes
struct node *listCreate();
struct node *listAdd(struct node *list, int val);
struct node *createNode(int val);
void listPrint(struct node *list);
void listFree(struct node *list);
int listLength(struct node *l);
int listCountOdds(struct node *l);
bool listIsSorted(struct node *l);
struct node *listDelete(struct node *l, int value);

/**
 * Main function
 */
int main() {
    // Create a new list
    struct node *list = listCreate();

    // Add some dummy values
    list = listAdd(list, 1);
    list = listAdd(list, 2);
    list = listAdd(list, 3);
    list = listAdd(list, 4);
    list = listAdd(list, 5);

    // Print out the list
    listPrint(list);

    // Print out the length of the list
    printf("The list has %d nodes.\n", listLength(list));

    // Print out the number of odd numbers in the list
    printf("The list has %d odd numbered nodes.\n", listCountOdds(list));

    // Check whether the list is sorted
    if (listIsSorted(list)) {
        printf("The list is sorted.\n");
    } else {
        printf("The list is not sorted.\n");
    }
    
    // Delete a value from the list, and print it out
    int deleteVal = 6;
    list = listDelete(list, deleteVal);
    printf("After deleting %d, the list looks like:\n", deleteVal);
    listPrint(list);

    return 0;
}

/**
 * Creates a new list.
 * 
 * @returns An empty list.
 */
struct node *listCreate() {
    return NULL;
}

/**
 * Adds a node (with the given value) to a linked list.
 * 
 * @param list - The linked list
 * @param val - The value to add
 * 
 * @returns The modified list.
 */
struct node *listAdd(struct node *list, int val) {
    struct node *newNode = createNode(val);
    
    // If list is empty.
    if (list == NULL) {
        return newNode;
    }

    // Iterate through the list, handling cases.
    struct node *curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    // Add onto list, and return.
    curr->next = newNode;
    return list;
}

/**
 * Helper function to create a single node of a linked list.
 * 
 * @param val - The value which the node takes on.
 * 
 * @returns The modified list.
 */
struct node *createNode(int val) {
    struct node *new = malloc(sizeof(struct node));
    new->value = val;
    new->next = NULL;
    return new;
}

/**
 * Prints out the contents of a list.
 * 
 * @param list - The list to be printed
 * 
 * @returns Nothing.
 */
void listPrint(struct node *list) {
    struct node *curr = list;

    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }

    printf("X\n");
}

/**
 * Frees a linked-list.
 * 
 * @param list - The list to free.
 */
void listFree(struct node *list) {
    struct node *curr = list;
    struct node *freeTemp = curr;
    while (curr != NULL) {
        curr = curr->next;
        free(freeTemp);
        freeTemp = curr;
    }
}

///////////////////////////////////// TODO /////////////////////////////////////

/**
 * Computes the length of a linked list.
 *
 * @param l - A pointer to the head of the linked list.
 * @returns The length of the linked list as an integer.
 */
int listLength(struct node *l) {
    // Base case
    if (l == NULL) {
        return 0;
    }

    // Return 1 for the current node
    return 1 + listLength(l->next);
}

/**
 * Counts the number of odd numbers in a linked list.
 *
 * @param l - A pointer to the head of the linked list.
 * @returns The number of odd values in the list.
 */
int listCountOdds(struct node *l) {
    // Base case
    if (l == NULL) {
        return 0;
    }

    // Set a default value.
    int nodeVal = 0;
    
    // If the current value is odd, add 1
    if (l->value % 2 == 1) {
        nodeVal = 1;
    }

    // We add the current node's 'value' to the rest of the list.
    return nodeVal + listCountOdds(l->next);
}

/**
 * Checks whether a linked list is sorted in ascending order.
 *
 * @param l - A pointer to the head of the linked list.
 * @returns true if the list is sorted, false otherwise.
 */
bool listIsSorted(struct node *l) {
    // Base case
    if (l->next == NULL) {
        return true;
    }

    // Set a default value.
    int sorted = true;
    
    // Check whether adjacent nodes are ascending.
    int currVal = l->value;
    int nextVal = l->next->value;
    if (currVal > nextVal) {
        sorted = false;
    }

    // Add the result 'boolean-wise' to the rest of the list.
    return sorted && listIsSorted(l->next);
}

/**
 * Deletes the first instance of a value from a linked list, if it exists.
 *
 * @param l - A pointer to the head of the linked list.
 * @param value - The value to be deleted from the list.
 * @returns A pointer to the head of the updated linked list.
 */
struct node *listDelete(struct node *l, int value) {
    // Base case
    if (l == NULL) {
        return l;
    }

    // If we have found the value, return early, deleting the node
    struct node *currNext = l->next;
    if (l->value == value) {
        free(l);
        return currNext;
    }

    // Attach the results of the sublist deletion to the current node
    l->next = listDelete(l->next, value);
    return l; 
}