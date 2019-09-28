// SPDX-License-Identifier: GPL-3.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/*
 * create a strucure which stores the roll no and name
 * of a student (Singly Linked List)
 */

struct node {
	char   name[20];
	int    rollno;
	struct node *next;
} *head = NULL;

/*
 * User choice to isert,delete,display,search the details
 */

int main(void)
{
	int ch, total_node = 1;

	printf("\t\tStudent Data\n");

	while (1) {
		printf("\n1.Insert Data\n2.Display Data\n3.Delete Data\n"
			"4.Search by Name\n5.Search by Rollno\n6.Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &ch);
		printf("\n");

		switch (ch) {
		case 1:
			printf("Enter the posistion to insert the data : ");
			scanf("%d", &ch);

			if (ch > total_node) {
				printf("\nPosistion is greater than list size\n");
				printf("Total size of the list is %d", total_node - 1);
				break;
			} else if (ch == 1)
				insert();
			else if (ch == total_node)
				insertatEnd();
			else
				insertatMiddle(ch);
			
			total_node++;	
			break;
		case 2:
			display();
			break;
		case 3:
			if (head == NULL) {
				printf("The list is empty !\n");
				break;
			}
			printf("Enter the roll number of the student to "
				"delete the data : ");
			scanf("%d", &ch);
			delete(ch);
			break;
		case 4:
			searchbyName();
			break;
		case 5:
			searchbyRollno();
			break;
		case 6:
			if (head != NULL)
				free(head);
			exit(0);
		default:
			printf("Select a valid option\n");
		}
		printf("\n");
	}
	return 0;
}

/*
 *  Function to insert a name and roll no of a student
 *  It add the node at first
 */

void insert(void)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	int    check;

	printf("\nEnter the name of the student         : ");
	scanf("%s", temp->name);
A:
	printf("\nEnter the roll number of the student  : ");
	scanf("%d", &temp->rollno);

	check = searchRollnumber(temp->rollno);
	if (check == 1)
		goto A;

	if (head == NULL) {
		temp->next = NULL;
		head = temp;
	} else {
		temp->next = head;
		head = temp;
	}
}

/*
 * Function to add the student data at the last
 */

void insertatEnd(void)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp1 = head;
	int    check;

	printf("\nEnter the name of the student        : ");
	scanf("%s", temp->name);
B:
	printf("\nEnter the roll number of the student        : ");
	scanf("%d", &temp->rollno);
	temp->next = NULL;

	check = searchRollnumber(temp->rollno);
	if (check == 1)
		goto B;

	if (head == NULL)
		head = temp;
	else {
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

/*
 * Function to insert a student data at the middle of the list
 */

void insertatMiddle(int posistion)
{
	int    count = 1, check;
	struct node *temp = head;
	struct node *temp1 = (struct node *)malloc(sizeof(struct node));
	struct node *temp2 = NULL;

	while (temp != NULL) {
		if (count == posistion)
			break;
		count += 1;
		temp2 = temp;
		temp = temp->next;
	}

	printf("\nEnter the name of the student        : ");
	scanf("%s", temp1->name);
C:
	printf("\nEnter the name of the student        : ");
	scanf("%d", &temp1->rollno);

	check = searchRollnumber(temp1->rollno);
	if (check == 1)
		goto C;

	temp2->next = temp1;
	temp1->next = temp;
}

/*
 * Function to display the details of all the students in
 * the data base
 */

void display(void)
{
	struct node *temp1 = head;
	int    snumber = 1;

	if (head == NULL) {
		printf("List is empty!!");
		return;
	}
	printf("S.NO Name                 : Roll Number\n");

	while (temp1 != NULL) {
		printf("%4d %-20s : %d\n", snumber++,
			temp1->name, temp1->rollno);
		temp1 = temp1->next;
	}
}

/*
 * The function will tell wheater the given Rollno is in the list or not
 */

void searchbyRollno(void)
{
	int    flag = 0, searchElement, pos = 0;
	struct node *temp1 = head;

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	printf("\nEnter the roll no to search : ");
	scanf("%d", &searchElement);

	while (temp1 != NULL) {
		pos += 1;

		if (temp1->rollno == searchElement) {
			flag = 1;
			break;
		}
		temp1 = temp1->next;
	}

	if (flag == 1)
		printf("\nRoll no %d found at %d position\n",
			searchElement, pos);
	else
		printf("\nRoll no %d not found in list\n", searchElement);
}

/*
 * The function will tell wheater the given Name is in the list or not
 */

void searchbyName(void)
{
	int    flag = 0, pos = 0;
	char   search[20];
	struct node *temp1 = head;

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	printf("\nEnter the name to search : ");
	scanf("%s", search);

	while (temp1 != NULL) {
		pos += 1;
		if (strcmp(temp1->name, search) == 0) {
			flag = 1;
			break;
		}
		temp1 = temp1->next;
	}
	if (flag == 1)
		printf("\nName %s found at %d position\n", search, pos);
	else
		printf("\nName %s not found in list\n", search);
}


/*
 * Function to delete a student's data using the
 * roll number of the student
 */

void delete(int key)
{
	struct node *temp = head;
	struct node *temp1;

	printf("\n");
	if (temp != NULL && temp->rollno == key) {
		free(temp);
		head = head->next;
		printf("Deleted Successfully\n");
		return;
	}

	while (temp != NULL && temp->rollno != key) {
		temp1 = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Roll number not found in the list\n");
		return;
	}

	temp1->next = temp->next;
	free(temp);
	printf("Deleted Successfully\n");
}

/*
 * Function to search the Roll number of the student
 * in the database. If the roll number is present in the
 * database returns 1 else returns 0.
 */

int searchRollnumber(int Rollnumber)
{
	struct node *temp = head;

	while (temp != NULL) {
		if (temp->rollno == Rollnumber) {
			printf("\nRoll number already exists ! Please enter a "
					"valid Roll number\n");
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}
