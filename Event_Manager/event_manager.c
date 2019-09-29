#include "event.h"
#include "events.h"
#include "global.h"

#define check_bit(value, posistion) ((value) & 1 << (posistion))

struct module_data {
	int interest;
	void (*call_back_pointer)(char *event_name);
} module_data[MAX];

int array_pos;


void subscribe(int data, void(*pointer)(char *))
{
	module_data[array_pos].interest = data;
	module_data[array_pos].call_back_pointer = pointer;
	array_pos += 1;
}

void display_events(int event_number, char *event_name)
{
	int j;

	for (j = 0; j < array_pos; j++) {
		if (check_bit(module_data[j].interest, event_number))
			(*module_data[j].call_back_pointer)(event_name);
	}
}
