#include "manager.h"
#include "module.h"

void create(char *name, void(*ptr)(char *))
{
    createnode(name, ptr);
}

void subscribe(char *name, int data)
{
    subscribeEvent(name, data);
}

void publish(int num)
{
    publishEvent(num);
}

void free_mem(void)
{
	free_memory();
}

void Display(void)
{
	display();
}

void eventCreate(char *event_name)
{
	createEvent(event_name);
}

void eventDisplay(void)
{
	displayEvent();
}

int moduleSearch(char *name)
{
	return searchModule(name);
}

int eventSearch(char *name)
{
	return searchEvent(name);
}
