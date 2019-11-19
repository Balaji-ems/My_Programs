#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Qualities {
	STUDIES = 0,
	DISCIPLINE,
	SPORTS,
	ATTENDANCE,
	RAGGING,
	COMMUNICATION,
	RESPECT_OTHERS,
	MAX
};

static char *Quality[] = {"Studies", "Disipline", "Sport", "Attendance",
		   "Ragging", "Communication", "Respect_others"};

#define check_bit(value, posistion) ((value) & 1 << (posistion))
#define set_bit(value, posistion)   (value = value | (1 << posistion))
#define clear_bit(value, posistion) (value = value & (~(1 << posistion)))

void delete(int);
void insert(void);
void display(void);
void update(void);
int  searchRollnumber(int);
void Displayall(void);
void sort(void);

#endif
