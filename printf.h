/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:22:03 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 12:28:58 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fnc_data	{
	int minus;
	int zero;
	int	precision;
	int amount_precision;
	int width;
	char *string;
	char conversion;
}				t_fnc_data;

int		ft_printf(const char *, ...);
void	putstr(char *str);
int		ft_strlen(char *str);
char	*getnumberintostr(int i, int neg, unsigned long long int nb, int base, char *basestr);
char	*ft_itoa(int long long n, int base, char *basestr);
char	*ft_strjoin_back(char *s1, char *s2);
char	*ft_strjoin_front(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		isnumber(char c);
int		isinstr(char *str, char c);
int		Memory_allocation_error_free(void *to_free);
int processing_c(va_list saved_variables, t_fnc_data *data);
char 	*create_filled_string(int length, char filler);
int processing_d(va_list saved_variables, t_fnc_data *data);
int processing_d_flags(va_list saved_variables, t_fnc_data *data, int negative);
int processing_s(va_list saved_variables, t_fnc_data *data);
char *truncstr(char *oldstr, int range);
int processing_p(va_list saved_variables, t_fnc_data *data);
int processing_u(va_list saved_variables, t_fnc_data *data);
int	processing_x(va_list saved_variables, t_fnc_data *data);
int	processing_X(va_list saved_variables, t_fnc_data *data);
int processing_percent(va_list saved_variables, t_fnc_data *data);
void free_data(t_fnc_data *data);
int	parsing(va_list saved_variables, t_fnc_data *data, int start, int range, char *entry);
char			*ft_itoa_pointer(unsigned long long int n, int base, char *basestr);
int processing_d_width_flag(va_list saved_variables, t_fnc_data *data, int negative);
int processing_d_width_zero(va_list saved_variables, t_fnc_data *data, int negative);
int processing_d_width_minus(va_list saved_variables, t_fnc_data *data, int negative);
int processing_d_width_precision(va_list saved_variables, t_fnc_data *data, int negative);
int processing_d_width_minus_precison(va_list saved_variables, t_fnc_data *data, int negative);




#endif