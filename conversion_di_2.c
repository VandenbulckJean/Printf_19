/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:26:55 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 12:31:26 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "printf.h"

int processing_d_width_minus_precison(va_list saved_variables, t_fnc_data *data, int negative)
{
	char *str;

	if (!(str = create_filled_string(data->amount_precision - ft_strlen(data->string), '0')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	if (negative)
		if (!(data->string = ft_strjoin_front(data->string, "-")))
			return (-1);
	if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_precision(va_list saved_variables, t_fnc_data *data, int negative)
{
	char *str;

	//printf("1: %s\n", data->string);
	if (!(str = create_filled_string(data->amount_precision - ft_strlen(data->string), '0')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	if (negative)
		if (!(data->string = ft_strjoin_front(data->string, "-")))
			return (-1);
			//printf("2: %s\n", data->string);

	if (data->zero && data->amount_precision < 0)
	{
		if (!(str = create_filled_string(data->width - ft_strlen(data->string), '0')))
			return (-1);
	}
	else
	{
		if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
			return (-1);
	}
	if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_minus(va_list saved_variables, t_fnc_data *data, int negative)
{
	char *str;

	if (negative)
		if (!(data->string = ft_strjoin_front(data->string, "-")))
			return (-1);
	if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
		return(-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_zero(va_list saved_variables, t_fnc_data *data, int negative)
{
	char *str;

	if (!(str = create_filled_string(data->width - ft_strlen(data->string), '0')))
		return(-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	if (negative && data->string[0] == '0')
		data->string[0] = '-';
	if (negative && data->string[0] != '0' && data->string[0] != '-')
		if (!(data->string = ft_strjoin_front(data->string, "-")))
				return (-1);
	return(1);
}

int processing_d_width_flag(va_list saved_variables, t_fnc_data *data, int negative)
{
	char *str;

	if (data->precision && data->minus)
		return(processing_d_width_minus_precison(saved_variables, data, negative));
	if (data->precision && !(data->minus))
		return (processing_d_width_precision(saved_variables, data, negative));
	if (data->minus)
		return (processing_d_width_minus(saved_variables, data, negative));
	if (data->zero)
		return (processing_d_width_zero(saved_variables, data, negative));
	else
	{
		if (negative)
			if (!(data->string = ft_strjoin_front(data->string, "-")))
				return (-1);
		if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
			return(-1);
		if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
		free(str);
		return (1);
	}
}
