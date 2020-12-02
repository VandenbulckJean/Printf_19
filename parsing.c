/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:27 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 13:58:01 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

void	get_precision(va_list saved_variables, t_fnc_data *data, int *start, int *range, char *entry)
{
	data->precision = 1;
	(*start)++;
	(*range)--;
	if (entry[*start] == '*')
	{
		data->amount_precision = va_arg(saved_variables, int);
		(*start)++;
		(*range)--;
	}
	else
	{
		while (isnumber(entry[*start]) && *range)
		{
			data->amount_precision = (data->amount_precision * 10) + entry[*start] - '0';
			(*start)++;
			(*range)--;
		}
	}
	if (data->amount_precision < 0)
		data->precision = 0;
}

void	get_width(va_list saved_variables, t_fnc_data *data, int *start, int *range, char *entry)
{
	while (isnumber(entry[*start]) && *range)
	{
		data->width = (data->width * 10) + entry[*start] - '0';
		(*start)++;
		(*range)--;
	}
}

void	get_width_star(va_list saved_variables, t_fnc_data *data, int *start, int *range, char *entry)
{
	int star_value;

	star_value = va_arg(saved_variables, int);
	if (star_value < 0)
	{
		data->minus = 1;
		star_value = -star_value;
	}
	data->width = star_value;
	(*start)++;
	(*range)--;
}

int		resolve(va_list saved_variables, t_fnc_data *data)
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

int		parsing(va_list saved_variables, t_fnc_data *data, int start, int range, char *entry)
{
	data->conversion = entry[start+range];
	while (range)
	{
		if (entry[start] == '.')
			get_precision(saved_variables, data, &start, &range, entry);
		if ((entry[start] >= '1' && entry[start] <= '9') && range)
			get_width(saved_variables, data, &start, &range, entry);
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
			get_width_star(saved_variables, data, &start, &range, entry);
	}
	return (resolve(saved_variables, data));
}
