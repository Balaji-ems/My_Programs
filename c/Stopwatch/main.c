#include "core.h"

int main(void)
{
	int hour = 0, minutes = 0, sec = 0;
	time_t now;
	struct tm *timeinfo;
	char a;
	struct lap_time *ptr;

	time(&now);
	timeinfo = localtime(&now);

	hour = timeinfo->tm_hour;
	minutes = timeinfo->tm_min;
	sec = timeinfo->tm_sec;
start:
	for(hour; hour < 24; hour++) {
		for(minutes; minutes < 60; minutes++) {
			for(sec; sec < 60; sec++) {
				printf("\b\b\b\b\b\b\b\b\b%02d:%02d:%02d", hour, minutes, sec);
				fflush(stdout);
				if (scanf("%c", &a) == 1) {
					printf("\nSuccess\n");
					
					ptr = (struct lap_time *)malloc(sizeof(struct lap_time));
				}
				sleep(1);
			}
			sec = 0;
		}
		minutes = 0;
	}
	if (hour == 24)
		hour = 0;
	goto start;
}
