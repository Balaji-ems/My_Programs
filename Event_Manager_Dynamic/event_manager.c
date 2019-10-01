#include<stdio.h>
#include<stdlib.h>
#include "head.h"

struct node
{
    int interest;
    struct node* next;
    char module_name;
}*head=NULL;

void createnode(int size)
{
    int temp_interest;
    struct node* temp1;
    char ch;
    for(int i = 0;i < size;i++) {
	struct node* temp = malloc(sizeof(struct node));
	printf("Enter module name : ");
	scanf("%c",&ch);
	printf("%c",ch);
	temp->module_name=ch;
	temp->interest=0;
	temp->next = NULL;

	if(head == NULL) {
	    head = temp;
	    continue;
	}

	temp1 = head;
	while(temp1->next != NULL) {
	    temp1 = temp1->next;
	}
	temp1->next = temp;
    }
}

void subscribeEvent()
{
    struct node* temp = head;
    while(temp != NULL) {
	printf("Enter the subscribtion details of %c\n",temp->module_name);
	scanf("%d",&temp->interest);
	temp = temp->next;
    }
}

/*
void publishEvent(int event,void(*ptr)(char))
{
    struct node* temp = head;
    while(temp != NULL) {
	if(check_bit(temp->interest,event-1)) {
	    (*ptr)(temp->module_name);
	}
	temp = temp->next;
    }
}
*/
