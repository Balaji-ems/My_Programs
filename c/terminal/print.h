#ifndef PRINT_H
#define PRINT_H

enum {
	EXCESS,
	MIN,
	MAX
};

extern int debug_level;

void debug_print(int debug, const char *string, ...);

#endif
