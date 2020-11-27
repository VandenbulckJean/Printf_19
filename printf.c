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
		if ((entry[start] >= '1' && entry[start] <= '9') && range)
		{
			while (isnumber(entry[start]) && range)
				{
					data->width = (data->width * 10) + entry[start] - '0';
					start++;
					range--;
				}
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
		return(processing_s(saved_variables, data));
	if (data->conversion == 'p')
		return(processing_p(saved_variables, data));
	if (data->conversion == 'd' || data->conversion == 'i')
		return(processing_d(saved_variables, data));
	if (data->conversion == 'u')
		return(processing_u(saved_variables, data));
	if (data->conversion == 'x')
		return(processing_x(saved_variables, data));
	if (data->conversion == 'X')
		return(processing_X(saved_variables, data));
	if (data->conversion == '%')
		return(processing_percent(saved_variables, data));
	return (-2);
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
			resolve(saved_variables, fnc_data);
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
