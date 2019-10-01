#include<stdio.h>
#include<stdlib.h>
#include "module.h"


int main()
{
    int choice,size,i=0;
    while(1) {
	printf("Select an option given below\n");
	printf("1.Create\n2.Subscribe\n3.Publish\n4.Exit\n");
	scanf("%d",&choice);
	switch(choice) {
	case 1: 
		printf("Enter the no of modules to create : ");
		scanf("%d",&size);
		printf("\n");
		i=1;
		create(size);
		break;

	case 2:
		if(i == 0) {
		    printf("Insert data first\n");
		    break;
		}
		subscribe();
		break;
	
	case 3:
		if(i == 0) {
		    printf("Insert data first\n");
		    break;
		}
		printf("Enter the event number to bublish(1-7) : ");
		scanf("%d",&choice);
	//	publish(choice);
		break;
	case 4:
		exit(0);
	default:
		printf("Enter a valid option\n");		
	}
	printf("\n");
    }
}
