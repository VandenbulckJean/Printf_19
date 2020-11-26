#include "printf.h"

char 	*create_filled_string(int length, char filler)
{
	int i;
	char *str;

	i = 0;
	if (length > 0)
	{
		if(!(str = malloc(sizeof(char) * (length + 1))))
				return (NULL);
			while (i < length)
				str[i++] = filler;
			str[length] = '\0';
	}
	else
	{
		if(!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
	}
	return (str);
}

int		Memory_allocation_error_free(void *to_free)
{
	free(to_free);
	return (-1);
}