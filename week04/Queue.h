// Interface to the Queue ADT

// !!! DO NOT MODIFY THIS FILE !!!

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>

typedef struct queue *Queue;

/**
 * Creates a new empty queue
 * Time complexity: O(1)
 */
Queue QueueNew(void);

/**
 * Frees all memory allocated to the queue
 * Time complexity: O(n)
 */
void QueueFree(Queue q);

/**
 * Adds an int to the end of the queue
 * Time complexity: O(1)
 */
void QueueEnqueue(Queue q, int it);

/**
 * Removes an int from the front of the queue and returns it
 * Assumes that the queue is not empty
 * Time complexity: O(1)
 */
int QueueDequeue(Queue q);

/**
 * Gets the int at the front of the queue without removing it
 * Assumes that the queue is not empty
 * Time complexity: O(1)
 */
int QueueFront(Queue q);

/**
 * Prints out the contents of the queue (front to back)
 * Time complexity: O(n)
 */
void QueuePrint(Queue q);

/**
 * Gets the size of the given queue
 * Time complexity: O(1)
 */
int QueueSize(Queue q);

/**
 * Returns true if the queue is empty, and false otherwise
 * Time complexity: O(1)
 */
bool QueueIsEmpty(Queue q);

#endif
