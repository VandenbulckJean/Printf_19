# include "printf.h"

int		isinstr(char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}