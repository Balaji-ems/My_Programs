#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 18

static char num_array[]     = "0123456789";
static char small_array[]   = "abcdefghijklmnopqrstuvwxyz";
static char caps_array[]    = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char special_array[] = "!@$%&";

char *pwd_gen(char *pass)
{
	int random, select;

        srand(time(NULL));
        for (int i = 0; i < PASSWORD_LENGTH; i++) {
                random = rand();
                select =  random % 4;

                if (!select) {
                        *(pass + i) = num_array[random % sizeof(num_array)];
                } else if (select == 1) {
                        *(pass + i) = small_array[random % sizeof(small_array)];
                } else if (select == 2) {
                        *(pass + i) = caps_array[random % sizeof(caps_array)];
                } else if (select == 3) {
                        if (!i)
                                i--;
                        *(pass + i) = special_array[random % sizeof(special_array)];
                }
                if (!*(pass +i))
                        i--;
        }
        pass[PASSWORD_LENGTH] = '\0';

	return pass;
}


int main(void)
{
	char pass[PASSWORD_LENGTH + 1];
	char *pwd = pass;

	pwd = pwd_gen(pass);

	printf("The generated password is %s\n", pass);
}
