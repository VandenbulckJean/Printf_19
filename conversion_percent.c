#include "printf.h"

int processing_percent_width_minus_flag(va_list saved_variables, t_fnc_data *data)
{
	char *str;
	if (!(str = create_filled_string(data->width - 1, ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_percent_width_zero_flag(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - 1, '0')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_percent_width_flag(va_list width, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - 1, ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_percent_flags(va_list saved_variables, t_fnc_data *data)
{
	if (data->width)
	{
		if (data->minus)
		{
			return(processing_percent_width_minus_flag(saved_variables, data));
		}
		else if (data->zero)
		{
			return(processing_percent_width_zero_flag(saved_variables, data));
		}
		else
		{
			return(processing_percent_width_flag(saved_variables, data));
		}
	}
	return (1);
}

int processing_percent(va_list saved_variables, t_fnc_data *data)
{
	if (!(data->string = ft_strjoin_back(data->string, "%")))
		return(-1);
	return (processing_percent_flags(saved_variables, data));
}
