# include "printf.h"

int processing_c_precison_flag(void)
{
	return(-10);
}

int processing_c_zero_flag(void)
{
	return(-11);
}

int processing_c_width_minus_flag(t_fnc_data *data)
{
	char *str;
	if (!(str = create_filled_string(data->width - 1, ' ')))
		return(-1);
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

int processing_c_flags(va_list saved_variables, t_fnc_data *data)
{
	int return_value;

	return_value = 1;
	if (data->precision)
		return_value = processing_c_precison_flag();
	if (data->zero)
		return_value = processing_c_zero_flag();
	if (data->width)
		return_value = processing_c_width_minus_flag(data);
	return (return_value);
}

int processing_c(va_list saved_variables, t_fnc_data *data)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
			return (-1);
	str[0] = va_arg(saved_variables, int);
	str[1] = '\0';
	if (!(data->string = ft_strjoin_back(data->string, str)))
		return (Memory_allocation_error_free(str));
	free(str);
	return(processing_c_flags(saved_variables, data));
}