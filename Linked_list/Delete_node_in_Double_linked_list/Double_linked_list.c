// SPDX-License-Identifier: GPL-2.0

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/*
 * Main function accepts user input and performs
 * action for the input
 */

int main(void)
{
	int choice;
	struct node *todelete;

	while (1) {
		printf("Select an option given below\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case(1):
			insertatEnd();
			break;
		case(2):
			if (head == NULL) {
				printf("List is empty !!");
				break;
			}
			printf("Enter an element to delete : ");
			scanf("%d", &choice);
			todelete = head;
			while (todelete != NULL) {
				if (todelete->data == choice) {
					delete(todelete);
					break;
				}
				todelete = todelete->next;
			}
			if (todelete == NULL)
				printf("Enter a valid element to delete");
			break;
		case(3):
			display();
			break;
		case(4):
			if (head != NULL)
				free(head);
			exit(0);
		default:
			printf("Enter a valid option to perform an action");
		}
		printf("\n");
	}
}

/*
 * Function to insert the node at the end of
 * the list
 */

void insertatEnd(void)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp1 = head;

	printf("Enter the data to insert into the list : ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
		temp->prev = NULL;
		return;
	}
	while (temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = temp;
	temp->prev = temp1;
}

/*
 * Function to delete the node in
 * the given address
 */

void delete(struct node *temp)
{
	if (head == temp) {
		if (head->next == NULL) {
			free(head);
			head = NULL;
			printf("Deleted Successfully");
			return;
		}
		head = temp->next;
		head->prev = NULL;
		free(temp);
		printf("Deleted Successfully\n");
		return;
	}
	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		free(temp);
		printf("Deleted Successfully\n");
		return;
	}
	temp->prev->next = NULL;
	free(temp);
	printf("Deleted Successfully\n");
}

/*
 * Function to display the data in the list
 * from begining to end
 */

void display(void)
{
	struct node *temp = head;

	if (temp == NULL) {
		printf("List is empty !!\n");
		return;
	}
	printf("\nThe elements in the linked list are\n");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
