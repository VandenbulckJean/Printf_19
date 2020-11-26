#include "printf.h"

int processing_d_width_minus_precison(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->amount_precision - ft_strlen(data->string), '0')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_precision(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->amount_precision - ft_strlen(data->string), '0')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
		return (-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_minus(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
		return(-1);
	if (!(data->string = ft_strjoin_back(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_zero(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->width - ft_strlen(data->string), '0')))
		return(-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_width_flag(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (data->precision && data->minus)
		return(processing_d_width_minus_precison(saved_variables, data));
	if (data->precision && !(data->minus))
		return (processing_d_width_precision(saved_variables, data));
	if (data->minus)
		return (processing_d_width_minus(saved_variables, data));
	if (data->zero)
		return (processing_d_width_zero(saved_variables, data));
	else
	{
		if (!(str = create_filled_string(data->width - ft_strlen(data->string), ' ')))
			return(-1);
		if (!(data->string = ft_strjoin_front(data->string, str)))
			return (Memory_allocation_error_free(str));
		free(str);
		return (1);
	}
}

int processing_d_precision_flag(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = create_filled_string(data->amount_precision - ft_strlen(data->string), '0')))
		return(-1);
	if (!(data->string = ft_strjoin_front(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(1);
}

int processing_d_flags(va_list saved_variables, t_fnc_data *data)
{
	int return_value;

	return_value = 1;
	if (data->width)	
		return(processing_d_width_flag(saved_variables, data));
	if (data->precision)
		return(processing_d_precision_flag(saved_variables, data));
	return(return_value);
}

int processing_d(va_list saved_variables, t_fnc_data *data)
{
	char *str;
	int value;

	value = va_arg(saved_variables, int);
	if (data->precision && value == 0)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (-1);
		str[1] = '\0';
	}
	else
	{
		if (!(str = ft_itoa(value, 10, "0123456789")))
			return (-1);
		if (!(data->string = ft_strjoin_back(data->string, str)))
			return (Memory_allocation_error_free(str));
	}
	free(str);	
	return (processing_d_flags(saved_variables, data));
}