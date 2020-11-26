# include "printf.h"

char		*getnumberintostr(int i, int neg, unsigned long long int nb, int base, char *basestr)
{
	char			*str;

	if (neg == 1)
		i++;
	if (!(str = malloc(sizeof(char) * i + 2)))
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[i + 1] = '\0';
	while (nb > 0)
	{
		str[i] = basestr[(nb % base)];
		nb = nb / base;
		i--;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int long long n, int base, char *basestr)
{
	int						i;
	int						neg;
	unsigned long long int	nb;

	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		nb = n * -1;
	}
	else
		nb = n;
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (getnumberintostr(i, neg, nb, base, basestr));
}