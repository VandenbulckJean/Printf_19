/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:20:59 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 13:25:01 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			processing_p_zero_flag(void)
{
	return (-13);
}

int			processing_p_precision_flg(void)
{
	return (-14);
}

int			processing_p_width_minus_flag(va_list saved_variables, t_fnc_data *data)
{
	char *str;
	
	if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
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

int			processing_p_flags(va_list saved_variables, t_fnc_data *data)
{
	if (data->precision && data->amount_precision != 0)
		return (processing_p_precision_flg());
	if (data->zero)
		return (processing_p_zero_flag());
	if (data->width)
		return (processing_p_width_minus_flag(saved_variables, data));
	return (1);
}

int			processing_p(va_list saved_variables, t_fnc_data *data)
{
	char					*str;
	unsigned long long int	value;

	value = va_arg(saved_variables, unsigned long long int);
	if (!(data->string = ft_strjoin_back(data->string, "0x")))
		return (-1);
	if (!(data->precision && value == 0))
	{
		if (!(str = ft_itoa_pointer(value, 16, "0123456789abcdef")))
			return (-1);
		if (!(data->string = ft_strjoin_back(data->string, str)))
			return (Memory_allocation_error_free(str));
		free(str);
	}
	return (processing_p_flags(saved_variables, data));
}
