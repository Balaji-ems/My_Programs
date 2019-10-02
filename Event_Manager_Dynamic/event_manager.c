#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

#define check_bit(value,posistion) ((value) & 1 << (posistion))
#define set_bit(value,posistion)  (value = value | (1 << posistion))
#define clear_bit(value,posistion) (value = value & (~(1 << posistion)))

enum state {
	INITIALIZED = 0,
	SUBSCRIBED
};

struct node {
	int interest;
	struct node *next;
	char module_name[10];
	void(*ptr)(char *);
	int state;

} *head = NULL;

struct event {
	char *event_name;
	struct event *next;
} *event_head;

void createnode(char *name, void(*ptr)(char *)) 
{
	int temp_interest;
	struct node* temp1;

	struct node* temp = malloc(sizeof(struct node));
	
	strcpy(temp->module_name,name);
	temp->interest = 15;
	temp->ptr = ptr;
	temp->next = NULL;
	temp->state = INITIALIZED;

	if(head == NULL) {
		head = temp;
		return;
	}

	temp1 = head;

	while (temp1->next != NULL)
		temp1 = temp1->next;
	
	temp1->next = temp;
}

void subscribeEvent(char *name, int data)
{
	struct node* temp = head;
	printf("%s\n", name);
	while (temp != NULL) {
		if (strcmp(name, temp->module_name) == 0) {
			temp->interest = data;
			temp->state = SUBSCRIBED;
			return;
		}
		temp = temp->next;
	}
}


void publishEvent(int event)
{
	struct node* temp = head;
	while(temp != NULL) {
		if(check_bit(temp->interest,event-1)) {
			(temp->ptr)(temp->module_name);
		}
		temp = temp->next;
	}
}

void free_memory(void)
{
	free(head);
}

void display(void)
{
	struct node *temp = head;

	while (temp != NULL) {
		printf("%s\n", temp->module_name);
		temp = temp->next;
	}
}

void createEvent(char *event_name)
{
}	
