#include <stdio.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 18

static char num_array[] = "0123456789";
static char small_array[] = "abcdefghijklmnopqrstuvwxyz";
static char caps_array[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static char special_array[] = "!@?+#$%&:=";

int main(void)
{
	int random, select;
	char pass[PASSWORD_LENGTH + 1];

	for (int i = 0; i < PASSWORD_LENGTH; i++) {
		random = rand();
		select =  random % 4;
		if (!select)
			pass[i] = num_array[random % sizeof(num_array)];
		else if (select == 1)
			pass[i] = small_array[random % sizeof(small_array)];
		else if (select == 2)
			pass[i] = caps_array[random % sizeof(caps_array)];
		else if (select == 3) {
			if (!i)
				i--;
			pass[i] = special_array[random % sizeof(special_array)];
		}
	}
	pass[PASSWORD_LENGTH] = '\0';
	printf("The generated password is %s\n", pass);
}
