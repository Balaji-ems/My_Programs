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
		printf("1.Create Module\n2.Subscribe Event\n3.Create Event\n"
			"4.Publish\n5.Display Modules\n6.Display Events\n"
				"7.Exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1: 
			printf("Enter the no of modules to create : ");
			scanf("%d", &size);
			for ( ; index < size; index++) {
				printf("Enter the Module Name :");
				scanf("%s", name);
				create(name, callback);
			}
			index = 0;
			i = 1;
			break;

		case 2:
			if(i == 0) {
				printf("Insert data first\n");
				break;
			}
			Display();
			printf("Enter the name of the module : ");
			scanf("%s", name);
			printf("Enter the subscribtion details : ");
			scanf("%d", &sub_data);
			
			subscribe(name, sub_data);
			
			break;

		case 3:
			printf("Enter number of events to create : ");
			scanf("%d", &size);
			
			for (index = 0; index < size; index++) {
				printf("Enter the Event Name : ");
				scanf("%s", name);
				eventCreate(name);
			}
			index = 0;
			break;

		case 4:
			if(i == 0) {
				printf("Insert data first\n");
				break;
			}
			eventDisplay();

			printf("Enter the event number to publish: ");
			scanf("%d", &choice);
			
			publish(choice);
			
			break;

		case 5:
			Display();
			break;

		case 6:
			eventDisplay();
			break;

		case 7:
			free_mem();
			exit(0);

		default:
			printf("Enter a valid option\n");		
		}
		printf("\n");
	}
}
