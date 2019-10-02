#include <stdio.h>
#include <stdlib.h>
#include "module.h"

void callback(char *modulename)
{
	printf("Module name %s subscribed to the event\n", modulename);
}

int main(void)
{
	int choice, size, i = 0, index = 0, sub_data;
	char name[10];

	while(1) {
		printf("Select an option given below\n");
		printf("1.Create\n2.Subscribe\n3.Publish\n4.Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1: 
			printf("Enter the no of modules to create : ");
			scanf("%d", &size);
			for ( ; index < size; index++) {
				printf("Enter the event name :");
				scanf("%s", name);
				create(name, callback);
			}
			i = 1;
			break;
		case 2:
			if(i == 0) {
				printf("Insert data first\n");
				break;
			}

			printf("Enter the name of the module : ");
			scanf("%s", name);
			printf("Enter the subscribtion details : ");
			scanf("%d", &sub_data);
			subscribe(name, sub_data);
			break;
		case 3:
			if(i == 0) {
				printf("Insert data first\n");
				break;
			}
			printf("Enter the event number to bublish(1-7) : ");
			scanf("%d", &choice);
			publish(choice);
			break;
		case 4:
			free_mem();
			exit(0);
		case 5:
			Display();
			break;

		default:
			printf("Enter a valid option\n");		
		}
		printf("\n");
	}
}
