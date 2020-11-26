# include "printf.h"

t_fnc_data	*mallocandsetzero()
{
	t_fnc_data *data;
	if (!(data = malloc(sizeof(t_fnc_data))))
		return (NULL);
	data->amount_precision = 0;
	data->precision = 0;
	data->minus = 0;
	data->width = 0;
	data->zero = 0;
	data->conversion = 0;
	if (!(data->string = malloc(sizeof(char))))
	{
		free(data);
		return (NULL);
	}
	(data->string)[0] = '\0';
	return (data);
}

void	parsing(va_list saved_variables, t_fnc_data *data, int start, int range, char *entry)
{
	data->conversion = entry[start+range];

	while (range)
	{

		if (entry[start] == '.')
		{
			data->precision = 1;
			start++;
			range--;
			if (entry[start] == '*')
			{
				data->amount_precision = va_arg(saved_variables, int);
				start++;
				range--;
			}
			else
			{
				while (isnumber(entry[start]) && range)
				{
					data->amount_precision = (data->amount_precision * 10) + entry[start] - '0';
					start++;
					range--;
				}
			}
		}
		if (((entry[start] >= '1' && entry[start] <= '9') || (isnumber(entry[start]) && data->width != 0)) && range)
		{
			data->width = (data->width * 10) + entry[start] - '0';
			start++;
			range--;
		}
		if (entry[start] == '-' && range)
		{
			data->minus = 1;
			start++;
			range--;
		}
		if (entry[start] == '0' && range)
		{
			data->zero = 1;
			start++;
			range--;
		}
		if (entry[start] == '*' && range)
		{
			data->width = va_arg(saved_variables, int);
			start++;
			range--;
		}
	}
}



int	resolve(va_list saved_variables, t_fnc_data *data)
{
	char *str;
	if (data->conversion == 'c')
		return (processing_c(saved_variables, data));
	if (data->conversion == 's')
	{
		str = ft_strdup(va_arg(saved_variables, char*));
		data->string = ft_strjoin_back(data->string, str);
		free(str);
	}
	if (data->conversion == 'p')
	{
		str = ft_itoa(va_arg(saved_variables,long long int), 16, "0123456789abcdef");
		data->string = ft_strjoin_back(data->string, "0x");
		data->string = ft_strjoin_back(data->string, str);
		free(str);
	}
	if (data->conversion == 'd' || data->conversion == 'i')
		return(processing_d(saved_variables, data));
	if (data->conversion == 'u')
	{
		str = ft_itoa(va_arg(saved_variables, int), 10, "0123456789");
		data->string = ft_strjoin_back(data->string, str);
		free(str);
	}
	if (data->conversion == 'x')
	{
		str = ft_itoa(va_arg(saved_variables, int), 16, "0123456789abcdef");
		data->string = ft_strjoin_back(data->string, str);
		free(str);
	}
	if (data->conversion == 'X')
	{
		str = ft_itoa(va_arg(saved_variables, int), 16, "0123456789ABCDEF");
		data->string = ft_strjoin_back(data->string, str);
		free(str);
	}
	if (data->conversion == '%')
	{
		data->string = ft_strjoin_back(data->string, "%");
	}
	return (0);
}

/*int resolveflag(t_fnc_data *data)
{
	char *str;
	int i;

	i = 0;
	if (data->width)
	{
		if (data->precision)
	{
		if (data->amount_precision == 0 && (isinstr("diuxX", data->conversion)) && data->string[0] == '0')
		{
			free(data->string);
			if (!(data->string = malloc(sizeof(char))))
				return (-1);
			data->string[0] = '\0';
		}
		if ((data->amount_precision > ft_strlen(data->string)) && (isinstr("diuxX", data->conversion)))
		{
			str = createfilledstr((data->amount_precision - ft_strlen(data->string)), '0');
			str = ft_strjoin_back (str, data->string);
			free(data->string);
			data->string = str;
		}
		if (data->width && data->zero && !(data->minus))
		{
			i = ft_strlen(data->string) - 1 - data->amount_precision;
			while (i >= 0)
				data->string[i--] = ' ';
		} else if (data->width && !(data->zero) && !(data->minus))
		{
			i = ft_strlen(data->string) - data->amount_precision;
			while(data->string[i] && data->string[i] == ' ')
				data->string[i++] = '0';
		}
	}
		if (data->zero)
			str = createfilledstr((data->width - ft_strlen(data->string)), '0');
		else
			str = createfilledstr((data->width - ft_strlen(data->string)), ' ');
		if (data->minus && !(data->zero))
		{
			data->string = ft_strjoin_back(data->string, str);
			free(str);
		}
		else if (data->minus && !(data->zero) && data->precision)
		{
		}
		else
		{
			str = ft_strjoin_back (str, data->string);
			free(data->string);
			data->string = str;
		}
			
	}
	return (0);
}*/
void	error_handler(int error_code)
{
	if (error_code == -1)
		putstr("[Memory allocation error]");
	if (error_code == -10)
		putstr("[Precision flag used with ‘c’ has undefined behavior]");
	if (error_code == -11)
		putstr("[Zero flag used with ‘c’ has undefined behavior]");
}

int	entry_processing(va_list saved_variables,char *entry, t_fnc_data *fnc_data)
{
	int i;
	int start;

	i = 0;
	while (entry[i])
	{
		while (entry[i] && entry[i] != '%')
			write(1, &entry[i++], 1);
		if (entry[i] && entry[i] == '%')
		{
			start = ++i;
			fnc_data = mallocandsetzero();
			while (!(isinstr("cspdiuxX%", entry[i])) && entry[i])
			{
				if (!(isinstr("-.*0123456789", entry[i++])))
					return (0);
			}
			parsing(saved_variables, fnc_data, start, i++ - start, entry);
			error_handler(resolve(saved_variables, fnc_data));
			putstr(fnc_data->string);
			free(fnc_data);
		}
	}
	return (1);
}

int		ft_printf(const char *entry, ...)
{
	va_list		saved_variables;
	t_fnc_data *fnc_data;

	va_start(saved_variables,  entry);
	entry_processing(saved_variables, (char *)entry, fnc_data);
	va_end(saved_variables);
	return (1);
}
