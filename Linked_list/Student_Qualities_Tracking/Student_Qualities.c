// SPDX-License-Identifier: GPL-3.0

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

enum Qualities {
	STUDIES = 0,
	DISCIPLINE,
	SPORTS,
	ATTENDANCE,
	RAGGING,
	COMMUNICATION,
	RESPECT_OTHERS,
	MAX
};

char *Quality[] = {"Studies", "Disipline", "Sport", "Attendance",
		   "Ragging", "Communication", "Respect_others"};

#define check_bit(value, posistion) ((value) & 1 << (posistion))
#define set_bit(value, posistion)   (value = value | (1 << posistion))
#define clear_bit(value, posistion) (value = value & (~(1 << posistion)))

/*
 * structure to store the name , rollno , qualities of a student
 */

struct node {
	char   name[20];
	int    quality;
	int    rollno;
	struct node *next;
} *head = NULL;

/*
 * user choice of operation
 */

int main(void)
{
	int choice;

	printf("\t\t Student Quality Tracking\n");
	while (1) {
		printf("Choose an option from the list given below\n");
		printf("1.Insert\n2.Display\n3.Delete\n4.Update\n5.Exit\n");

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			printf("Enter the roll number to delete : ");
			scanf("%d", &choice);
			delete(choice);
			break;
		case 4:
			update();
			break;
		case 5:
			if (head != NULL)
				free(head);
			exit(0);
		default:
			printf("Enter a valid choice\n");
		}
		printf("\n");
	}
}

/*
 * function to insert details of the student
 */

void insert(void)
{
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	struct node *temp1 =  head;
	int    num = -1, count = 0;

	printf("\nEnter the Name of the student        : ");
	scanf("%s", temp->name);
A:
	printf("\nEnter the Roll Number of the student : ");
	scanf("%d", &temp->rollno);

	num = searchRollnumber(temp->rollno);

	if (num == 1)
		goto A;

	temp->quality = 0;
	temp->next = NULL;

	if (head == NULL)
		head = temp;
	else {
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

/*
 * display the details of the students
 */

void display(void)
{
	int i, rollno_to_display;
	struct node *temp1 = head;

	if (head == NULL) {
		printf("List is empty!!");
		return;
	}

	printf("Enter the roll number to %s the details : ", __func__);
	scanf("%d", &rollno_to_display);
	printf("\n");

	while (temp1 != NULL) {
		if (temp1->rollno == rollno_to_display)
			break;
		temp1 = temp1->next;
	}

	if (temp1 == NULL) {
		printf("\nEnter a valid roll number to %s\n", __func__);
		temp1 = head;
		printf("\nAvailable student details are :\n\n");
		printf("Name                 : Roll Number\n");
		while (temp1 != NULL) {
			printf("%-20s : %d\n", temp1->name, temp1->rollno);
			temp1 = temp1->next;
		}
		printf("\n");
		return;
	}

	printf("Name        : %s", temp1->name);
	printf("\n");
	printf("Roll number : %d\n\n", temp1->rollno);
	printf("Qualities            : Blackmark\n");

	for (i = STUDIES ; i < MAX ; i++) {
		printf("%-20s : ", Quality[i]);

		if (check_bit(temp1->quality, i))
			printf("Yes");
		else
			printf("No");

		printf("\n");
	}
}

/*
 * Update the details of the student
 */

void update(void)
{
	int rollno_to_update, bit, i;
	struct node *temp = head;

	if (head == NULL) {
		printf("List is empty !!");
		return;
	}

	printf("Enter the roll number of the student to %s the details : ",
		__func__);
	scanf("%d", &rollno_to_update);
	printf("\n");

	while (temp != NULL) {
		if (temp->rollno == rollno_to_update)
			break;
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Enter a valid roll number to %s", __func__);
		temp = head;
		printf("\nAvailable student details are :\n");
		printf("Name                 : Roll Number\n");
		while (temp != NULL) {
			printf("%-20s : %d\n", temp->name, temp->rollno);
			temp = temp->next;
		}
		return;
	}

	printf("Name of the student : %s\n", temp->name);
	printf("If any black mark enter 1 or enter 0\n");

	for (i = STUDIES ; i < MAX ; i++) {
		printf("Enter the input for %-15s : ", Quality[i]);
		scanf("%d", &bit);
		if (bit == 1)
			temp->quality = set_bit(temp->quality, i);
		else
			temp->quality = clear_bit(temp->quality, i);
	}
}

/*
 * Function to delete a student's data by using
 * the roll number of the student
 */

void delete(int key)
{
	struct node *temp = head;
	struct node *temp1;

	printf("\n");

	if (head == NULL) {
		printf("The list is empty !!\n");
		return;
	}

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
