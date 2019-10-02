#include "manager.h"
#include "module.h"
#include <stdio.h>

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
