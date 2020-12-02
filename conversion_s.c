/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:14 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 13:04:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			processing_s_zero_flag(void)
{
	return (-12);
}

int			processing_s_precision_flag(va_list saved_variables, t_fnc_data *data)
{
	if (data->amount_precision <
	ft_strlen(data->string) && data->amount_precision >= 0)
		if (!(data->string = truncstr(data->string, data->amount_precision)))
			return (-1);
	return (1);
}

int			processing_s_width_minus_flag(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width -
	ft_strlen(data->string), ' ')))
		return (-1);
	if (data->minus)
	{
		if (!(data->string = ft_strjoin_back(data->string, str)))
			return (Memory_allocation_error_free(str));
	}
	else
	{
		if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	}
	return (1);
}

int			processing_s_flags(va_list saved_variables, t_fnc_data *data)
{
	if (data->zero)
		return (processing_s_zero_flag());
	if (data->precision)
		if (processing_s_precision_flag(saved_variables, data) == -1)
			return (-1);
	if (data->width)
		return (processing_s_width_minus_flag(saved_variables, data));
	return (1);
}

int			processing_s(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = ft_strdup(va_arg(saved_variables, char*))))
		return (-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return (processing_s_flags(saved_variables, data));
}
