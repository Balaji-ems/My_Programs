#include <stdio.h>
#include <stdarg.h>
#include "print.h"

int debug_level = -1;

void debug_print(int debug, const char *string, ...)
{
	va_list format;

	va_start(format, string);
	if (debug > debug_level ) {
		vprintf(string, format);
		printf("\n");
	}
	va_end(format);
}
