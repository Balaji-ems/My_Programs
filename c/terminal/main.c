#include <stdio.h>
#include "global.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char ch[100];

	if (getch() == '\033') { // if the first value is esc
		getch(); // skip the [
    		switch(getch()) { // the real value
        	case 'A':
			printf("Up arrow\n");
            	break;
		case 'B':
            		printf("Down arrow\n");
            	break;
        	case 'C':
            		printf("Right arrow\n");
            	break;
        	case 'D':
			printf("Left arrow\n");
		break;
		}
	}
}
