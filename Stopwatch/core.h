#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX 20

struct lap_time {
	char time[10];
	struct lap_time *next_node;
};

#endif
