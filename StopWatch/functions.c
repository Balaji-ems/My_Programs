#include "header.h"
#include "functions.h"
// Get keyboard input and perform actions for
// the given input

int action_for_key(void)
{
	struct termios old_time, new_time;
	int char_input, ret;

	tcgetattr(STDIN_FILENO, &old_time);
	new_time = old_time;
	new_time.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_time);
	ret = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, ret | O_NONBLOCK);

	char_input = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_time);
	fcntl(STDIN_FILENO, F_SETFL, ret);

	if (char_input != EOF) {
		ungetc(char_input, stdin);
		return 1;
	}

	return 0;
}

// Display stopwatch on screen

void time_print(int *hour, int *min, int *sec)
{
	// clear screen escape sequence
	// printf("\033[2J\033[1;1H");
	if (sec > 0 || min > 0)
		printf("\r\r\r\r\r");
	// Display the time
	printf("%02d:%02d:%02d", *hour, *min, *sec);
}

// Pause the stopwatch

void *wait(void *arg)
{
	char c;

	while(1) {
		if (action_for_key()) {
			c = getchar();
			if (c == 'S' || c =='s') {
				break;
			} else if (c == 'r' || c == 'R') {
				signal = 1;
				break;
			} else if (c == 'e' || c == 'E') {
				exit(0);
			}
		}
	}
}
