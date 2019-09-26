// SPDX-License-Identifier: GPL-3.0

#include <stdio.h>
#include "module.h"
#include "events.h"
#include "global.h"

int main(void)
{
	int search_event, i;

	init();

	printf("Enter an event number to find the interested modules\n");
	for (i = 0; i < MAX; i++)
		printf("%d.%s\n", i+1, events[i]);

	printf("Available modules are from 1 to %d : ", MAX);
	scanf("%d", &search_event);

	if (search_event < 1 || search_event > MAX) {
		printf("Enter a valid event id\n");
		return 0;
	}
	printf("\n");
	display_events(search_event-1, events[search_event-1]);
	printf("\n");

}
