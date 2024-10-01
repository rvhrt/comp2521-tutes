////////////////////////////////////////////////////////////////////////////////
// Program: Queue.c                                                           //
// Description: Driver code to test the implementation of a queue.            //
// By: Ravindu Abeykoon Herath                                                //
// Date: 2/09/2024                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

int main(void) {
    // Create a queue
    Queue q = QueueNew();

    // Enqueue some elements
    QueueEnqueue(q, 2);
    QueueEnqueue(q, 4);
    QueueEnqueue(q, 1);
    QueueEnqueue(q, 5);
    QueueEnqueue(q, 9);
    QueueEnqueue(q, 8);
    QueueEnqueue(q, -1);

    // Print out the queue
    printf("The queue currently contains %d elements:\n", QueueSize(q));
    QueuePrint(q);

    // Dequeue some elements
    printf("Successfully dequeued %d\n", QueueDequeue(q));
    printf("Successfully dequeued %d\n", QueueDequeue(q));
    printf("Successfully dequeued %d\n", QueueDequeue(q));
    printf("Successfully dequeued %d\n", QueueDequeue(q));

    // Print out the queue again
    printf("The queue currently contains %d elements:\n", QueueSize(q));
    QueuePrint(q);

    // Clean up
    QueueFree(q);

    return 0;
}