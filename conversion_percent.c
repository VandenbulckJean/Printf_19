/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:06 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 14:39:12 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			processing_percent_width_minus_flag(t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - 1, ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return (1);
}

int			processing_percent_width_zero_flag(t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - 1, '0')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return (1);
}

int			processing_percent_width_flag(t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - 1, ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return (1);
}

int			processing_percent_flags(t_fnc_data *data)
{
	if (data->width)
	{
		if (data->minus)
		{
			return (processing_percent_width_minus_flag(data));
		}
		else if (data->zero)
		{
			return (processing_percent_width_zero_flag(data));
		}
		else
		{
			return (processing_percent_width_flag(data));
		}
	}
	return (1);
}

int			processing_percent(t_fnc_data *data)
{
	if (!(data->string = ft_strjoin_back(data->string, "%")))
		return (-1);
	return (processing_percent_flags(data));
}
