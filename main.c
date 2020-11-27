#include "printf.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int number = -14;
	char character = 'f';
	char *word = "coucou toi !";
	char **coucou = &word;
	unsigned int tttt = 123;
	char newline = '\n';


	printf("%-5c|\n", '\0');
	ft_printf("%-5c|", '\0');

}