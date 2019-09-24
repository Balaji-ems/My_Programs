// SPDX-License-Identifier: GPL-3.0

#include "event.h"
#include <stdio.h>
#include "module.h"

void print_one(char *event)
{
	printf("Module one is interested in %s\n", event);
}
void module_one(void)
{
	int interest_one = 90;

	subscribe(interest_one, print_one);
}

void print_two(char *event)
{
	printf("Module two is interested in %s\n", event);
}

void module_two(void)
{
	int interest_two = 105;

	subscribe(interest_two, print_two);
}

void print_three(char *event)
{
	printf("Module three is interested in %s\n", event);
}

void module_three(void)
{
	int interest_three = 44;

	subscribe(interest_three, print_three);
}

void print_four(char *event)
{
	printf("Module four is interested in %s\n", event);
}

void module_four(void)
{
	int interest_four = 37;

	subscribe(interest_four, print_four);
}

void print_five(char *event)
{
	printf("Module five is interested in %s\n", event);
}

void module_five(void)
{
	int interest_five = 83;

	subscribe(interest_five, print_five);
}

void init(void)
{
	module_one();
	module_two();
	module_three();
	module_four();
	module_five();
}
