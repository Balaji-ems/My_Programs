/*
 * Structure for a doubly linked list
 * Which contains a data and two pointers,
 * one points to the previous node and another
 * points to the next node
 */

struct node {
	struct node *prev;
	int data;
	struct node *next;
} *head = NULL;

void insertatEnd(void);
void delete(struct node *);
void display(void);
