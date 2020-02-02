#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#include "print.h"

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

/* Signal Handler for SIGINT */
void sigintHandler(int sig_num)
{
	/* Reset handler to catch SIGINT next time.
	 * Refer http://en.cppreference.com/w/c/program/signal
	 */
	signal(SIGINT, sigintHandler);
	debug_print(EXCESS, "Cannot be terminated using Ctrl+C\n");
	fflush(stdout);
}
/* Refer http://en.cppreference.com/w/c/program/signal */
