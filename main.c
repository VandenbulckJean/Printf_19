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


	printf("%-99.64u%0013.152i%--38c%082.*d%-160c]\n" ,623103255u,-544485744,0,-70,-749238306,-46);
	ft_printf("%-99.64u%0013.152i%--38c%082.*d%-160c]" ,623103255u,-544485744,0,-70,-749238306,-46);

}