#ifndef STACK_H
#define STACK_H

typedef struct stack *Stack;

/**
 * Creates a new, empty Stack
 */
Stack StackNew(void);

/**
 * Frees memory allocated for a Stack
 */
void StackFree(Stack s);

/**
 * Adds an item to the top of a Stack
 */
void StackPush(Stack s, int item);

/**
 * Removes an item from the top of a Stack
 * Assumes that the Stack is not empty
 */
int StackPop(Stack s);

/**
 * Gets the number of items in a Stack
 */
int StackSize(Stack s);

/**
 * Gets the item at the top of a Stack without removing it
 * Assumes that the Stack is not empty
 */
int StackPeek(Stack s);

#endif