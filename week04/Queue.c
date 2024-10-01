////////////////////////////////////////////////////////////////////////////////
// Program: Queue.c                                                           //
// Description: Implementation of a Queue using two stacks.                   //
// By: Ravindu Abeykoon Herath                                                //
// Date: 2/09/2024                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

// Static (this is important) helper function(s)
static void stackInverse(Stack populated, Stack empty);

// Using two stacks to represent a queue.
struct queue {
	Stack s1;
	Stack s2;
};

Queue QueueNew(void) {
    Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueFree(Queue q) {
    StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}

///////////////////////////////////// TODO /////////////////////////////////////

void QueueEnqueue(Queue q, int it) {
    // Rename for clarity
    Stack currentStack = q->s1;

    // Push onto the non-empty stack
    StackPush(currentStack, it);
}

int QueueDequeue(Queue q) {
    // Rename for clarity
    Stack currentStack = q->s1;
    Stack otherStack = q->s2;

    // Perform a stack inverse
    stackInverse(currentStack, otherStack);

    // Pop off the otherStack (which contains the queue in order)
    int frontItem = StackPop(otherStack);

    // Perform another stack inverse (to maintain order)
    stackInverse(otherStack, currentStack);

    // Return the dequeued item
    return frontItem;
}

void stackInverse(Stack populated, Stack empty) {
    // For each element in the populated stack, pop and push onto other stack
    while(StackSize(populated) != 0) {
        StackPush(empty, StackPop(populated));
    }
}

int QueueFront(Queue q) {
    // Rename for clarity
    Stack currentStack = q->s1;
    Stack otherStack = q->s2;

    // Perform a stack inverse  
    stackInverse(currentStack, otherStack);

    // Pop and push the last element (so it is not dequeued)
    int frontItem = StackPop(otherStack);
    StackPush(otherStack, frontItem);

    // Perform another stack inverse (to maintain order)
    stackInverse(otherStack, currentStack);

    return frontItem;
}

void QueuePrint(Queue q) {
    // Rename for clarity
    Stack currentStack = q->s1;
    Stack otherStack = q->s2;

    // Perform a stack inverse  
    stackInverse(currentStack, otherStack);

    // Perform a modified stack inverse, where we print each element
    printf("FRONT ");
    while(StackSize(otherStack) != 0) {
        int currItem = StackPop(otherStack);
        printf("%d ", currItem);
        StackPush(currentStack, currItem);
    }
    printf("BACK\n");
}

int QueueSize(Queue q) {
    return StackSize(q->s1);
}

bool QueueIsEmpty(Queue q) {
    if (StackSize(q->s1) == 0) {
        return true;
    } else {
        return false;
    }
}
