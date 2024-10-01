#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

struct stack {
	struct node *head;
	int size;
};

struct node {
	int item;
	struct node *next;
};

Stack StackNew(void) {
	Stack s = malloc(sizeof(struct stack));
	if (s == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	s->head = NULL;
	s->size = 0;
	return s;
}

void StackFree(Stack s) {
	struct node *curr = s->head;
	while (curr != NULL) {
		struct node *temp = curr;
		curr = curr->next;
		free(temp);
	}
	free(s);
}

void StackPush(Stack s, int item) {
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL) {
		fprintf(stderr, "error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	new->item = item;
	new->next = s->head;

	s->head = new;
	s->size++;
}

int StackPop(Stack s) {
	if (s->size == 0) {
		fprintf(stderr, "error: stack is empty!\n");
		return 0;
	}

	struct node *newHead = s->head->next;
	int it = s->head->item;

	free(s->head);
	s->head = newHead;
	s->size--;

	return it;
}

int StackSize(Stack s) {
	return s->size;
}

int StackPeek(Stack s) {
	if (s->size == 0) {
		fprintf(stderr, "error: stack is empty!\n");
		return 0;
	}

	return s->head->item;
}
