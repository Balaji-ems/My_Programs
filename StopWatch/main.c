#include "header.h"
#include "functions.h"

int main(void)
{
	int hour, min, sec, temp;
	char c;
	pthread_t t1;

	printf("Press the following to select an operation\n");
	printf("S -> Start the stopwatch\nP -> Pause the stopwatch\n"
	       "R -> Reset the stopwatch\nE -> Exit\n");
reset:
	hour = min = sec = 0;

	time_print(&hour, &min, &sec);
	
	while (1) {
		if (action_for_key()) {
			c = getchar();

			if (c != 's')
				continue;
			for (; hour < 60; hour ++){
				for (; min < 60; min++) {
					for (; sec < 60; sec++) {
						sleep(1);
start:
						time_print(&hour, &min, &sec);
						if (action_for_key()) {
							c = getchar();
							if (c == 'r' || c == 'R') {
								goto reset;
							} else if (c == 'e' || c == 'E') {
								printf("\n");
								exit(0);
							} else if (c == 's' || c == 'S') {
								goto start;
							} else if (c == 'p' || c == 'P') {
								printf("\b");
								pthread_create(&t1, NULL, &wait, NULL);
								pthread_join(t1, NULL);

								if (signal == 1)
									goto reset;
							}
						}
					}
				}
			}
		}
	}
}
