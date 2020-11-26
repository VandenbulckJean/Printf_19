#include "printf.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int number = 534;
	char character = 'f';
	char *word = "coucou toi !";
	char **coucou = &word;
	unsigned int tttt = 123;
	char newline = '\n';


	printf("hey %0d|\n", number);
	ft_printf("hey %0d|", number);
}