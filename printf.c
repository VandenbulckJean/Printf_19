/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:58 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 13:12:24 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

static t_fnc_data	*mallocandsetzero()
{
	t_fnc_data	*data;
	
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

static void			write_count_free(t_fnc_data *data, int *writtenchar)
{
	putstr(data->string);
	*writtenchar = *writtenchar + ft_strlen(data->string);
	free_data(data);
}

static void			write_count(char c, int *writtenchar)
{
	write(1, &c, 1);
	(*writtenchar)++;
}

static int			entry_processing(va_list sv, char *entry, t_fnc_data *data)
{
	int i;
	int start;
	int return_value;
	int writtenchar;

	i = 0;
	writtenchar = 0;
	while (entry[i])
	{
		while (entry[i] && entry[i] != '%')
			write_count(entry[i++], &writtenchar);
		if (entry[i] && entry[i] == '%')
		{
			start = ++i;
			if (!(data = mallocandsetzero()))
				return (-1);
			while (!(isinstr("cspdiuxX%", entry[i])) && entry[i])
				if (!(isinstr("-.*0123456789", entry[i++])))
					return (0);
			if ((return_value = parsing(sv, data, start, i++ - start, entry)) == -1)
				return (return_value);
			write_count_free(data, &writtenchar);
		}
	}
	return (writtenchar);
}

int					ft_printf(const char *entry, ...)
{
	va_list		saved_variables;
	t_fnc_data	*fnc_data;
	int			return_value;

	va_start(saved_variables, entry);
	return_value = entry_processing(saved_variables, (char *)entry, fnc_data);
	va_end(saved_variables);
	return (return_value);
}
