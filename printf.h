/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:22:03 by jvanden-          #+#    #+#             */
/*   Updated: 2020/12/02 15:12:41 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fnc_data	{
	va_list	saved_variables;
	int		minus;
	int		zero;
	int		precision;
	int		amount_precision;
	int		width;
	char	*string;
	char	conversion;
}				t_fnc_data;

int		ft_printf(const char *entry, ...);
void	putstr(char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int long long n, int base, char *basestr);
char	*ft_strjoin_back(char *s1, char *s2);
char	*ft_strjoin_front(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		isnumber(char c);
int		isinstr(char *str, char c);
int		memory_allocation_error_free(void *to_free);
int		processing_c(t_fnc_data *data);
char	*create_filled_string(int length, char filler);
int		processing_d(t_fnc_data *data);
int		processing_d_flags(t_fnc_data *data, int negative);
int		processing_s(t_fnc_data *data);
char	*truncstr(char *oldstr, int range);
int		processing_p(t_fnc_data *data);
int		processing_u(t_fnc_data *data);
int		processing_x(t_fnc_data *data);
int		processing_cap_x(t_fnc_data *data);
int		processing_percent(t_fnc_data *data);
void	free_data(t_fnc_data *data);
int		parsing(t_fnc_data *data, int start, int range, char *entry);
char	*ft_itoa_pointer(unsigned long long int n, int base, char *basestr);
int		processing_d_width_flag(t_fnc_data *data, int negative);
int		processing_d_width_zero(t_fnc_data *data, int negative);
int		processing_d_width_minus(t_fnc_data *data, int negative);
int		processing_d_width_precision(t_fnc_data *data, int negative);
int		processing_d_width_minus_precison(t_fnc_data *data, int negative);
int		free_string_return(t_fnc_data *data, int i);

#endif
