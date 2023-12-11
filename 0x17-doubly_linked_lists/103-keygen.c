#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char password[7], *code;
	int len = strlen(argv[1]), a, t;

	code = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	t = (len ^ 59) & 63;
	password[0] = codex[t];

	t = 0;
	for (a = 0; a < len; a++)
		t += argv[1][a];
	password[1] = code[(t ^ 79) & 63];

	t = 1;
	for (a = 0; a < len; a++)
		t *= argv[1][a];
	password[2] = code[(t ^ 85) & 63];

	t = 0;
	for (a = 0; a < len; a++)
	{
		if (argv[1][a] > t)
			t = argv[1][a];
	}
	srand(t ^ 14);
	password[3] = code[rand() & 63];

	t = 0;
	for (a = 0; a < len; a++)
		t += (argv[1][a] * argv[1][a]);
	password[4] = code[(t ^ 239) & 63];

	for (a = 0; a < argv[1][0]; a++)
		t = rand();
	password[5] = code[(t ^ 229) & 63];

	password[6] = '\0';
	printf("%s", password);
	return (0);
}
